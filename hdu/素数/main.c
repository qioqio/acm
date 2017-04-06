#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,flag;
    for(x=100;x<=200;x++)
    {   flag=1;
        for(y=2;y<x;y++)
        {
             if(x%y==0)
               {

                   flag=0;
                   break;
               }



        }
        if(flag==1)
            printf("%d\n",x);


    }
    return 0;
}
