

/*================================================================
 *
 *
 *   文件名称：test_can_b.c
 *   创 建 者：肖飞
 *   创建日期：2022年05月06日 星期五 15时24分38秒
 *   修改日期：2022年05月06日 星期五 16时55分05秒
 *   描    述：
 *
 *================================================================*/
#include "test_can_b.h"

#include <stdlib.h>

#include "os_utils.h"
#include "can_data_task.h"
#include "can.h"
#include "command_status.h"

#include "log.h"

typedef struct {
	uint8_t id;
	uint32_t extid;
	u_u64_u32_t send;
	uint32_t stamp;
	uint32_t send_stamp;
	command_state_t state;
	callback_item_t data_request_cb;
	callback_item_t data_response_cb;
	channels_info_t *channel_info;
} can_test_ctx_t;

static int can_send_data(can_test_ctx_t *ctx, can_info_t *can_info)
{
	int ret = 0;
	can_tx_msg_t tx_msg;
	u_u64_u32_t *send = (u_u64_u32_t *)tx_msg.Data;

	tx_msg.ExtId = ctx->extid;//扩展ID 初始化
	tx_msg.IDE = CAN_ID_EXT;//ID类型 为扩展ID
	tx_msg.RTR = CAN_RTR_DATA;//
	tx_msg.DLC = sizeof(ctx->send.v);//数据长度

	send->v = ctx->send.v;

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

	if(ctx->state == COMMAND_STATE_RESPONSE) {
		if(ticks_duration(ticks, ctx->send_stamp) >= 100) {
			debug("can %d rx timeout!", ctx->id);
		}
	}

	if(ticks_duration(ticks, ctx->send_stamp) < 200) {
		return;
	}

	ctx->send.s.u32_0 = os_rand();
	ctx->send.s.u32_1 = os_rand();

	ret = can_send_data(ctx, can_data_task_info->can_info);

	if(ret == 0) {
		ctx->state = COMMAND_STATE_RESPONSE;
		ctx->send_stamp = ticks;
	} else {
		debug("can %d tx error!", ctx->id);
	}
}

static void can_data_response(void *fn_ctx, void *chain_ctx)
{
	can_test_ctx_t *ctx = (can_test_ctx_t *)fn_ctx;
	can_data_task_info_t *can_data_task_info = (can_data_task_info_t *)chain_ctx;
	can_rx_msg_t *can_rx_msg = can_get_msg(can_data_task_info->can_info);
	uint32_t *recv = (uint32_t *)can_rx_msg->Data;
	uint32_t send = ctx->send.s.u32_0 + ctx->send.s.u32_1;

	if(can_rx_msg->ExtId == ctx->extid) {
		if(send == *recv) {
			ctx->state = COMMAND_STATE_IDLE;
		} else {
			debug("can %d rx error! send:%08x, recv:%08x", ctx->id, send, *recv);
		}
	} else {
		debug("can %d extid:%08x, response extid:%08x!", ctx->id, ctx->extid, can_rx_msg->ExtId);
		debug("can %d rx error!", ctx->id);
	}
}

void test_can_b(channels_info_t *channel_info, void *hcan, uint8_t id)
{
	can_test_ctx_t *ctx = os_calloc(1, sizeof(can_test_ctx_t));
	can_data_task_info_t *can_data_task_info = get_or_alloc_can_data_task_info(hcan);

	OS_ASSERT(ctx != 0);
	OS_ASSERT(can_data_task_info != 0);

	ctx->id = id;
	ctx->extid = 0x12345600 + id;

	ctx->data_request_cb.fn = can_data_request;
	ctx->data_request_cb.fn_ctx = ctx;
	add_can_data_task_info_request_cb(can_data_task_info, &ctx->data_request_cb);

	ctx->data_response_cb.fn = can_data_response;
	ctx->data_response_cb.fn_ctx = ctx;
	add_can_data_task_info_response_cb(can_data_task_info, &ctx->data_response_cb);
}
