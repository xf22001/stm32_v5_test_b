

/*================================================================
 *
 *
 *   文件名称：channels_addr_handler.c
 *   创 建 者：肖飞
 *   创建日期：2021年07月16日 星期五 14时03分28秒
 *   修改日期：2022年05月09日 星期一 11时00分26秒
 *   描    述：
 *
 *================================================================*/
#include "modbus_data_value.h"
#include "app.h"
#include "channels.h"
#include "display.h"

#include "log.h"

void channels_modbus_data_action(void *fn_ctx, void *chain_ctx)
{
	channels_info_t *channels_info = (channels_info_t *)fn_ctx;
	modbus_data_ctx_t *modbus_data_ctx = (modbus_data_ctx_t *)chain_ctx;

	//debug("op:%s, addr:%d",
	//      (modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) ? "get" :
	//      (modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) ? "set" :
	//      "unknow",
	//      modbus_data_ctx->addr);

	switch(modbus_data_ctx->addr) {
		case 0: {
		}
		break;

		default:
			debug("error! op:%s, addr:%d",
			      (modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) ? "get" :
			      (modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) ? "set" :
			      "unknow",
			      modbus_data_ctx->addr);
			break;
	}
}
