#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;
int mat[10000];


typedef struct node
{
    int a;

}lnode,*linklist;

int main()
{
lnode *p;
 p=(linklist)malloc(sizeof(lnode));
p->a=3;
printf("%d\n",p->a);
    return 0;
}
