#include <iostream>
#include<stdio.h>
using namespace std;
char mat[100000];
int main()
{
    int times;
    scanf("%d",&times);
    int i;
    for( i=0;i<times;i++)
    {
        int x;
        scanf("%d",&x);
        mat[i]=x;
    }
    mat[i]='\0';
    printf("%s",mat);
    return 0;
}
