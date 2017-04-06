#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;



struct node
{
    int v,next;
}edge[100];
int cnt;
int heads[100];
void add(int x,int y)
{
     edge[++cnt].next=heads[x];
    edge[cnt].v=y;
    heads[x]=cnt;
    return ;
}


int main()
{
    memset(heads,-1,sizeof(heads));
    int times;
    scanf("%d",&times);
    for(int j=0;j<times;j++)
    {

        int x,y;
        scanf("%d %d",&x,&y);
        add(x,y);
    }
    for(int i=0;i<100;i++)
    {
        for(int j=heads[i];j!=-1;j=edge[j].next)
            printf("%d %d\n",i,edge[j].v);
    }
    return 0;

}


/*

5
2 1
45 2
1 6
2 49
1 5
*/
//struct node
//{
//    int v,next;
//}edge[1000];
//int times;int cnt;
//
//void add(int x,int y)
//{
//    edge[++cnt].next=heads[x];
//    edge[cnt].v=y;
//    heads[x]=cnt;
//    return;
//
//}
//int main()
//{
//    scanf("%d",&times);
//   memset(heads,-1,sizeof(heads));
//    int time=times;
//    while(time--)
//    {
//        int x,y;
//        scanf("%d %d",&x,&y);
//        add(x,y);
//    }
//    for(int i=0;i<100;i++)
//    {
//       for(int j=heads[i];j!=-1;j=edge[j].next)
//        printf("%d %d\n",i,edge[j].v);
//
//    }
//    return 0;
//}

