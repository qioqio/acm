#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int maxn=300000;
char num[1000000000];
double mat[maxn];
int main()
{
    mat[0]=0;
    for(int i=1;i<maxn;i++)
    {
        mat[i]=mat[i-1]+1.0/i/i;
    }
    while(scanf("%s",num)!=EOF)
    {
        if(strlen(num)>6)
            printf("1.64493\n");
        else
        {
            int numb=0;
            for(int i=0;i<strlen(num);i++)
            {
                numb=numb*10+(num[i]-'0');
            }
            if(numb<=maxn-1)
             printf("%.5lf\n",mat[numb]);
             else   printf("1.64493\n");


        }






    }







    return 0;
}

