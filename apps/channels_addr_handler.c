

/*================================================================
 *
 *
 *   文件名称：channels_addr_handler.c
 *   创 建 者：肖飞
 *   创建日期：2021年07月16日 星期五 14时03分28秒
 *   修改日期：2022年06月01日 星期三 17时21分19秒
 *   描    述：
 *
 *================================================================*/
#include "modbus_data_value.h"
#include "app.h"
#include "channels.h"
#include "display.h"
#include "test_type.h"
#include "main.h"

#include "log.h"

void channels_modbus_data_action(void *fn_ctx, void *chain_ctx)
{
	//channels_info_t *channels_info = (channels_info_t *)fn_ctx;
	modbus_data_ctx_t *modbus_data_ctx = (modbus_data_ctx_t *)chain_ctx;

	//debug("op:%s, addr:%d",
	//      (modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) ? "get" :
	//      (modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) ? "set" :
	//      "unknow",
	//      modbus_data_ctx->addr);

	switch(modbus_data_ctx->addr) {
		case TEST_TYPE_PORTS_NONE: {
		}
		break;

		case TEST_TYPE_PORTS_CONTACTOR_DRV: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out1_GPIO_Port, out1_Pin);
		}
		break;

		case TEST_TYPE_PORTS_FAN1_RLY_DRV: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out1_GPIO_Port, out1_Pin);
		}
		break;

		case TEST_TYPE_PORTS_VTRANS_1_12V_24: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out2_GPIO_Port, out2_Pin);
		}
		break;

		case TEST_TYPE_PORTS_VTRANS_2_12V_24: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out2_GPIO_Port, out2_Pin);
		}
		break;

		case TEST_TYPE_PORTS_BMSPOWER_PLUG1: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out3_GPIO_Port, out3_Pin);
		}
		break;

		case TEST_TYPE_PORTS_BMSPOWER_PLUG2: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out3_GPIO_Port, out3_Pin);
		}
		break;

		case TEST_TYPE_PORTS_LED_YELLOW_PLUG1: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
		}
		break;

		case TEST_TYPE_PORTS_LED_YELLOW_PLUG2: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
		}
		break;

		case TEST_TYPE_PORTS_LED_RED_PLUG1: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
		}
		break;

		case TEST_TYPE_PORTS_LED_RED_PLUG2: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
		}
		break;

		case TEST_TYPE_PORTS_LED_GREEN_POWER1: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
		}
		break;

		case TEST_TYPE_PORTS_LED_GREEN_POWER2: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_SCLK2: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out10_GPIO_Port, out10_Pin);
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_LCLK2: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out10_GPIO_Port, out10_Pin);
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_DS2: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out10_GPIO_Port, out10_Pin);
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_SCLK1: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out11_GPIO_Port, out11_Pin);
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_LCLK1: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out11_GPIO_Port, out11_Pin);
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_DS1: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out11_GPIO_Port, out11_Pin);
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_RX1: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out12_GPIO_Port, out12_Pin);
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_RX2: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out12_GPIO_Port, out12_Pin);
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_RX3: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out12_GPIO_Port, out12_Pin);
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_TX1: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out12_GPIO_Port, out12_Pin);
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_TX2: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out12_GPIO_Port, out12_Pin);
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_TX3: {
			modbus_data_ctx->value = HAL_GPIO_ReadPin(out12_GPIO_Port, out12_Pin);
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
