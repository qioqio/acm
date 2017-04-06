#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int times;
    scanf("%d",&times);
    for( int i=0;i<times;i++)
    {

      char x;
      int a,b;
      scanf(" %c %d %d",&x,&a,&b);
      if(x=='+')printf("%d\n",a+b);
      if(x=='-')printf("%d\n",a-b);
      if(x=='*')printf("%d\n",a*b);
      if(x=='/'&&(a/b-a*1.0/b!=0))printf("%.2f\n",a*1.0/b);
       if(x=='/'&&(a/b-a*1.0/b==0))  printf("%d\n",a/b);
    }

    return 0;
}
