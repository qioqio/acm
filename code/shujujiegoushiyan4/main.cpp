#include <iostream>
#include<stdio.h>
using namespace std;
int mat[10000];
int  read()//先将数据读进来，并且返回数据元素的个数。
{
    int n=0;
    while(scanf("%d",&mat[n])!=EOF)
    {
       n++;
    }
    return n;
}

int AdjustArray(int l, int r) //返回调整后基准数的位置
{
	int i = l, j = r;
	int x = mat[l];
	while (i < j)
	{
		// 从右向左找小于x的数来填s[i]
		while(i < j && mat[j] >= x)
			j--;
		if(i < j)
		{
			mat[i] =mat[j]; //将s[j]填到s[i]中，s[j]就形成了一个新的坑
			i++;
		}

		// 从左向右找大于或等于x的数来填s[j]
		while(i < j && mat[i] < x)
			i++;
		if(i < j)
		{
			mat[j] = mat[i]; //将s[i]填到s[j]中，s[i]就形成了一个新的坑
			j--;
		}
	}
	//退出时，i等于j。将x填到这个坑中。
	mat[i] = x;

	return i;
}

void sort( int l, int r)//下面进行递归的快速排序
{
    if (l < r)
    {
        int i = AdjustArray( l, r);
        sort( l, i - 1); // 递归调用
        sort( i + 1, r);
    }
}



void print(int num)//打印输出结果
{

    for(int i=0;i<num;i++)
    {
        printf("%d,",mat[i]);
    }
    printf("\n");
}

int main()
{
    //把第一个文件读入，进行快速排序。
    freopen("in1.txt","r",stdin);
    int num=read();
    printf("Before  the sort,the mat is:\n");
    print(num);
    sort(0,num-1);
    printf("After  the sort,the mat is:\n");
    print(num);
    //将第二个文件读入，进行快排操作。
    freopen("in2.txt","r",stdin);

    num =read();
    printf("Before  the sort,the mat is:\n");
    print(num);
    sort(0,num-1);
    printf("After  the sort,the mat is:\n");
    print(num);

    return 0;
}
