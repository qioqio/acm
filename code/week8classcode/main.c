#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  maxn 1000

//int g[maxn][maxn];
//int v[maxn];
//int dis[maxn];
//int n;
//int ans=0;
//
//void prim()
//{
//    int i,j,k;
//    int mn,loc;
//    memset(v,0,sizeof(v));
//    memset(dis,10100,sizeof(dis));
//    dis[0]=0;
//    for(i=0;i<n;i++)
//    {
//        mn=10000007;
//        for(j=0;j<n;j++)
//        {
//                if(dis[j]<mn && v[j]==0)
//                    {mn=dis[j];
//                    loc=j;}
//        }
//        v[loc]=1;
//        ans+=dis[loc];
//        for(j=0;j<n;j++)
//        {
//            if(dis[j]>g[loc][j])
//                dis[j]=g[loc][j];
//        }
//     }
//}
//
//
//int main()
//{
//
//    n=3;
//    g[1][0]=g[0][1]=1;
//    g[1][2]=g[2][1]=3;
//    g[2][0]=g[0][2]=5;
//    prim();
//    printf("%d\n",ans);
//}


int set[maxn];
int n,m;
int ans;
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
    set[k]=findset(set[k]);
    return set[k];
}
void unionset(int a,int b)
{
    set[findset(a)]=findset(b);
}
typedef struct edge
{
    int u,v;
    int w;
}edge;
edge e[maxn];
int cmp(const void *a,const void *b)
{
    edge *aa=a;
    edge *bb=b;
    return aa->w-bb->w;
}
void kruskal()
{
    int i;
    ans=0;
    init();
    qsort(e,m,sizeof(edge),cmp);
    for(i=0;i<m;i++)
    {


        if(findset(e[i].u)!=findset(e[i].v))
        {
            unionset(e[i].u,e[i].v);
            ans+=e[i].w;

        }
    }


}
int main()
{
    n=3;
    m=3;
    e[0].u=0;e[0].v=1;e[0].w=3;
    e[1].u=2; e[1].v=0; e[1].w=3;
    e[2].u=2; e[2].v=1; e[2].w=8;

kruskal();
printf("%d\n",ans);
    return 0;
}














































