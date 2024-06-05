#include<AT89S52.h>

#define DATA P2
#define RS P0_7
#define EN P0_5
#define RW P0_6
#define IR1 P1_0
#define IR2 P1_1
#define IR3 P1_2
#define IN P1_7
#define IT P1_6


void lcd_init(void);
void lcd_data(char);
void lcd_cmd(char);
void lcd_busy(void);
void lcd_print(char*);
void delay(void);

void main()
{
  while(1)
   {
    if(IR1 == 1 && IR2 == 1 && IR3 == 1)
    {
        lcd_init();
        lcd_print("CAR PARCKING SYS");
        lcd_cmd(0xC0);
        lcd_print("SLOT AVL:3");
    }
    else if(IR1 == 1 && IR2 == 1 && IR3 == 0)
    {
        lcd_init();
        lcd_print("CAR PARCKING SYS");
        lcd_cmd(0xC0);
        lcd_print("SLOT AVL:2");
        IN = 0;
	IT = 1;
	delay();
	IN = 0;
	IT = 0;
	delay();
	IN = 1;
	IT = 0;
	delay();
	IN = 0;
	IT = 0;
	delay();
    }
    else if(IR1 == 1 && IR2 == 0 && IR3 == 1)
    {
        lcd_init();
        lcd_print("CAR PARCKING SYS");
        lcd_cmd(0xC0);
        lcd_print("SLOT AVL:2");
        IN = 0;
	IT = 1;
	delay();
	IN = 0;
	IT = 0;
	delay();
	IN = 1;
	IT = 0;
	delay();
	IN = 0;
	IT = 0;
	delay();
    }
    else if(IR1 == 1 && IR2 == 0 && IR3 == 0)
    {
        lcd_init();
        lcd_print("CAR PARCKING SYS");
        lcd_cmd(0xC0);
        lcd_print("SLOT AVL:1");
        IN = 0;
	IT = 1;
	delay();
	IN = 0;
	IT = 0;
	delay();
	IN = 1;
	IT = 0;
	delay();
	IN = 0;
	IT = 0;
	delay();
    }
    else if(IR1 == 0 && IR2 == 1 && IR3 == 1)
    {
        lcd_init();
        lcd_print("CAR PARCKING SYS");
        lcd_cmd(0xC0);
        lcd_print("SLOT AVL:2");
        IN = 0;
	IT = 1;
	delay();
	IN = 0;
	IT = 0;
	delay();
	IN = 1;
	IT = 0;
	delay();
	IN = 0;
	IT = 0;
	delay();
    }
    else if(IR1 == 0 && IR2 == 1 && IR3 == 0)
    {
        lcd_init();
        lcd_print("CAR PARCKING SYS");
        lcd_cmd(0xC0);
        lcd_print("SLOT AVL:1");
        IN = 0;
	IT = 1;
	delay();
	IN = 0;
	IT = 0;
	delay();
	IN = 1;
	IT = 0;
	delay();
	IN = 0;
	IT = 0;
	delay();
    }
    else if(IR1 == 0 && IR2 == 0 && IR3 == 1)
    {
        lcd_init();
        lcd_print("CAR PARCKING SYS");
        lcd_cmd(0xC0);
        lcd_print("SLOT AVL:1");
        IN = 0;
	IT = 1;
	delay();
	IN = 0;
	IT = 0;
	delay();
	IN = 1;
	IT = 0;
	delay();
	IN = 0;
	IT = 0;
	delay();
    }
    else if(IR1 == 0 && IR2 == 0 && IR3 == 0)
    {
        lcd_init();
        lcd_print("CAR PARCKING SYS");
        lcd_cmd(0xC0);
        lcd_print("SLOT AVL:0");
        IN = 0;
	IT = 1;
	delay();
	IN = 0;
	IT = 0;
	delay();
	IN = 1;
	IT = 0;
	delay();
	IN = 0;
	IT = 0;
	delay();
    }
    else{
        IN = 0;
        IT = 0;
    }
   }
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

void delay(void)
{
 int i,j;
 for(i=0;i<500;i++)
 {
  for(j=0;j<500;j++)
  {}
 }
}
