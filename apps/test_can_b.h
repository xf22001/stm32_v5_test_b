

/*================================================================
 *   
 *   
 *   文件名称：test_can_b.h
 *   创 建 者：肖飞
 *   创建日期：2022年05月09日 星期一 10时42分52秒
 *   修改日期：2022年05月09日 星期一 10时43分20秒
 *   描    述：
 *
 *================================================================*/
#ifndef _TEST_CAN_B_H
#define _TEST_CAN_B_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "app_platform.h"
#include "cmsis_os.h"

#include "os_utils.h"
#include "command_status.h"
#include "callback_chain.h"
#include "channels.h"

typedef struct {
	uint8_t id;
	uint32_t extid;
	u_u64_u32_t recv;
	uint32_t stamp;
	command_state_t state;
	callback_item_t data_request_cb;
	callback_item_t data_response_cb;
} can_test_ctx_t;

can_test_ctx_t *test_can_b(channels_info_t *channels_info, void *hcan, uint8_t id);

#ifdef __cplusplus
}
#endif
#endif //_TEST_CAN_B_H
