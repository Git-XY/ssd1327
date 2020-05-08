#ifndef __OLED_H__
#define __OLED_H__

#include <rthw.h>

#if defined(PKG_USING_SSD1327) || defined(RT_DEBUG_SSD1327)
#define OLED_X_PIXEL 128
#define OLED_Y_PIXEL 96
#define OLED_FRAME_BUFFER_SIZE ((OLED_X_PIXEL/2)*(OLED_Y_PIXEL))

typedef enum oled_set_color
{
	COLOR1  = 0x0,
	COLOR2  = 0x1,
	COLOR3  = 0x2,
	COLOR4  = 0x3,
	COLOR5  = 0x4,
	COLOR6  = 0x5,
	COLOR7  = 0x6,
	COLOR8  = 0x7,
	COLOR9  = 0x8,
	COLOR10 = 0x9,
	COLOR11 = 0xA,
	COLOR12 = 0xB,
	COLOR13 = 0xC,
	COLOR14 = 0xD,
	COLOR15 = 0xE,
	COLOR16 = 0xF
}oled_color;

typedef rt_uint16_t addr_t;
typedef rt_uint8_t  pos8_t;
typedef rt_bool_t   bool_t;

void oled_set_show_range(
			pos8_t x_start,
			pos8_t x_end,
			pos8_t y_start,
			pos8_t y_end);

void oled_draw_pixel(
			pos8_t x, 
			pos8_t y, 
			oled_color color);

void oled_set_clear_range(
			pos8_t x_start,
			pos8_t x_end,
			pos8_t y_start,
			pos8_t y_end);

void oled_refresh_all(void);

void oled_refresh_part(
			pos8_t x_start,
			pos8_t x_end,
			pos8_t y_start,
			pos8_t y_end);

//SimplleGUI½Ó¿Úº¯Êý
void	SCREEN_SetPixel(int iPosX, int iPosY, int iColor);
int		SCREEN_GetPixel(int iPosX, int iPosY);
int	    SCREEN_Initialize(void);
void	SCREEN_ClearDisplay(void);
void	SCREEN_RefreshScreen(void);

#endif
#endif
