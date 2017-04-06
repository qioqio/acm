#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int heads[100];
struct node
{
    int v,next;
}edge[1000];
int times;int cnt;

void add(int x,int y)
{
    edge[++cnt]=heads[x];
    edge[cnt].v=y;
    heads[x]=cnt;
    return;

}





int main()
{

    memset(edge,-1,sizeof(edge));
    int time=times;
    while(time--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        add(x,y);


    }



    return 0;
}