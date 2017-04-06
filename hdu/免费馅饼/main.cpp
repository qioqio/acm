#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int mat[100001][11];

int max3(int a,int b,int c)
{
    if(a>=b&&a>=c)return a;
    else if (b>=c)return b;
    else return c;

}
int max2(int a,int b)
{
    if(a>=b)return a;
    else return b;

}
int main()
{
    int times;
    scanf("%d",&times);

    while(times!=0)
    {
        memset(mat,0,sizeof(mat));
        int a,b,maxb=0;
        for(int i=0;i<times;i++)
        {
            scanf("%d %d",&a,&b);

            maxb=max2(maxb,b);
            mat[b][a]++;

        }

        for(int i=maxb-1;i>=0;i--)
        {

            for(int j=1;j<=9;j++)
            {
            //    printf("%d %d %d %d %d %d\n",i,j,mat[i][j],mat[i+1][j],mat[i+1][j+1],mat[i+1][j-1]);


                mat[i][j]=max3(mat[i+1][j],mat[i+1][j+1],mat[i+1][j-1])+mat[i][j];

            }
            mat[i][0]=mat[i][0]+max2(mat[i+1][0],mat[i+1][1]);
            mat[i][10]=mat[i][10]+max2(mat[i+1][10],mat[i+1][9]);
        }
        printf("%d\n",mat[0][5]);

        scanf("%d",&times);
    }

    return 0;
}
