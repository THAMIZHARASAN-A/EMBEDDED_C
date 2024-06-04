#include <AT89S52.h>
#define DATA P2
#define RS P0_7
#define RW P0_6
#define EN P0_5
#define trig P3_5
#define echo P3_2

__sfr DPTR=0x82;
unsigned int range=0;
unsigned char get;
 
void lcd_init(void);
void lcd_busy(void);
void lcd_data(char);
void lcd_cmd(char);
void lcd_print(char*);
void send_pluse(void);
unsigned char ultrasonic(void);
void Delay_us()
{
	TL0=0xF5;
	TH0=0xFF;
	TR0=1;
	while (TF0==0);
	TR0=0;
	TF0=0;
}

void main()
{
 lcd_init();
 lcd_print("Start");
 TMOD = 0x09;
 TR0 = 1;
 TH0 = 0x00;
 TL0 = 0x00;
 P3 = (1<<2);
 /*lcd_display("LCD Working");*/
 while(1)
 {
    lcd_cmd(0x84);
    range=ultrasonic();
    lcd_data((range/100)+48);
    lcd_data(((range/10)%10)+48);
    lcd_data((range%10)+48);
 }
}

void send_pluse()
{
  TH0 = 0x00;
  TL0 = 0x00;
  trig = 1;
  Delay_us();
  trig = 0;
}
unsigned char ultrasonic()
{
 
  send_pluse();
  while(!echo);
  while(echo);
  DPH=TH0;
  DPL=TL0;
  TH0=TL0=0xff;
  if(DPTR<38000)
  {
    get=DPTR/59;
    }
  else{
    get=0;
    }
  return get;
}

void lcd_init(void)
{
lcd_busy();
lcd_cmd(0x38);
lcd_cmd(0x01);
lcd_cmd(0x0C);
lcd_cmd(0x06);
lcd_cmd(0x80);
}


void lcd_cmd(char c)
{
DATA=c;
RS=0;
RW=0;
EN=1;
EN=0;
lcd_busy();
}

void lcd_data(char d)
{
DATA=d;
RS=1;
RW=0;
EN=1;
EN=0;
lcd_busy();
}
void lcd_busy()
{
char s;
RS=0;
RW=1;
DATA=0xFF;
EN=1;
s=DATA&0x80;
EN=0;  
while(s!=0x00)
{
  EN=1;
  s=DATA&0x80;
  EN=0;
}
}

void lcd_print(char*msg)
{
while(*msg!=0x00)
{
  lcd_data(*msg);
  *msg++;
}
}
void lcd_delay(void)
{
  unsigned int i;
  for(i=0;i<=1000;i++);
}
