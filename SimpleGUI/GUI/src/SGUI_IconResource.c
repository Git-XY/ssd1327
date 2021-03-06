/*************************************************************************/
/** Copyright.															**/
/** FileName: SGUI_IconResource.c										**/
/** Author: XuYulin														**/
/** Description: Simple GUI basic drawing operating interface.			**/
/*************************************************************************/
//=======================================================================//
//= Include files.													    =//
//=======================================================================//
#include "SGUI_IconResource.h"

//=======================================================================//
//= Static variable define.												=//
//=======================================================================//
//SGUI_BMP_RESOURCE_DEFINE(SGUI_RES_ICON_ERROR_16, 16, 16,
//0xFF,0x01,0x01,0x19,0x39,0x71,0xE1,0xC1,0xC1,0xE1,0x71,0x39,0x19,0x01,0x01,0xFF,
//0xFF,0x80,0x80,0x98,0x9C,0x8E,0x87,0x83,0x83,0x87,0x8E,0x9C,0x98,0x80,0x80,0xFF);

//SGUI_BMP_RESOURCE_DEFINE(SGUI_RES_ICON_INFORMATION_16, 16, 16,
//0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0xED,0xED,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,
//0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0xBF,0xBF,0x80,0x80,0x80,0x80,0x80,0x80,0xFF);

//SGUI_BMP_RESOURCE_DEFINE(SGUI_RES_ICON_QUESTION_16, 16, 16,
//0xFF,0x01,0x01,0x01,0x31,0x39,0x1D,0x0D,0x0D,0x9D,0xF9,0xF1,0x01,0x01,0x01,0xFF,
//0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0xB6,0xB7,0x83,0x81,0x80,0x80,0x80,0x80,0xFF);

//SGUI_BMP_RESOURCE_DEFINE(SGUI_RES_ICON_WARNING_16, 16, 16,
//0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0xFD,0xFD,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,
//0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0xB7,0xB7,0x80,0x80,0x80,0x80,0x80,0x80,0xFF);

//SGUI_BMP_RESOURCE_DEFINE(SGUI_RES_ICON_ERROR_24, 24, 24,
//0xFF,0x01,0x01,0x01,0x71,0xF1,0xF1,0xE1,0xC1,0x81,0x01,0x01,0x01,0x01,0x81,0xC1,0xE1,0xF1,0xF1,0x71,0x01,0x01,0x01,0xFF,
//0xFF,0x00,0x00,0x00,0x00,0x00,0x81,0xC3,0xE7,0xFF,0xFF,0x7E,0x7E,0xFF,0xFF,0xE7,0xC3,0x81,0x00,0x00,0x00,0x00,0x00,0xFF,
//0xFF,0x80,0x80,0x80,0x8E,0x8F,0x8F,0x87,0x83,0x81,0x80,0x80,0x80,0x80,0x81,0x83,0x87,0x8F,0x8F,0x8E,0x80,0x80,0x80,0xFF);

//SGUI_BMP_RESOURCE_DEFINE(SGUI_RES_ICON_INFORMATION_24, 24, 24,
//0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x79,0x79,0x79,0x79,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,
//0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
//0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x98,0x9F,0x9F,0x9F,0x9F,0x98,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF);

//SGUI_BMP_RESOURCE_DEFINE(SGUI_RES_ICON_QUESTION_24, 24, 24,
//0xFF,0x01,0x01,0x01,0x01,0x01,0xC1,0xE1,0xF1,0xF1,0x79,0x79,0x79,0x79,0xF1,0xF1,0xE1,0xC1,0x81,0x01,0x01,0x01,0x01,0xFF,
//0xFF,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x00,0xC0,0xE0,0xF0,0xF8,0x7C,0x3F,0x1F,0x0F,0x07,0x00,0x00,0x00,0x00,0xFF,
//0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x9E,0x9E,0x9E,0x9E,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF);

//SGUI_BMP_RESOURCE_DEFINE(SGUI_RES_ICON_WARNING_24, 24, 24,
//0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xF1,0xF9,0xF9,0xF1,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,
//0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
//0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x9E,0x9E,0x9E,0x9E,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF);

SGUI_BMP_RESOURCE_DEFINE(SGUI_RES_ICON_WATHER64, 64, 64,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x7E,
0x7E,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x80,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,
0x0F,0x1F,0x1F,0x8E,0xC4,0xE0,0xF0,0xF8,0x78,0x7C,0x3C,0x3C,0x1E,0x1E,0x1E,0x1E,
0x1E,0x1E,0x1E,0x1E,0x3C,0x3C,0x78,0xF8,0xF0,0xE0,0xC4,0x8E,0x1F,0x1F,0x0F,0x07,
0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,
0x00,0xF8,0xFE,0xFF,0x1F,0x07,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x1F,0xFF,0xFE,0xF0,0x00,0x00,
0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x00,
0x00,0x0F,0x7F,0xFF,0xFC,0xF0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xFC,0xFF,0x7F,0x0F,0x00,0x00,
0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xE0,
0xF0,0xF8,0xFC,0x78,0x33,0x07,0x07,0x0F,0x0E,0x1E,0x3C,0x3C,0x38,0x78,0x78,0x78,
0x78,0x78,0x78,0x38,0x3C,0x3C,0x1E,0x1F,0x0F,0x03,0x33,0x78,0xFC,0xF8,0xF0,0xE0,
0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x7E,
0x7E,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00);

SGUI_BMP_RESOURCE_DEFINE(SGUI_RES_ICON_SPO232, 32, 32,
0x00,0x00,0x80,0xE0,0xF0,0xF8,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xF8,0xF8,0xE0,0xC0,
0xC0,0xE0,0xF8,0xF8,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xF8,0xF0,0xE0,0x80,0x00,0x00,
0x00,0x00,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x7F,0x7F,0x07,0x80,0x80,
0x07,0x3F,0xFF,0xFF,0x1F,0x1F,0xFF,0x3F,0x1F,0x9F,0x9F,0x9F,0x9F,0x1F,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x03,0x0F,0x1F,0x3F,0x7F,0xFE,0xF8,0xF0,0xF8,0xFF,0xFF,
0xFC,0xC0,0x03,0x00,0xF0,0xFC,0x70,0x38,0x1E,0x0F,0x03,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x1F,
0x1F,0x0F,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00);


