#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 500

typedef struct btnode
{
	char c[10];
	struct btnode *l, *r;
}BTNode;
BTNode *creat_bt()/*二叉树的建立*/
{
	int i = 0, k;
	char n[10], p[10], position[10];
	BTNode *s, *que[MAXSIZE];
	scanf("%s", n);
	while (strcmp(n,"-1"))
	{
	    scanf("%s", p);
	    scanf("%s", position);
		s = (BTNode*)malloc(sizeof(BTNode));

		strcpy(s->c,n);
		s->l = NULL;
        s->r = NULL; que[i] = s; i++;
		for (k = 0; k<i; k++)
		{
			if (!strcmp(que[k]->c,p))
            {
                if (!strcmp(position,"L"))
                que[k]->l = s;
                if (!strcmp(position,"R"))
                que[k]->r = s;
            }
		}
		scanf("%s", n);
	}
	return que[0];
}
void  DLR(BTNode *bt)
{/*前序递归遍历*/
	if (bt)
	{
		printf("%s,", bt->c);
		DLR(bt->l);
		DLR(bt->r);
	}
}/* DLR*/
void  LDR(BTNode *bt)
{/*中序递归遍历*/
	if (bt)
	{
		LDR(bt->l);
		printf("%s,", bt->c);
		LDR(bt->r);
	}
}/* LDR*/
void  LRD(BTNode *bt)
{/*后序递归遍历*/
	if (bt)
	{
		LRD(bt->l);
		LRD(bt->r);
		printf("%s,", bt->c);
	}
}/* LRD*/
void LevelOrder(BTNode *bt) /*层次遍历二叉树bt*/
{
	BTNode* Q[MAXSIZE];
	BTNode* q;
	int front = 0, rear = 0;
	if (bt == NULL)return;
	Q[++rear] = bt;
	while (front != rear)
	{
		q = Q[++front];
		printf("%s,", q->c);
		if (q->l != NULL)Q[++rear] = q->l;
		if (q->r != NULL)Q[++rear] = q->r;
	}
}
int  main()
{
	freopen("in.txt","r",stdin);
	BTNode *t;
	t = creat_bt();
	printf("前序遍历结果:\n"); DLR(t);printf("\n");
	printf("中序遍历结果:\n"); LDR(t);printf("\n");
	printf("后序遍历结果:\n"); LRD(t);printf("\n");
	printf("按层遍历结果:\n"); LevelOrder(t);printf("\n");
	printf(" 程序退出!\n ");
	return 0;

}

