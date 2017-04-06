#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const  int maxn=111;
int number[10];
int mat[maxn];
int oper()
{

    number[0]=6;
    number[1]=2;
    number[2]=5;
    number[3]=5;
    number[4]=4;
    number[5]=5;
    number[6]=6;
    number[7]=3;
    number[8]=7;
    number[9]=6;

    memset(mat,0,sizeof(mat));
    int i;
    for(i=0;i<maxn;i++)
    {
        int temp=i;
        while(temp!=0)
        {
            mat[i]+=number[temp%10];
            temp=temp/10;
        }
    }

}
int main()
{
    int times;
    oper();
    scanf("%d",&times);
    while(times--)
    {
        int n;
        scanf("%d",&n);
        int i,j;int ans1=0;int ans2=0;
        for(i=1;i<maxn;i++)
        {
            for(j=i+1;i+j<maxn;j++)
            {
                if(mat[i]+mat[j]+4+mat[i+j]==n)
                    ans1++;
            }
        }
        for(i=1;i<maxn/2;i++)
        {
            if(mat[i]+mat[i]+4+mat[i+i]==n)
                    ans2++;
        }
        printf("%d\n",ans2+ans1*2);




    }
    return 0;
}
