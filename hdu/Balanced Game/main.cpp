#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
   int time;
   scanf("%d",&time);
   while(time--)
   {
       int x;
       scanf("%d",&x);
        if(x%2==0)
            printf("Bad\n");
        else printf("Balanced\n");




   }



      return 0;
}
