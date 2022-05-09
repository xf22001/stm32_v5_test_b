

/*================================================================
 *   
 *   
 *   文件名称：test_uart_b.h
 *   创 建 者：肖飞
 *   创建日期：2022年05月07日 星期六 10时10分11秒
 *   修改日期：2022年05月09日 星期一 10时52分27秒
 *   描    述：
 *
 *================================================================*/
#ifndef _TEST_UART_B_H
#define _TEST_UART_B_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "app_platform.h"
#include "cmsis_os.h"

#include "os_utils.h"
#include "callback_chain.h"
#include "channels.h"

typedef struct {
	uint8_t id;
	uint32_t v1;
	uint32_t v2;
	uint32_t alive_stamps;
	uint8_t tx_data[64];
	uint16_t tx_size;
	uint8_t rx_data[64];
	uint16_t rx_size;
	callback_item_t data_request_cb;
	callback_item_t data_response_cb;
} uart_test_ctx_t;

uart_test_ctx_t *test_uart_b(channels_info_t *channels_info, void *huart, uint8_t id);

#ifdef __cplusplus
}
#endif
#endif //_TEST_UART_B_H
