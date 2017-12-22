#include "Playing.h"




void Playing()
{
    while(sum>0)
    {
        start = clock();
        if(PlayerVsComp==0)
        {
            ValidPlace=1;
            Moving();
        }
        else if (PlayerVsComp==1)
        {
            if(wchPlayer==1)
            {
                ValidPlace=1;
                Moving();
            }
            else if (wchPlayer==2)
            {
                computerRandom();

            }
        }
        else if (PlayerVsComp==2)
        {
            if(wchPlayer==1)
            {
                ValidPlace=1;
                Moving();
            }
            else if (wchPlayer==2)
            {
                computerGreedy();
            }
        }
      //  if (minPassed==0){
        end = clock();
        dif+= (end-start)/(double)CLOCKS_PER_SEC;
       // }
     /*   else if (minPassed==1){
            end=clock();
            dif+=(end-start)/(double)CLOCKS_PER_SEC;

        } */
        minPassed=0;
        system("cls");
        Print();
    }
}
