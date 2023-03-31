#include<AT89S52.h>
#define BUZ P0_0
#define ON 1
#define OFF 0
#define SWITCH P3_3
#define INPUT 0                    
void main()
{
   __bit status;
   BUZ =ON;
   SWITCH = INPUT;
   while(1)
   {
     status=SWITCH;
     BUZ=!status;
   }
}
