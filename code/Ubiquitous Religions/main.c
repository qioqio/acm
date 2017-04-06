#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  maxn 51000
int n;
int m;
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
    if(set[k]==k)
        return k;
    set[k]= findset(set[k]);
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
    int i,j;
    int times=0;
    while(scanf("%d %d",&n,&m)&& m!=0 &&n!=0)
    {
        int i;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&e[i].u,&e[i].v);
        }
        init();
        for(i=0;i<m;i++)
            if(findset(e[i].u)!=findset(e[i].v))
                unionset(e[i].u,e[i].v);
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(set[i]==i)ans++;
        }
        times++;
        printf("Case %d: %d\n",times,ans);

    }
    return 0;
}



















