

/*================================================================
 *
 *
 *   文件名称：channels_config.h
 *   创 建 者：肖飞
 *   创建日期：2021年01月18日 星期一 11时00分11秒
 *   修改日期：2022年05月06日 星期五 14时41分11秒
 *   描    述：
 *
 *================================================================*/
#ifndef _CHANNELS_CONFIG_H
#define _CHANNELS_CONFIG_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "app_platform.h"
#include "cmsis_os.h"

typedef struct {
	void *huart;
	void *con_gpio;
	uint16_t con_pin;
	void *led_gpio;
	uint16_t led_pin;
	uint8_t station;
} display_config_t;

typedef struct {
	uint8_t id;
	display_config_t display_config;
} channels_config_t;

channels_config_t *get_channels_config(uint8_t id);

#ifdef __cplusplus
}
#endif

#endif //_CHANNELS_CONFIG_H
