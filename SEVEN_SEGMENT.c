#include<AT89S52.h>

const char seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xf8,0x80,0x90};
void wait(int del);
void main()
{
while(1)
{
int i,j;
	for(i=0;i<10;i++)
	{
		P0=seg[i];
		wait(1);
	}
	for(j=10;j>=0;j--)
	{
		P0=seg[j];
		wait(1);
	}
}
}
void wait(int del)
{
 int j;
  for(j=0;j<del;j++)
  {
  
  }
 
}

