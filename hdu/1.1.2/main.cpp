#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int times;

    long long a,b;
    scanf("%d",&times);
    while(times--)
    {
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",a+b);
    }
    return 0;
}
