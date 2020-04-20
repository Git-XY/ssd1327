#include "ssd1327.h"
#include "oled.h"

static rt_uint8_t frameBuffer  [OLED_FRAME_BUFFER_SIZE];
#define CoordsToAddress(x,y) (((x) >> 1)+((y) << 6)) // y<<6 == y*64

static rt_err_t oled_coords_check(pos8_t x_start,pos8_t x_end,pos8_t y_start,pos8_t y_end)
{
    if ((x_start >= OLED_X_PIXEL) || (y_start >= OLED_Y_PIXEL))
        return -RT_ERROR;
    if ((x_end   >= OLED_X_PIXEL) || (y_end   >= OLED_Y_PIXEL))
        return -RT_ERROR;
   return RT_EOK;
}

//range x1~x2:0-127
//range y1~y2:0-95
void oled_set_show_range(pos8_t x_start,pos8_t x_end,pos8_t y_start,pos8_t y_end)
{
	if(oled_coords_check(x_start,x_end,y_start,y_end) != RT_EOK)
	  return ;
	rt_uint8_t buf[6];
	buf[0] = SSD1327_SET_COLUMN_ADDR;	 // Set Column Address
    buf[1] = x_start >> 1; 				 // A[5:0]:Start Address, range:00h~3Fh,(RESET = 00h)
    buf[2] = x_end   >> 1; 				 // B[5:0]:End Address, range:00h~3Fh,(RESET = 3Fh)
    buf[3] = SSD1327_SET_ROW_ADDR;		 //  Set Row Address   
    buf[4] = y_start;                    //  A[6:0]: Start Address, range:00h~7Fh (RESET = 00h)
	buf[5] = y_end;                      //  B[6:0]: End Address, range:00h~7Fh (RESET = 7Fh)
	ssd1327_write_large_cmd(buf,6);       
}

//pixel xy coordinates 0-127, color 0-15, and whether to immediately output it to the display or buffer it
void oled_draw_pixel(pos8_t x, pos8_t y, oled_color color)
{
    if((x%2) == 0)
        frameBuffer[CoordsToAddress(x,y)] = (frameBuffer[CoordsToAddress(x,y)] & 0x0f) | (color<<4);
    else
        frameBuffer[CoordsToAddress(x,y)] = (frameBuffer[CoordsToAddress(x,y)] & 0xf0) | (color);
}

//range x1~x2:0-127
//range y1~y2:0-95
void oled_set_clear_range(pos8_t x_start,pos8_t x_end,pos8_t y_start,pos8_t y_end)
{
	if(oled_coords_check(x_start,x_end,y_start,y_end) != RT_EOK)
	  return ;
	
	oled_set_show_range(x_start, x_end, y_start,y_end);
	
	rt_uint8_t *tempbuf = RT_NULL;
	rt_uint16_t size    = ((x_end >> 1) - (x_start >> 1) +1)*(y_end - y_start +1);
	tempbuf = (rt_uint8_t *)rt_malloc(size);
    rt_uint8_t *count = tempbuf;
    for (pos8_t y = y_start; y <= y_end; y++)
    {
        for (pos8_t x = (x_start >> 1); x <= (x_end >> 1); x++,count++)
        {
			 frameBuffer[x+(y << 6)] = 0;
			 *(count++)              = 0;
        }
    }
	
	ssd1327_write_large_data(tempbuf,size);
	
	rt_free(tempbuf);
}

void oled_refresh_all()
{
    oled_set_show_range(0,127,0,95);
    ssd1327_write_large_data(frameBuffer,OLED_FRAME_BUFFER_SIZE);
}


void oled_refresh_part(pos8_t x_start,pos8_t x_end,pos8_t y_start,pos8_t y_end)
{
	if(oled_coords_check(x_start,x_end,y_start,y_end) != RT_EOK)
	  return ;	
	
	oled_set_show_range(x_start, x_end, y_start,y_end);
	
	rt_uint16_t size  = ((x_end >> 1) - (x_start >> 1) +1)*(y_end - y_start +1);
	rt_uint8_t *tempbuf = (rt_uint8_t *)rt_malloc(size);
   	rt_uint8_t *count = tempbuf;
	
    for (pos8_t y = y_start; y <= y_end; y++)
    {
        for (pos8_t x = (x_start >> 1); x <= (x_end >> 1); x++)
        {
			*(count++) = frameBuffer[x+(y << 6)];
        }
    }
	ssd1327_write_large_data(tempbuf,size);
	rt_free(tempbuf);
}


void SCREEN_SetPixel(int iPosX, int iPosY, int iColor)
{
    if(iColor == 0)
        oled_draw_pixel(iPosX, iPosY, COLOR1);
    if(iColor == 1)
        oled_draw_pixel(iPosX, iPosY, COLOR3);
}

int SCREEN_GetPixel(int iPosX, int iPosY)
{
    return frameBuffer[CoordsToAddress(iPosX,iPosY)];
}

int	 SCREEN_Initialize(void)
{
    return rt_hw_ssd1327_init();
}

void SCREEN_ClearDisplay(void)
{
    rt_memset(frameBuffer, 0, sizeof(frameBuffer));
}
void SCREEN_RefreshScreen(void)
{
    oled_refresh_all();
}
