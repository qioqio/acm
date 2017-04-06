#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int mat[1005];
int main()
{
    int times;
    scanf("%d",&times);

    for(int i=0;i<times;i++)
    {
        scanf("%d",&mat[i]);
    }
   sort(mat, mat+times);

        int zhong=times/2;
        int min=0,max=0;
        for(int j=zhong;j>=0;j--)
        {

            if(mat[j]!=mat[zhong])
               {
                    min=j+1;
                    break;

               }

        }
        for(int j=zhong;j<times;j++)
        {

            if(mat[j]!=mat[zhong])
               {
                    max=times-j;
                    break;

               }

        }
        if(min==max)
            printf("%d\n",mat[zhong]);
        else
        printf("-1\n");




    return 0;
}
