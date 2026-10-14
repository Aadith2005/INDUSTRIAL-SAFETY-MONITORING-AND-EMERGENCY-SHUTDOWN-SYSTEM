#include <LPC21XX.H>
#include "delay_ms.c"
#include "lcd_header.h"
#include "UART_header.h"
#define m1 1<<21
#define m2 1<<22
#define LED 1<<23

int flag=0;

//char* title="industrial";
//char* start="motor running";
//char* stop="motor stopped";

void motor_ISR(void)   __irq
{

//EXTINT=(1<<1 )|(1<<2);
if(((VICIRQStatus>>15)&1)==1)
{
EXTINT=(1<<1);
IOCLR0=m1;
IOCLR0=m2;
IOSET0=LED;
UART_STR("MOTOR STOP!! ");
LCD_COMMAND(0X01);
LCD_STR("MOTOR STOP!!");
delay_ms(2000);
flag=1;
VICVectAddr=0;
}
else if(((VICIRQStatus>>16)&1)==1)
{
EXTINT=1<<2;
IOCLR0=m1;
IOCLR0=m2;
IOSET0=LED;
UART_STR("MOTOR STOP!! ");
LCD_COMMAND(0X01);
LCD_STR("MOTOR STOP!!");
delay_ms(2000);
flag=1;
VICVectAddr=0;
}
}
  
int main()
{
//EINT1
PINSEL0|=(1<<29);
PINSEL0&=~(1<<28);
//EINT2
PINSEL0|=(1<<31);
PINSEL0&=~(1<<30);
IODIR0|=m1|m2|LED;

IOSET0=LED;
VICIntSelect=0;
VICDefVectAddr=(unsigned long)motor_ISR;

EXTMODE=0X06;
EXTPOLAR=0X00;

//VICIntEnable=(1<<15)|(1<<16);
VICIntEnable=(1<<15)|(1<<16);
LCD_INIT();
LCD_COMMAND(0x80);
LCD_COMMAND(0X01);

UART_CONFIG();
UART_STR("Industrial Safety monitoring & Emergency shutdown system ");
LCD_TITLE("Industrial Safety monitoring & Emergency shutdown system");
delay_ms(5000);
LCD_COMMAND(0X01);

IOCLR0=m1;
IOSET0=m2;
IOCLR0=LED;
UART_STR("Motor Running ");
LCD_STR("Motor Running");

while(1)
{
if(flag==1)
{
LCD_COMMAND(0X01);
IOCLR0=m1;
IOSET0=m2;
IOCLR0=LED;
UART_STR("Motor Running ");
LCD_STR("Motor Running");
flag=0;
}
else
continue;
}
}

