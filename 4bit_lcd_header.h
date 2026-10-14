#define LCD_D 0xf << 21
#define RS 1<<12
#define E  1<<13
void LCD_INIT(void);
void LCD_COMMAND( unsigned char);
void LCD_DATA(unsigned char);
void LCD_STR(unsigned char*);


void LCD_INIT()
{
PINSEL0=0;
IODIR0=LCD_D|RS|E;
LCD_COMMAND(0X01);
LCD_COMMAND(0X02);
LCD_COMMAND(0X0C);
LCD_COMMAND(0X28);
}
void LCD_COMMAND(unsigned char cmd)
{
IOCLR0=LCD_D;
IOSET0=(cmd&0xf0)<<17;
IOCLR0=RS;
IOSET0=E;
delay_ms(2);
IOCLR0=E;

IOCLR0=LCD_D;
IOSET0=(cmd&0x0f)<<21;
IOCLR0=RS;
IOSET0=E;
delay_ms(2);
IOCLR0=E;
}



void LCD_DATA(unsigned char d)
{
IOCLR0=LCD_D;
IOSET0=(d&0xf0)<<17;
IOSET0=RS;
IOSET0=E;
delay_ms(2);
IOCLR0=E;

IOCLR0=LCD_D;
IOSET0=(d&0x0f)<<21;
IOSET0=RS;
IOSET0=E;
delay_ms(2);
IOCLR0=E;
}

void LCD_STR(unsigned char *s)
{
while(*s)
LCD_DATA(*s++);
} 