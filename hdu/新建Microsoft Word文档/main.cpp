#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;
int mat[5000];
int fuck(int n)
{
    if(n==0)return 1;
    return 10*fuck(n-1);
}
int main()
{
    int times;
    scanf("%d",&times);
    getchar();

    while(times--)
    {
        char str[20];
        gets(str );
        if(!strcmp(str,"New"))
        {
            for(int i=1;i<5000;i++)
                if(mat[i]==0)
                {

                    mat[i]=1;
                    printf("%d\n",i);
                    break;
                }

        }
        else
        {
            int num=0;
            for(int i=1;i<strlen(str);i++)
            {
                if(str[strlen(str)-i]<'0'||str[strlen(str)-i]>'9')break;
                num=num+(str[strlen(str)-i]-'0')*fuck(i-1);

            }

            if(mat[num]==1)
            {
               mat[num]=0;
               printf("Successful\n");


            }
            else
                printf("Failed\n");
        }


    }


    return 0;
}
