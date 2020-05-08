#include "ssd1327.h"
#include "oled.h"
#include "SGUI_Basic.h"
#include "SGUI_Text.h"
#include "SGUI_FontResource.h"
#include "SGUI_ProcessBar.h"
#if (defined(PKG_USING_SSD1327) && defined(PKG_USING_SSD1327_SAMPLE))|| defined(RT_DEBUG_SSD1327)
void ssd1327_sample()
{

	//SCREEN_Initialize();//ssd1327.c init.
	
	SCREEN_ClearDisplay();
    ssd1327_set_power(POWER_ON);
	
	SGUI_SCR_DEV Oled128X96   = {0x00};
	Oled128X96.fnInitialize   = SCREEN_Initialize;
    Oled128X96.stSize.iWidth  = 128;
	Oled128X96.stSize.iHeight = 96;
	Oled128X96.fnSetPixel     = SCREEN_SetPixel;
	Oled128X96.fnGetPixel     = SCREEN_GetPixel;
	Oled128X96.fnClear        = SCREEN_ClearDisplay;
	Oled128X96.fnSyncBuffer   = SCREEN_RefreshScreen;
	
	//电池 
	SGUI_PROCBAR_STRUCT pstProcessBarData;
	pstProcessBarData.Parameter.Direction = SGUI_PROCBAR_LEFT;
	pstProcessBarData.Parameter.Height    = 7;
	pstProcessBarData.Parameter.Width     = 12;
	pstProcessBarData.Parameter.PosX      = 115;
	pstProcessBarData.Parameter.PosY      = 0;
	pstProcessBarData.Parameter.MaxValue  = 100;
    pstProcessBarData.Data.Value          = 50;
	SGUI_ProcessBar_Repaint(&Oled128X96,&pstProcessBarData);
	SGUI_Basic_DrawRectangle(&Oled128X96,113, 2, 2,3, SGUI_COLOR_FRGCLR,SGUI_COLOR_TRANS);
	
	 SGUI_RECT   pstDisplayArea;
	 SGUI_POINT  pstInnerPos;
	 pstDisplayArea.iHeight = 8;
	 pstDisplayArea.iWidth  = 18;
	 pstDisplayArea.iX      = 113 - 18;
	 pstDisplayArea.iY      = 1;
	 pstInnerPos.iX = 0;
	 pstInnerPos.iY = 0;
	 SGUI_Text_DrawText(&Oled128X96, "50%", &SGUI_DEFAULT_FONT_8,&pstDisplayArea, &pstInnerPos,SGUI_DRAW_NORMAL);
	
	//时间
     pstDisplayArea.iHeight = 46;
	 pstDisplayArea.iWidth  = 16*8;
	 pstDisplayArea.iX      = 0;
	 pstDisplayArea.iY      = 25;
	 pstInnerPos.iX = 0;
	 pstInnerPos.iY = 0;
	 SGUI_Text_DrawText(&Oled128X96, "22:36:12", &SGUI_DEFAULT_FONT_32,&pstDisplayArea, &pstInnerPos,SGUI_DRAW_NORMAL);
     
	 pstDisplayArea.iHeight = 16;
	 pstDisplayArea.iWidth  = 8*9;
	 pstDisplayArea.iX      = 0;
	 pstDisplayArea.iY      = 73;
	 pstInnerPos.iX         = 0;
	 pstInnerPos.iY         = 0;
	 SGUI_Text_DrawText(&Oled128X96, "2020.4.18", &SGUI_DEFAULT_FONT_12,&pstDisplayArea, &pstInnerPos,SGUI_DRAW_NORMAL);
		
	//NB标识
	SGUI_Basic_DrawLine(&Oled128X96, 0, 0, 8, 0, SGUI_COLOR_FRGCLR);
	SGUI_Basic_DrawLine(&Oled128X96, 4, 0, 4, 7, SGUI_COLOR_FRGCLR);
	SGUI_Basic_DrawLine(&Oled128X96, 0, 0, 4, 4, SGUI_COLOR_FRGCLR);
	SGUI_Basic_DrawLine(&Oled128X96, 4, 4, 8, 0, SGUI_COLOR_FRGCLR);
	
	//NB信号
	SGUI_Basic_DrawLine(&Oled128X96, 6, 7, 6, 5, SGUI_COLOR_FRGCLR); //25%
	SGUI_Basic_DrawLine(&Oled128X96, 8, 7, 8, 4, SGUI_COLOR_FRGCLR); //50%
	SGUI_Basic_DrawLine(&Oled128X96, 10, 7, 10, 3,SGUI_COLOR_FRGCLR);//75%
	SGUI_Basic_DrawLine(&Oled128X96, 12, 7, 12, 2,SGUI_COLOR_FRGCLR);//100%
	
	Oled128X96.fnSyncBuffer();
	rt_thread_mdelay(5000);
	SCREEN_ClearDisplay();
	Oled128X96.fnSyncBuffer();
	ssd1327_set_power(POWER_OFF);
}

MSH_CMD_EXPORT(ssd1327_sample,ssd1327 sample);

#endif
