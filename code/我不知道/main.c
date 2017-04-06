#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int mat[105];
    int i;
    for(i=1;i<105;i++)
    {

        mat[i]=1;
    }

    int number=101;

    while(number!=1)
    {
        int j;int flag=1;
        for(j=1;j<102;j++)
        {   if(mat[j])flag=(flag+1)%2;
           if(mat[j]&&(flag+1)%2){mat[j]=0;}

        }
        int i;number=0;
        for(i=1;i<102;i++)
        {
            if(mat[i]==1)number++;
        }

    }
    for(i=1;i<102;i++)
    {
        if(mat[i]==1)printf("%d\n",i);
    }

    return 0;
}







