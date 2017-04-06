#include <stdio.h>
#include <stdlib.h>
const int maxn=100000;
int head[maxn];
int e[maxn];
int cts;
int next[maxn],line[maxn];
int buildedge(int a,int b,int c){
	e[cts]= b;
	len[cts]=c;
	next[cts]=head[a];
	head[a]=cts++;
}
void dij(int c)
{
    memset(dis,0x3f,sizeof(dis));
    memset(v,0,sizeof(v));
    dis[c]=0;

    int i,j;
    int mn,loc;
    for(i=1;i<=n;i++)
    {
        mn=1000000000;
        for(j=1;j<=n;j++)
        {
            if( v[j]==0 && dis[j]<mn )
                {
                    loc=j;
                    mn=dis[j];
                }
        }
        for(j=head[loc];j>0;j=next[j])
        {
            if(dis[j]>dis[loc]+len[j])
                dis[j]=dis[loc]+len[j];
        }
        v[loc]=1;
    }
}
int main()
{   cas=1;
    int n,m;
    scanf("%d %d",&n,&m);
    int i;
    for(i=0;i<n;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            buildedge(a,b,c);
        }

    return 0;
}
