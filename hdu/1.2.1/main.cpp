#include <iostream>
#include<stdio.h>
#include <string.h>
using namespace std;
char mat[1000];

int main()
{
    int times;
    scanf("%d",&times);getchar();
    for( int i=0;i<times;i++)
    {
        gets(mat);
        int x=0;
        for(int i=0;i<=strlen(mat);i++)
        {
            if(mat[i]==' '||mat[i]=='\0')
            {
                for(int k=i-1;k>=x;k--)
                printf("%c",mat[k]);
                if(mat[i]==' ')printf("%c",mat[i]);
                x=i;
            }
        }
        if(i!=times-1)
        printf("\n");
    }

    return 0;
}
