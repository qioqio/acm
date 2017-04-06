#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <malloc.h>

using namespace std;



struct Node {
	double coef;//系数
	int expn;//指数
	Node *next;//指针，指向下一个节点
};

Node *A = NULL;//定义三个多项式指针
Node *B = NULL;
Node *c = NULL;
void sort(Node *&head)//排序函数
{
	if (head->next->next == NULL)  //如果只有一个节点的话，不用排序，直接返回即可
	{
		 return;
	}
	else
	{//采用冒泡排序
		for (Node *p = head->next; p != NULL; p = p->next)//外层循环，循环元素个数次
		{
			for (Node *q = head->next; q->next != NULL; q = q->next)//内层循环，循环元素个数减去一次
			{
				if (q->expn > q->next->expn)//如果前面的元素指数大于后面的，就进行换序
				{
					int temp1 = q -> expn;
					q->expn = q->next->expn;
					q->next->expn = temp1;
					double temp2=  q->coef;
					q->coef = q->next->coef;
					q->next->coef = temp2;
				}
			}
		}

	}

}

void sort2(Node *&head)//排序函数（采用这个 函数实现c链表的逆序）
{
	if (head->next->next == NULL)  //如果只有一个节点的话，不用排序，直接返回即可
	{
		return;
	}
	else
	{//采用冒泡排序
		for (Node *p = head->next; p != NULL; p = p->next)//外层循环，循环元素个数次
		{
			for (Node *q = head->next; q->next != NULL; q = q->next)//内层循环，循环元素个数减去一次
			{
				if (q->expn < q->next->expn)//如果前面的元素指数小于后面的，就进行换序
				{
					int temp1 = q->expn;
					q->expn = q->next->expn;
					q->next->expn = temp1;
					double temp2 = q->coef;
					q->coef = q->next->coef;
					q->next->coef = temp2;
				}
			}
		}

	}

}
void CreatPolynomial(Node *&head)//创造 一个 多项式链表
{
	head = (Node *)malloc(sizeof(Node));
	head->coef = 0;
	head->expn = 0;
	head->next = NULL;
	Node *p = head;
	int a, b;
	scanf("%d %d", &a, &b);
	while(b>=0)
	{
		p->next = (Node *)malloc(sizeof(Node));  //  生成新结点，尾插入生成链表
		p = p->next;
		p->coef = a;
		p->expn = b;
		p->next = NULL;
		scanf("%d %d", &a, &b);
	}

}

void PrintPolynomial(Node *&head)//打印多项式
{
	if (head==NULL) //  结果多项式没有元素就直接退出
	{
		printf("\n"); return ;
	}
	else {
		for (Node *p = head->next; p != NULL; p = p->next)//head->next是第一个元素，所以从它开始打印
		{
			cout <<'['<< p->coef<<' '<<p->expn<<']';
		}
	}
	cout << endl;//打印换行符
}


void Free(Node *&head)//定义一个类似于析构函数的东西
{
	Node *q = NULL;
	for (Node *p = head; p != NULL; p = q) {
		q = p->next;
		free(p);
	}
}

char cmp(int a, int b)
{
	if (a > b)
		return '>';
	if (a < b)
		return '<';
	return '=';
}

void AddPolynomial(Node *&pA, Node *&pB)//  传进两个链表的头指针
{
	c = (Node *)malloc(sizeof(Node));
	c->coef = 0;
	c->expn = 0;
	c->next = NULL;
	Node *p = c;
	Node *ha = pA;
	Node *hb = pB;
	Node *qa = ha->next; //  ha, hb分别跟在qa, qb的后一位置
	Node *qb = hb->next; //  qa, qb分别指向Pa, Pb中当前比较元素
	while (qa && qb)
	{
		double sum = 0;
		int a = qa->expn;
		int b = qb->expn;
		switch (cmp(a, b)) //比较qa与qb的系数
		{
		case '<':
			p->next = (Node *)malloc(sizeof(Node));  //  生成新结点，尾插入生成链表
			p = p->next;
			p->coef = qa->coef;
			p->expn =qa->expn ;
			p->next = NULL;

			ha = qa;
			qa = qa->next;
			break;
		case '>':
			p->next = (Node *)malloc(sizeof(Node));  //  生成新结点，尾插入生成链表
			p = p->next;
			p->coef = qb->coef;
			p->expn = qb->expn;
			p->next = NULL;

			hb = qb;
			qb = qb->next;
			break;

		case '=':
			sum = qa->coef + qb->coef;
			if (sum != 0.0)
			{

				p->next = (Node *)malloc(sizeof(Node));  //  生成新结点，尾插入生成链表
				p = p->next;
				p->coef = sum;
				p->expn = qa->expn;
				p->next = NULL;
				ha = qa;
				hb = qb;
			}
			qb = qb->next;
			qa = qa->next;
			break;
		}
	}
	if (qa)
	{
		while (qa)
		{
			p->next = (Node *)malloc(sizeof(Node));  //  生成新结点，尾插入生成链表
			p = p->next;
			p->coef = qa->coef;
			p->expn = qa->expn;
			p->next = NULL;

			ha = qa;
			qa = qa->next;
		}
	}
	if (qb)
	{
		while (qb)
		{
			p->next = (Node *)malloc(sizeof(Node));  //  生成新结点，尾插入生成链表
			p = p->next;
			p->coef = qb->coef;
			p->expn = qb->expn;
			p->next = NULL;
			hb = qb;
			qb = qb->next;
		}
	}
}
int main()
{

	int times;
	scanf("%d", &times);
	while(times--)
	{
		CreatPolynomial(A);  sort(A);//将多项式创造出来，并且按照升序排列
		CreatPolynomial(B);  sort(B);

		AddPolynomial(A, B); //  c = A + B
		sort2(c);
		PrintPolynomial(c);//  输出c
		Free(A); Free(B);//  务必释放结点
	}
	return 0;
}
/*
2
-1 17 2 20 5 9 -7 7 10 4 22 2 2 0 16 5 0 -1
2 19 7 7 3 17 4 4 15 10 -10 5 13 2 -7 0 8 -8
3 5 -2 1 4 0 0 -1
7 7 1 6 -1 5 8 -8



*/
