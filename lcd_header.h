#define LCD_D 0xff << 23
#define RS 1<<19
#define E  1<<18
void LCD_INIT(void);
void LCD_COMMAND( unsigned char);
void LCD_DATA(unsigned char);
void LCD_STR(unsigned char*);
void LCD_TITLE(unsigned char *s);



void LCD_INIT()
{
PINSEL1|=0;
IODIR1=LCD_D|RS|E;
LCD_COMMAND(0X01);
LCD_COMMAND(0X02);
LCD_COMMAND(0X0C);
LCD_COMMAND(0X38);
}
void LCD_COMMAND(unsigned char cmd)
{
IOCLR1=LCD_D;
IOSET1=cmd<<23;
IOCLR1=RS;
IOSET1=E;
delay_ms(2);
IOCLR1=E;
}



void LCD_DATA(unsigned char d)
{
IOCLR1=LCD_D;
IOSET1=d<<23;
IOSET1=RS;
IOSET1=E;
delay_ms(2);
IOCLR1=E;
}

void LCD_STR(unsigned char *s)
{
while(*s)
LCD_DATA(*s++);
}

void LCD_TITLE(unsigned char *s)
{
int i=0;
while(*s)
LCD_DATA(*s++);
while(i<24)
{
delay_ms(500);
LCD_COMMAND(0X18);
i++;
}
} 









