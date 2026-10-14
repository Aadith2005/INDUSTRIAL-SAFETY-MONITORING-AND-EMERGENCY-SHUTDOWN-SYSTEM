#include<LPC21XX.H>
void UART_CONFIG(void);
void UART_CONFIG(void);
void UART_TX(unsigned char);
unsigned char UART_RX(void);
void UART_STR(unsigned char*);
void UART_INTEGER(signed int);
void UART_FLOAT(float);


void UART_CONFIG(void)
{
PINSEL0 |=0X05;
U0LCR=0X83;
U0DLL=97;
U0DLM=0;
U0LCR=0X03;
}
void UART_TX(unsigned char txbyte)
{
while(((U0LSR>>5)&1)==0);
U0THR=txbyte;
}

unsigned char UART_RX(void)
{
while((U0LSR&1)==0);
return U0RBR;
}

void UART_STR(unsigned char *s)
{
while(*s)
{
UART_TX(*s++);
}
}


void UART_INTEGER(signed int n)
{
unsigned char arr[5];
int i=0;
if(n==0)
{
UART_TX('0');
return;
}
else
{
if(n<0)
{
UART_TX('-');
n=-n;
}
while(n>0)
{
arr[i++]=n%10;
n=n/10;
}
for(--i;i>=0;i--)
{
UART_TX(arr[i]+48);
}
}
}

void UART_FLOAT(float f)
{
int temp=f;
UART_INTEGER(temp);
UART_TX('.');
temp=(f-temp)*10;
UART_INTEGER(temp);
}
