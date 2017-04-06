#include <iostream>
#include <stdio.h>
using namespace std;
long long n,k;
int main()
{
    scanf("%lld %lld",&n,&k);
    long long l,r,mid;
    l=0;
    r=k;
    while(l<r)
    {
        mid=(l+r)/2;
         long long s = mid * k - (mid - 1) * (mid + 2) / 2;
         if(s<n)
         {
             l=mid+1;

         }
        if(s>=n)
        {
            r=mid;
        }


    }
    mid=(l+r)/2;
    if(mid*k-(mid-1)*(mid+2)/2<n)
        printf("-1\n");
    else printf("%lld\n",mid);
    return 0;
}










