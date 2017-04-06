#include <iostream>
#include <set>
#include<stdio.h>
using namespace std;
set<long long> a;

int main()
{
    a.insert(1);
    long long i=0;
    int time=1;
    for(;;)
    {
        i=*a.lower_bound(i+1);
        if(i>1000000000)break;
        a.insert(i*2);
        a.insert(i*3);
        a.insert(i*5);
        a.insert(i*7);
        time++;
    }

    int times;
    scanf("%d",&times);
    while(times--)
    {
        int ans;
        scanf("%d",&ans);
        ans=*a.lower_bound(ans);
        printf("%d\n",ans);
    }
    return 0;
}

