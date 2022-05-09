

/*================================================================
 *   
 *   
 *   文件名称：test_can_b.c
 *   创 建 者：肖飞
 *   创建日期：2022年05月09日 星期一 10时42分03秒
 *   修改日期：2022年05月09日 星期一 10时42分34秒
 *   描    述：
 *
 *================================================================*/
#include "test_can_b.h"

#include <stdlib.h>

#include "can_data_task.h"
#include "can.h"

#include "log.h"

static int can_send_data(can_test_ctx_t *ctx, can_info_t *can_info)
{
	int ret = 0;
	can_tx_msg_t tx_msg;
	uint32_t *send = (uint32_t *)tx_msg.Data;

	tx_msg.ExtId = ctx->extid;//扩展ID 初始化
	tx_msg.IDE = CAN_ID_EXT;//ID类型 为扩展ID
	tx_msg.RTR = CAN_RTR_DATA;//
	tx_msg.DLC = sizeof(*send);//数据长度

	*send = ctx->recv.s.u32_0 + ctx->recv.s.u32_1;

	ret = can_tx_data(can_info, &tx_msg, 10);

	return ret;
}

static void can_data_request(void *fn_ctx, void *chain_ctx)
{
	can_test_ctx_t *ctx = (can_test_ctx_t *)fn_ctx;
	can_data_task_info_t *can_data_task_info = (can_data_task_info_t *)chain_ctx;
	uint32_t ticks = osKernelSysTick();
	int ret;

	if(ticks_duration(ticks, ctx->stamp) < 10) {
		return;
	}

	ctx->stamp = ticks;

	if(ctx->state != COMMAND_STATE_REQUEST) {
		return;
	}

	ret = can_send_data(ctx, can_data_task_info->can_info);

	if(ret == 0) {
		ctx->state = COMMAND_STATE_IDLE;
	} else {
		debug("can %d tx error!", ctx->id);
	}
}

static void can_data_response(void *fn_ctx, void *chain_ctx)
{
	can_test_ctx_t *ctx = (can_test_ctx_t *)fn_ctx;
	can_data_task_info_t *can_data_task_info = (can_data_task_info_t *)chain_ctx;
	can_rx_msg_t *can_rx_msg = can_get_msg(can_data_task_info->can_info);
	u_u64_u32_t *recv = (u_u64_u32_t *)can_rx_msg->Data;

	ctx->recv.v = recv->v;
	ctx->state = COMMAND_STATE_REQUEST;
}

can_test_ctx_t *test_can_b(channels_info_t *channels_info, void *hcan, uint8_t id)
{
	can_test_ctx_t *ctx = os_calloc(1, sizeof(can_test_ctx_t));
	can_data_task_info_t *can_data_task_info = get_or_alloc_can_data_task_info(hcan);

	OS_ASSERT(ctx != 0);
	OS_ASSERT(can_data_task_info != 0);

	ctx->id = id;
	ctx->extid = 0x12345600 + id;

	ctx->data_request_cb.fn = can_data_request;
	ctx->data_request_cb.fn_ctx = ctx;
	OS_ASSERT(add_can_data_task_info_request_cb(can_data_task_info, &ctx->data_request_cb) == 0);

	ctx->data_response_cb.fn = can_data_response;
	ctx->data_response_cb.fn_ctx = ctx;
	OS_ASSERT(add_can_data_task_info_response_cb(can_data_task_info, &ctx->data_response_cb) == 0);

	return ctx;
}
