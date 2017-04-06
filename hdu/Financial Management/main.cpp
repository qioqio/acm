#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    float sum=0;
    for(int i=0;i<12;i++)
    {
        float temp=0;
        scanf("%f",&temp);
        sum+=temp;
    }




  printf("$%.2f\n",sum/12);
    return 0;
}
