#include<AT89S52.h>
void main()
{

   while(1)
   {
     if(P0_1==0 && P1_1==1)
      {
         P2_0=0;
      }
      else if(P0_1==1 && P1_1==0)
      {
         P2_0=0;
      }
      
     else if(P0_1==0 && P1_1==0)
      {
        P2_0=1;
      }
      else 
      {
        P2_0=1;
      }
   }
}
