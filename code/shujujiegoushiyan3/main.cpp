#include<stdio.h>
#include <string.h>
#include<iostream>
#define number 100//数据元素个数最大值，同时也是元素名字长度的最大值
#define MAX 100000//路径权值最大值
using namespace std;
int mat[number][number];//记录节点之间的距离
int n;//记录节点的数目
int v[number];//遍历图的时候记录节点是否被访问过
char s[number][number];//记录每个元素叫什么名字
int dis[number];//记录初始节点到其他节点的最短距离
int que[number];//记录初始节点到其他节点最短路径的最后一个元素
void dfs(int i)//深度优先搜索
{
    printf("%s\n",s[i]);//将第i个元素打印输出
    v[i]=1;//将i记录成已经访问过
    for(int j=0;j<n;j++)
    {
        if(mat[i][j]<MAX&&v[j]==0)
        {
            dfs(j);
        }
    }

}
void path()
{
    int mark[number];//标记数组，记录那些元素被访问过
    int i, j, min, k, tmp;
    memset(que,0,sizeof(que));//所有节点到初始节点的路径初始化为直接到达
    memset(mark,0,sizeof(mark));
    //初始化dis数组
    for (i = 0; i < n; i ++)
        dis[i] = mat[0][i];
    dis[0] = 0;
    mark[0] = 1;//将0这个节点置成已经访问过

//下面是典型的Dijkstra算法，首先找到距离初始节点最近的节点，然后进行松弛操作，每次循环找到一个节点，所以进行n-1次循环
    for (i = 1; i < n; i ++)
    {
        min = MAX;
        for (j = 0; j < n; j ++)
        {
            if (!mark[j] && dis[j] < min) {
                k = j;
                min = dis[j];
            }
        }
        mark[k] = 1;


        for (j = 0; j < n; j ++) {
            tmp = mat[k][j] + dis[k];
            if (tmp < dis[j] )
            {
                dis[j] = tmp;
                que[j]=k;
            }
        }
    }

}

void show(int v)   //打印最短路径上的各个顶点
{
    //先将所有的信息压入栈中，然后进行输出
    int stack[number];
    int a=0;
    int u=v;
    while(v!=0)
    {
        a++;
        stack[a]=v;
        v=que[v];
    }
    a++;
    stack[a]=v;
    while(a!=0)
    {
        cout<<s[stack[a]]<<",";
        a--;
    }

}

int main()
{
    //首先对第一个文件进行操作，（由于老师的文件有很多无用的信息，而且格式很复杂，所以我的读入操作写的很乱。
   // 但是最终是将节点按照顺序存在s这个二维数组中，将点与点之间的距离存入mat二维数组中）
    memset(mat,0x3f,sizeof(mat));//将节点之间的距离赋值成很大的数

    freopen("ex3_Graph1.txt","r",stdin);
	char c;
	scanf("%c",&c);
	while(c!=':')scanf("%c", &c);
	scanf("%c", &c);
	 n = c - '0';
	scanf("%s",s[1]);
	for(int i=0;i<n;i++)
    scanf("%s", s[i]);

    char cs[number];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", cs);
		for (int j = 0; j < n; j++)
		{
			int x;
			scanf("%d\n",&x);
			if(x!=-1)
			mat[i][j] = x;


		}
	}

//	for(int i=0;i<n;i++)
//        mat[i][i]=0;

    memset(v,0,sizeof(v));
	dfs(0);
	path();
	//下面打印结果
	printf("graph1:\n");
    for(int i=1;i<n;i++)
    {

        printf("%s->%s path:",s[0],s[i]);
        // 打印路径
        show(i);//打印初始节点到其他节点的最短距离
        printf("value=%d\n",dis[i]);
    }




//下面打开第二个文件，进行操作，操作完全一样，但是在打印输出 的时候，稍有不同

    memset(mat,0x3f,sizeof(mat));//将节点之间的距离赋值成很大的数
    freopen("ex3_Graph2.txt","r",stdin);
	scanf("%c",&c);
	while(c!=':')scanf("%c", &c);
	scanf("%c", &c);
	 n = c - '0';
	scanf("%s",s[1]);
	for(int i=0;i<n;i++)
    scanf("%s", s[i]);


	for (int i = 0; i < n; i++)
	{
		scanf("%s", cs);
		for (int j = 0; j < n; j++)
		{
			int x;
			scanf("%d\n",&x);
			if(x!=-1)
			mat[i][j] = x;


		}
	}
//
//	for(int i=0;i<n;i++)
//        mat[i][i]=0;

    memset(v,0,sizeof(v));
	dfs(0);
	path();
	printf("graph2:\n");
    printf("%s->%s path:",s[0],s[7]);
    show(7);
    printf("value=%d\n",dis[7]);

	return 0;
}
