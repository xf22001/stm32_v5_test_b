
/*================================================================
 *   
 *   
 *   文件名称：test_can_b.h
 *   创 建 者：肖飞
 *   创建日期：2022年05月06日 星期五 16时47分11秒
 *   修改日期：2022年05月06日 星期五 16时47分32秒
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

#include "channels.h"

void test_can_b(channels_info_t *channel_info, void *hcan, uint8_t id);

#ifdef __cplusplus
}
#endif
#endif //_TEST_CAN_B_H
