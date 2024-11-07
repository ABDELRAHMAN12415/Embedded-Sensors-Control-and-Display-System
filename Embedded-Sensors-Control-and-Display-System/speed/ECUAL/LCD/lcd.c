#include "../../UTILITIES/types.h"
#include "../../UTILITIES/defines.h"
#include "../../UTILITIES/registers.h"
#include "../../MCAL/DIO DRIVER/dio.h"
#include "../../MCAL/INTERRUBTS/interrubt.h"
#include "lcd.h"

void LCD_4BIT_INIT(void)
{
	
	LCD_4BIT_SEND_COMMAND(0x02);/* 4bit mode initialization */
	LCD_4BIT_SEND_COMMAND(0x28);/* 2 line, 5*7 matrix in 4bit mode */
	LCD_4BIT_SEND_COMMAND(0x0c);/* display on, cursor off */
	LCD_4BIT_SEND_COMMAND(0x06);/* cursor shift_to_right */
	LCD_4BIT_SEND_COMMAND(0x01);/* clear display screen */
	
				TIMER_VALUE(TIMER2,6);					//count register initialization
				TIMER_START(TIMER2,CLK3);				//select F/ prescaler of timer2 and start
				TIMER_ov_WAIT(TIMER2);
				TIMER_STOP(TIMER2);
}

void LCD_4BIT_SEND_COMMAND(uint8_t comand)
{
	
	LCD_PORT = (LCD_PORT & 0x0f) | (comand & 0xf0);/* send upper nibble */
	LCD_PORT &= ~(1<<RS);/* RS=0 , command reg */
	LCD_PORT |= (1<<EN);/* enable pulse */
	
				TIMER_VALUE(TIMER2,56);					//count register initialization
				
	LCD_PORT &= ~(1<<EN);
	
				TIMER_START(TIMER2,CLK2);				//select F/ prescaler of timer2 and start
				TIMER_ov_WAIT(TIMER2);
				TIMER_STOP(TIMER2);
				
	LCD_PORT = (LCD_PORT & 0x0f) | (comand << 4);/* send lower nibble */
	LCD_PORT |= (1<<EN);
	
				TIMER_VALUE(TIMER2,6);					//count register initialization
				
	LCD_PORT &= ~(1<<EN);
	
				TIMER_START(TIMER2,CLK3);				//select F/ prescaler of timer2 and start
				TIMER_ov_WAIT(TIMER2);
				TIMER_STOP(TIMER2);
				
}

void LCD_4BIT_SEND_CHAR(uint8_t data)
{
	
	LCD_PORT = (LCD_PORT & 0x0f) | (data & 0xf0);/* send upper nibble */
	LCD_PORT |= (1<<RS);/* RS=1 , data reg */
	LCD_PORT |= (1<<EN);/* enable pulse */
	
				TIMER_VALUE(TIMER2,56);					//count register initialization
	
	LCD_PORT &= ~(1<<EN);
	
				TIMER_START(TIMER2,CLK2);				//select F/ prescaler of timer2 and start
				TIMER_ov_WAIT(TIMER2);
				TIMER_STOP(TIMER2);
	
	LCD_PORT = (LCD_PORT & 0x0f) | (data << 4);/* send lower nibble */
	LCD_PORT |= (1<<EN);
	
				TIMER_VALUE(TIMER2,6);					//count register initialization
	
	LCD_PORT &= ~(1<<EN);
	
				TIMER_START(TIMER2,CLK3);				//select F/ prescaler of timer2 and start
				TIMER_ov_WAIT(TIMER2);
				TIMER_STOP(TIMER2);
	
}

void LCD_4BIT_SEND_STRING(char *str)
{
	uint8_t i = 0;
	
while (str[i] != 0)
{
	LCD_4BIT_SEND_CHAR(str[i]);
	i++;
}
}

void LCD_4BIT_CURSOR_MOVE(uint8_t line, uint8_t digit)
{
	switch (line)
	{
		case 1:
		LCD_4BIT_SEND_COMMAND(0x80);
		break;
		
		case 2:
		LCD_4BIT_SEND_COMMAND(0xc0);
		break;
	}
	
	for (uint8_t i=0; i<=digit; i++)
	{
		LCD_4BIT_SEND_COMMAND(0x14);
	}
	
}

void LCD_4BIT_SEND_INT(int int_number)
{
	char num[3];
	
	itoa(int_number, num, 10);
	LCD_4BIT_SEND_STRING(num);
}