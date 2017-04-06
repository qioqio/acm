#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100
int g[maxn][maxn];
int v[maxn];
int dis[maxn];
int n,ans;
void oper()
{
    ans=0;
    memset(dis,0x3f,sizeof(dis));
    memset(v,0,sizeof(v));
    dis[0]=0;
    int i,j,k;
    int loc,mn;
    for(i=0;i<n;i++)
    {   mn=1000000000;
        for(j=0;j<n;j++)
        {
            if(dis[j]<mn && v[j]==0)
            {
                mn=dis[j];
                loc=j;
            }
        }
        v[loc]=1;

        ans+=dis[loc];
        for(j=0;j<n;j++)
        {
            if(dis[j]>g[loc][j])
                dis[j]=g[loc][j];
        }
    }

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif

    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&g[i][j]);
            }
        }
        oper();
        printf("%d\n",ans);

    }



    return 0;
}






















