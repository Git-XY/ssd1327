/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:   add max30102 register
 * Date           Author       Notes
 * 2020-03-26     xiaoyuan    the first version
 */
#ifndef __SSD1327_H__
#define __SSD1327_H__

#include <rthw.h>
#include "ssd1327_reg.h"

#if defined(PKG_USING_SSD1327) || defined(RT_DEBUG_SSD1327)
typedef enum ssd1327_set_power
{
	POWER_OFF = 0x02,
	POWER_ON  = 0x03
}ssd1327_power;

typedef enum ssd1327_set_scroll_speed
{
	SCROLL_2       =    0x07,
	SCROLL_3       =    0x04,
	SCROLL_4       =    0x05,
	SCROLL_5       =    0x06,
	SCROLL_6       =    0x00,
	SCROLL_32      =    0x01,
	SCROLL_64      =    0x02,
	SCROLL_256     =    0x03
}scroll_speed;

typedef enum ssd1327_set_scroll_direct
{
	SCROLL_RIGHT,
	SCROLL_LIFT
}scroll_direct;

int rt_hw_ssd1327_init(void);

int ssd1327_write_cmd(const rt_uint8_t cmd);

int ssd1327_write_large_cmd(const rt_uint8_t *cmd,rt_uint16_t len);

int ssd1327_write_large_data(const rt_uint8_t *data,rt_uint16_t len);

void ssd1327_set_overall_contrast(rt_uint8_t data);

int ssd1327_set_power(ssd1327_power power);

void ssd1327_set_scroll(
					rt_uint8_t x_start,
					rt_uint8_t x_end, 
					rt_uint8_t y_start,
					rt_uint8_t y_end, 
					scroll_speed speed,
					scroll_direct direct,
					rt_uint32_t duration);

#endif
#endif

