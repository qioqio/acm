#include <stdio.h>
#include <stdlib.h>
int   f(long long a,long long  b,int c)
{
    if(b==0)return 1;
    if(b==1)return a%c;
    int ans;
    ans=f(a,b/2,c)%c;
    ans=(ans*ans)%c;
    if(b%2==1)
    {
        return (ans*a)%c;
    }
    else return ans%c;
}
int main()
{
    int times;
    scanf("%d",&times);
    while(times--)
    {
        long long n;
        scanf("%d",&n);
        printf("%d\n",f(n,n,10));
    }
    return 0;
}
