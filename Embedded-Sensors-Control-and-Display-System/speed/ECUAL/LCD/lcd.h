
#ifndef LCD_H_
#define LCD_H_

#define LCD_PORT PORTA
#define EN 7
#define RS 5

void LCD_4BIT_INIT(void); 

void LCD_4BIT_SEND_COMMAND(uint8_t cmnd);

void LCD_4BIT_SEND_CHAR(uint8_t data);

void LCD_4BIT_SEND_STRING(char *str);

void LCD_4BIT_SEND_INT(int int_number);

void LCD_4BIT_CURSOR_MOVE(uint8_t line, uint8_t digit);

#endif 