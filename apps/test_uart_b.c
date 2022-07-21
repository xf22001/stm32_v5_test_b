

/*================================================================
 *
 *
 *   文件名称：test_uart_b.c
 *   创 建 者：肖飞
 *   创建日期：2022年05月07日 星期六 09时35分03秒
 *   修改日期：2022年07月20日 星期三 15时04分37秒
 *   描    述：
 *
 *================================================================*/
#include "test_uart_b.h"

#include "uart_data_task.h"

#define LOG_DISABLE
#include "log.h"

typedef struct {
	int id;
	uint32_t v;
} uart_test_tx_data_t;

typedef struct {
	int id;
	uint32_t v1;
	uint32_t v2;
} uart_test_rx_data_t;

static void uart_data_request(void *fn_ctx, void *chain_ctx)
{
	uart_test_ctx_t *ctx = (uart_test_ctx_t *)fn_ctx;
	uart_data_task_info_t *uart_data_task_info = (uart_data_task_info_t *)chain_ctx;
	uint16_t rx_size;

	ctx->tx_size = sizeof(uart_test_tx_data_t);
	ctx->rx_size = sizeof(uart_test_rx_data_t);

	rx_size = uart_rx_data(uart_data_task_info->uart_info, ctx->rx_data, ctx->rx_size, 1000);

	if(rx_size == ctx->rx_size) {
		uart_test_rx_data_t *uart_test_rx_data = (uart_test_rx_data_t *)ctx->rx_data;
		uart_test_tx_data_t *uart_test_tx_data = (uart_test_tx_data_t *)ctx->tx_data;
		uint16_t tx_size;

		uart_test_tx_data->id = uart_test_rx_data->id;
		uart_test_tx_data->v = uart_test_rx_data->v1 + uart_test_rx_data->v2;

		tx_size = uart_tx_data(uart_data_task_info->uart_info, ctx->tx_data, ctx->tx_size, 1000);

		if(tx_size != ctx->tx_size) {
			debug("uart %d tx_size:%d, ctx->tx_size:%d", ctx->id, tx_size, ctx->tx_size);
		}
	} else {
		debug("uart %d rx_size:%d, ctx->rx_size:%d", ctx->id, rx_size, ctx->rx_size);
	}
}

uart_test_ctx_t *test_uart_b(channels_info_t *channels_info, void *huart, uint8_t id)
{
	uart_test_ctx_t *ctx = os_calloc(1, sizeof(uart_test_ctx_t));
	uart_data_task_info_t *uart_data_task_info = get_or_alloc_uart_data_task_info(huart);

	OS_ASSERT(ctx != 0);
	OS_ASSERT(uart_data_task_info != 0);

	set_uart_data_task_request_delay(uart_data_task_info, 200);
	uart_info_signal(uart_data_task_info->uart_info);

	ctx->id = id;

	ctx->data_request_cb.fn = uart_data_request;
	ctx->data_request_cb.fn_ctx = ctx;
	OS_ASSERT(add_uart_data_task_info_cb(uart_data_task_info, &ctx->data_request_cb) == 0);
	set_uart_data_task_request_delay(uart_data_task_info, 0);

	return ctx;
}
