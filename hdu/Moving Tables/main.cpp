#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int mat[401];
int main()
{
    int times;
    scanf("%d",&times);
    while(times--)
    {
        memset(mat,0,sizeof(mat));
        int time;
        scanf("%d",&time);
        while(time--)
        {
            int s,t;
            scanf("%d %d",&s,&t);
            if(s>t)
            {
                int temp=t;
                t=s;
                s=temp;

            }
            int a,b;
            if(t==t/2*2)
                a=t;
            else a=t+1;
            if(s==s/2*2)
                b=s-1;
            else b=s;
            for(int i=b;i<=a;i++)
            {
                mat[i]++;

            }

        }
    int maxn=0;
    for(int i=1;i<=400;i++)
    {
         maxn=max(maxn,mat[i]);


    }

    printf("%d\n",maxn*10);

    }
    return 0;
}
