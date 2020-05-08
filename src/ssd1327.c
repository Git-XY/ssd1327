#include "ssd1327.h"
#include <board.h>
#include <drv_spi.h>
#if defined(PKG_USING_SSD1327) || defined(RT_DEBUG_SSD1327)
#define SPI_BUS_NAME				"spi2"
#define SPI_SSD1327_DEVICE_NAME 	"spi20"

#define RES_PIN  GET_PIN(C, 5)
#define DC_PIN   GET_PIN(C, 6)
#define CS_PIN   GET_PIN(C, 8)

#define SWAP(a,b) (a) ^= (b);(b) = (a)^(b);(a) ^= (b);

static struct rt_spi_device *spi_dev_ssd1327;

static int rt_hw_ssd1327_config(void)
{
    rt_err_t res;
   struct rt_spi_configuration cfg;
    res = rt_hw_spi_device_attach(SPI_BUS_NAME, SPI_SSD1327_DEVICE_NAME, GPIOC, GPIO_PIN_8);
    if (res != RT_EOK)
        return res;
	     
	cfg.data_width = 8;
	cfg.mode       = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
	cfg.max_hz     = 20* 1000 *1000; 
     spi_dev_ssd1327 = (struct rt_spi_device *)rt_device_find(SPI_SSD1327_DEVICE_NAME);
	if (!spi_dev_ssd1327)
    {
        rt_kprintf("spi sample run failed! can't find %s device!\n", SPI_SSD1327_DEVICE_NAME);
    }
	else
    /* config spi */
    {
        rt_spi_configure(spi_dev_ssd1327, &cfg);
    }

    return RT_EOK;
}

int rt_hw_ssd1327_init(void)
{
    rt_hw_ssd1327_config();

    rt_pin_mode(DC_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(RES_PIN, PIN_MODE_OUTPUT);

    rt_pin_write(RES_PIN, PIN_LOW);
    rt_thread_delay(100);
    rt_pin_write(RES_PIN, PIN_HIGH);

	rt_uint8_t buf[] =
    {0xAE,0xa0,0x51,0xa1,0x00,0xa2,0x00,
	 0xa4,0xa8,0x7f,0xab,0x01,0x81,0x77,
	 0xb1,0x31,0xb3,0xb1,0xb5,0x03,0xb6,
	 0x0d,0xbc,0x07,0xbe,0x07,0xd5,0x02};//,0xAF
	if(ssd1327_write_large_cmd(buf,sizeof(buf))!= RT_EOK)
		 return -RT_ERROR;
    return RT_EOK;
}
#if !defined(PRO_USING_DEVICE_INIT)
INIT_DEVICE_EXPORT(rt_hw_ssd1327_init);
#endif


int ssd1327_write_cmd(const rt_uint8_t cmd)
{
    rt_pin_write(DC_PIN, PIN_LOW);
    if (rt_spi_send(spi_dev_ssd1327, &cmd, 1) != 1)
        return -RT_ERROR;
    else
        return RT_EOK;
}
int ssd1327_write_large_cmd(const rt_uint8_t *cmd,rt_uint16_t len)
{
	    rt_pin_write(DC_PIN, PIN_LOW);
	
    if (rt_spi_send(spi_dev_ssd1327, cmd, len) != len)
        return -RT_ERROR;
    else
        return RT_EOK;
}

int ssd1327_write_large_data(const rt_uint8_t *data,rt_uint16_t len)
{
    rt_pin_write(DC_PIN, PIN_HIGH);
    if (rt_spi_send(spi_dev_ssd1327, data, len) != len)
        return -RT_ERROR;
    else
        return RT_EOK;
}


void ssd1327_set_overall_contrast(rt_uint8_t data)
{
	rt_uint8_t buf[2];
	buf[0] = 0x81;
	buf[1] = data;
	ssd1327_write_large_cmd(buf,2);
}

int ssd1327_set_power(ssd1327_power power)
{
	rt_uint8_t buf[3];
	buf[0] = 0xAF;   //退出休眠模式
	buf[1] = 0xB5;   //通过设置SSD1327 GPIO来控制升压电路的使能管脚
	buf[2] = power;  //打开或者关闭电源
	if(ssd1327_write_large_cmd(buf,3)!= RT_EOK)
		 return -RT_ERROR;
    return RT_EOK;
}

void ssd1327_set_scroll(
					rt_uint8_t x_start,
					rt_uint8_t x_end, 
					rt_uint8_t y_start,
					rt_uint8_t y_end, 
					scroll_speed speed,
					scroll_direct direct,
					rt_uint32_t duration)
{
    if (x_start > x_end) //swap 
    {  
        SWAP(x_start,x_end);
    }
	
    if (y_start > y_end)
    {  
		SWAP(y_start,y_end);
    }
	rt_uint8_t buf[10];
	    buf[0] = 0x2E;//关闭滚动 
    if (direct)
        buf[1] = 0x26;
    else
        buf[2] =  0x27;
        buf[3] =  0;
	    buf[4] =  y_start;
	    buf[5] =  speed;
	    buf[6] =  y_end;
	    buf[7] =  x_start >> 1;
	    buf[8] =  x_end   >> 1;
	    buf[9] =  0;
    ssd1327_write_large_cmd(buf,10);
	
    ssd1327_write_cmd(0x2F); //start
    rt_thread_mdelay(duration);
    ssd1327_write_cmd(0x2E); //stop;
}

#endif
