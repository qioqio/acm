#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <malloc.h>

struct node//定义节点
{
	int number;
	struct node *next;
};
struct node *head;//定义链表的头
void creat()//创建链表
{
	int n;
	//初始化头结点
	head = (node*)malloc(sizeof(node));
	scanf("%d", &n);
	head->number = n;
	head->next = NULL;
	struct node *curr = head;
	//定义其他节点,从文件读入其他节点数据
	while (scanf("%d", &n)!=EOF)
	{
		curr->next = (node*)malloc(sizeof(node));
		curr = curr->next;
		curr->number = n;
		curr->next = NULL;
	}
}
void print()
{    //打印链表的所有节点，
	node *p = head;
	while (p != NULL)
	{
		printf("%d ",p->number);
		p = p->next;
	}
	printf("\n");
}

int len()
{
	node *p = head;
	int ans = 0;//记录链表的长度
	while (p != NULL)
	{
		ans++;
		p = p->next;
	}
	return ans;
}
void find(int x)//找到 链表中第一个数字是x的元素下标
{
	node *p = head;
	int n = 0;
	while (p)
	{
		if (x==p->number)//找到数据之后，结束程序运行
		{
			printf("The position of %d is ", x);
			printf("%d\n", n); return;
		}
		n++;
		p = p->next;
	}
		printf("Sorry,the number is not in tne linklist.\n");
}
//将链表逆序，并且返回链表的头指针

node *rebuild(node *head)
 {
   node *newHead;
   //如果链表中元素个数不大于1的话，结束递归
    if ((head == NULL) || (head->next == NULL))
        return head;
    newHead = rebuild(head->next); /*递归部分*/
    head->next->next = head; /*回朔部分*/
    head->next = NULL;
	return newHead;
 }
void index(int position, int x)
{
	if (position < 0)
		printf("The position must be a positive number.");
	node *p = head;
	int n = 0;//n记录元素位置
	while (p != NULL)
	{
		//找到该位置后，进行插入操作
		if (n==position)
		{
			int temp = p->number;
			p->number = x;
			node *p2 = (node*)malloc(sizeof(node));
			p2->number = temp;
			p2->next = p->next;
			p->next = p2;
			return;
		}
		n++;
		p = p->next;
	}
	printf("Sorry,the position is too large.\n");

}
//删除第一个数值是x的元素
int del(int x)
{
	node *p;
	node *temp;
	if (head == NULL)
	{
		return 0;
	}
	if (head->number == x)//如果头结点的数值是x的话，进行删除操作
	{
		temp = head;
		head = head->next;
		free(temp);
		return 1;
	}
	p = head->next;
	temp = head;//temp指向p的前一个结点
	while (p)
	{
		if (p->number == x)//找到第一个数值是x的元素之后，进行删除操作
		{
			temp->next=p->next;
			free(p);
			return 1;
		}
		p = p->next;
		temp = temp->next;
	}
	return 0;

}

int sort()
{


	node *p1 = head;
	node *p2 = head;
	//外层循环使用p1指针，循环元素个数次
	for (p1 = head; p1 != NULL; p1 = p1->next)
		//内层循环使用p2指针，循环元素个数减去一次
		for (p2 = head; p2->next != NULL; p2 = p2->next)
		{//如果前面元素的值大于后面元素的值就进行换序
			if (p2->number > p2->next->number)
			{
				int temp = p2->number;
				p2->number = p2->next->number;
				p2->next->number = temp;
			}
		}
	return 0;
}
int main()
{
    freopen("in.txt","r",stdin);

	creat();fclose(stdin);
    freopen("CON", "r", stdin);
	printf("The linklist has finished.\n");
	printf("The linklist is ");
	print();

	sort();
	printf("After the  sort .The linklist is ");
	print();

	int x,position;

	printf("Please input the value.");
	scanf("%d", &x);
	find(x);

	printf("Please input  the position and the value.");
	scanf("%d %d", &position,&x);
	index(position, x);
	printf("The linklist is ");
	print();

	scanf("%d", &x);
	del( x);
	printf("After delet ,the linklist is ");
	print();

	printf("The length of the listlink is  %d\n", len());

	head=rebuild(head);
	printf("After the rebulid,the linklist is ");
	print();
	return 0;
}
/*
1 3 5 8 9 4 6 7 55 30 48 12 4 513 1 54 1997
1997
0 1997
1997

*/

























