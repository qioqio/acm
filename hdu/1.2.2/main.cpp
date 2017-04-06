#include <iostream>
#include <stdio.h>
using namespace std;
int gcd(int a,int b)
{
    int temp;
    while(b!=0)
    {
        int temp=a%b;
        a=b;
        b=temp;

    }
    return a;





}
int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    while(a!=-1&&b!=-1)
    {

        if(gcd(a,b)==1)
            printf("YES\n");
        else printf("POOR Haha\n");
    scanf("%lld %lld",&a,&b);



    }
    return 0;
}
