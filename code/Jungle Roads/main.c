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
    memset(dis,1000000,sizeof(dis));
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
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
    scanf("%d",&n);
    while(n!=0)
    {
        memset(g,0x3f,sizeof(g));

        char a, b;
        int i,j,l;
        for(i=0;i<n-1;i++)
        {
            scanf(" %c %d",&a,&l);
            for(j=0;j<l;j++)
                {
                    scanf(" %c",&b);
                    scanf("%d",&g[a-'A'][b-'A']);
                    g[b-'A'][a-'A']=g[a-'A'][b-'A'];
                }
        }
        oper();

        printf("%d\n",ans);

        scanf("%d",&n);
    }
	return 0;
}

























