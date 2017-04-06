#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100000000
#define maxcity 10006
int n,m;
struct Edge
{
    int to,next;
}edge[100050];
int head[50010];
int vis[100010],tot;
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dfs(int x)
{   int i;
    for( i = head[x]; i != -1; i = edge[i].next)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(edge[i].to);
        }
    }
    printf("%d\n",x);
}
int main()
{
    int t,C = 1;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        int u,v;
        int i;
        tot = 0;
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        for(i = 0; i < m; i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs(1);
    }
    return 0;
}




