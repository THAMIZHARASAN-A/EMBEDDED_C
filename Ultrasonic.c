#include <AT89S52.h>
#define DATA P2
#define RS P0_7
#define RW P0_6
#define EN P0_5
#define trig P3_5
#define eco P3_2


void lcd_start(void);
void lcd_init(void);
void lcd_busy(void);
void lcd_data(char);
void lcd_cmd(char);
void lcd_display(char*);
void send_pluse(void);
unsigned int get_range(void);
void Delay_us()
{
	TL0=0xF5;
	TH0=0xFF;
	TR0=1;
	while (TF0==0);
	TR0=0;
	TF0=0;
}


int cms;

void main()
{
 lcd_init();
 lcd_display("Start");
 TMOD = 0x09;
 TR0 = 1;
 TH0 = 0x00;
 TL0 = 0x00;
 eco = 0x04;
 /*lcd_display("LCD Working");*/
 while(1)
 {
 get_range();
 Delay_us();
 }
}

void send_pluse(void)
{
  TH0 = 0x00;
  TL0 = 0x00;
  trig = 1;
  Delay_us();
  trig = 0;
}
unsigned int get_range(void)
{
 long int timer_val,i=0;
 send_pluse();
 while(!INT0);
 TR0 = 1;  
 while(INT0);
 TR0 = 0;  
 timer_val = (TH0<<8) + TL0;
 lcd_cmd(0x81);
 lcd_display("Output");
 lcd_cmd(0x8a);
 if(timer_val < 38000)
 {
  cms = timer_val/59;
  if((cms!=0) && (cms<100))
  {
   lcd_display((cms/10)+48);
   lcd_display((cms%10)+48);
   
  }
 }
 else{
  lcd_cmd(0x06);
  lcd_display("Out of Range");
 }
}

void lcd_init(void)
{
 EN=0;
 lcd_start();
 lcd_cmd(0x01);
 lcd_cmd(0x0C);
 lcd_cmd(0x06);
 lcd_cmd(0x80);
}

void lcd_busy(void)
{
 char b=0x80;
 DATA=0xF0;
 RS=0;
 RW=1;
 while(b!=0x00)
 {
  EN=1;
  b=DATA;
  EN=0;
  EN=1;
  EN=0;
  b=b&0x80;
 }
}

void lcd_data(char d)
{
 char d1,d0;
 RS=1;
 RW=0;
 DATA=(d&0xF0);
 EN=1;
 EN=0;
 DATA=(d<<4);
 EN=1;
 EN=0;
 lcd_busy();
}


void lcd_cmd(char c)
{
 RS=0;
 RW=0;
 DATA=(c&0xF0);
 EN=1;
 EN=0;
 DATA=(c<<4);
 EN=1;
 EN=0;
 lcd_busy();
}

void lcd_display(char*b)
{
 while(*b!=0x00)
 {
  lcd_data(*b);
  *b++;
 }
}

void lcd_start(void)
{
 EN=0;
 lcd_busy();
 RS=0;
 RW=0;
 DATA=0x30;
 EN=1;
 EN=0;
 lcd_busy();
 DATA=0x20;
 EN=1;
 EN=0;
 lcd_busy();
 lcd_cmd(0x28);
 P1_0=0;
}

