

/*================================================================
 *
 *
 *   文件名称：channels_addr_handler.c
 *   创 建 者：肖飞
 *   创建日期：2021年07月16日 星期五 14时03分28秒
 *   修改日期：2022年07月05日 星期二 14时39分30秒
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
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out1_GPIO_Port, out1_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_FAN1_RLY_DRV: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out1_GPIO_Port, out1_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_VTRANS_1_12V_24: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out2_GPIO_Port, out2_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_VTRANS_2_12V_24: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out2_GPIO_Port, out2_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_BMSPOWER_PLUG1: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out3_GPIO_Port, out3_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_BMSPOWER_PLUG2: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out3_GPIO_Port, out3_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_LED_YELLOW_PLUG1: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_LED_YELLOW_PLUG2: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_LED_RED_PLUG1: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_LED_RED_PLUG2: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_LED_GREEN_POWER1: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_LED_GREEN_POWER2: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out9_GPIO_Port, out9_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_SCLK2: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out10_GPIO_Port, out10_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_LCLK2: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out10_GPIO_Port, out10_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_DS2: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out10_GPIO_Port, out10_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_SCLK1: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out11_GPIO_Port, out11_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_LCLK1: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out11_GPIO_Port, out11_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_CHARGING_LED_DS1: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out11_GPIO_Port, out11_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_TX1: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out12_GPIO_Port, out12_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_TX2: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out12_GPIO_Port, out12_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_TX3: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(out12_GPIO_Port, out12_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_PLUG1_LOCK_1: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(lock1_C3_GPIO_Port, lock1_C3_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_PLUG1_LOCK_2: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(lock1__GPIO_Port, lock1__Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_PLUG2_LOCK_1: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(lock2_C1_GPIO_Port, lock2_C1_Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_PLUG2_LOCK_2: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_GET) {
				modbus_data_ctx->value = HAL_GPIO_ReadPin(lock2__GPIO_Port, lock2__Pin);
			}
		}
		break;

		case TEST_TYPE_PORTS_DOOR1_OPEN: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey1_GPIO_Port, rey1_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_EPO: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey2_GPIO_Port, rey2_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_FUSE1_OPEN: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey3_GPIO_Port, rey3_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_FUSE2_OPEN: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey4_GPIO_Port, rey4_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_MAIN_RLY_PLUG1_BACK: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey5_GPIO_Port, rey5_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_MAIN_RLY_PLUG2_BACK: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey6_GPIO_Port, rey6_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_BRG_RLY_DRV_BACK: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey7_GPIO_Port, rey7_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_POWERDISTRIBUTION_1_BACK: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey8_GPIO_Port, rey8_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_POWERDISTRIBUTION_2_BACK: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey9_GPIO_Port, rey9_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_POWERDISTRIBUTION_3_BACK: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey10_GPIO_Port, rey10_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_POWERDISTRIBUTION_4_BACK: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey11_GPIO_Port, rey11_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_POWERDISTRIBUTION_5_BACK: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey12_GPIO_Port, rey12_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_FAN1_FAULT: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey13_GPIO_Port, rey13_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_FAN2_FAULT: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey14_GPIO_Port, rey14_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_FAN3_FAULT: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey15_GPIO_Port, rey15_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_FAN4_FAULT: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey16_GPIO_Port, rey16_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_FAN5_FAULT: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey17_GPIO_Port, rey17_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_RX1: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey18_GPIO_Port, rey18_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_RX2: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey19_GPIO_Port, rey19_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_PAR_EXT_RX3: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey20_GPIO_Port, rey20_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_PLUG1_LOCK_BACK: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey21_GPIO_Port, rey21_Pin, modbus_data_ctx->value);
			}
		}
		break;

		case TEST_TYPE_PORTS_PLUG2_LOCK_BACK: {
			if(modbus_data_ctx->action == MODBUS_DATA_ACTION_SET) {
				HAL_GPIO_WritePin(rey22_GPIO_Port, rey22_Pin, modbus_data_ctx->value);
			}
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
