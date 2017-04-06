#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mat[100000];
void oper()
{
    memset(mat,0,sizeof(mat));
    int i,j;
    for(i=0;i<100;i++)
    {
        if(mat[i]==0)
        {
            for(j=i;j<100;j+i)
                mat[j]=1;
        }
    }


    for(i=0;i<100;i++)
        {if(mat[i]==1)
            printf("%d\n",i);
        }


}
int main()
{
    oper();
    int i;
    return 0;
}


