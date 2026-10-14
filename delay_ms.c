void delay_ms(unsigned int ms);
void delay_ms(unsigned int ms)
{
T0PR =15000-1;
T0TCR=0x1;
while(T0TC<ms);
T0TCR=0x3;
T0TCR=0x0;
   
 
}  