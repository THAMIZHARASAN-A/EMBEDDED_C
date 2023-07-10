#include<AT89S52.h>
#define DATA P0
#define DIGIT P1

const char seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xf8,0x80,0x90};
void wait(int del);

void main()
{
DIGIT = 0X0F;
DATA = 0XFF;
	while(1)
	{
		DATA=seg[2];
		DIGIT = 0X07;
		DIGIT = 0X0F;

		DATA=seg[3];
		DIGIT = 0X0B;
		DIGIT = 0X0F;

		DATA=seg[0];
		DIGIT = 0X0D;
		DIGIT = 0X0F;

		DATA=seg[3];
		DIGIT = 0X0E;
		DIGIT = 0X0F;
	}
}
void wait(int del)
{
 int j;
  for(j=0;j<del;j++)
  {
  
  }
 
}

