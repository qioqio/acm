#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 300000
int n,m;
int set[maxn];
typedef struct edge
{
    int u,v;
}edge;
edge e[maxn];
void init()
{
    int i;
    for(i=0;i<n;i++)
        set[i]=i;

}
int findset(int k)
{
    if(set[k]==k)return k;
    set[k]=findset(set[k]);
    return set[k];
}
void unionset(int a,int b)
{
    set[findset(a)]=findset(b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif

    scanf("%d %d",&n,&m);
    while(n!=0)
    {
        int i;
        int time=0;
        for(i=0;i<m;i++)
        {   int j,k;
            int x,y;
            scanf("%d %d",&j,&x);
            for(k=1;k<j;k++)
            {
                scanf("%d",&y);
                e[time].u=x;
                e[time].v=y;
                time++;
                x=y;
            }
        }
        init();
        for(i=0;i<time;i++)
        {
            if(findset(e[i].u)!=findset(e[i].v))
                unionset(e[i].u,e[i].v);
        }
        int z=findset(0);
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(z==findset(i))ans++;
        }

        printf("%d\n",ans);
        scanf("%d %d",&n,&m);
    }
    return 0;
}










