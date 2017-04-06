#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int times;
    scanf("%d",&times);
    for( int i=0;i<times;i++)
    {
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      int x=b-c-a;
     // printf("%d  %d %d %d ****\n",a,b,c,x);

        if(x>0)printf("advertise\n");
        if(x==0)printf("does not matter\n");
        if(x<0)printf("do not advertise\n");

    }

    return 0;
}
