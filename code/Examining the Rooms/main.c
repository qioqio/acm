#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long  mat[25][25];
int  oper()
{
    int i,j;
    memset(mat,0,sizeof(mat));

    for(i=0;i<25;i++)mat[i][i]=1;
    for(i=1;i<25;i++)
        for(j=1;j<i;j++)
            mat[i][j]=mat[i-1][j-1]+mat[i-1][j]*(i-1);
    return 0;
}
int main()
{

    int times;


    long long sum=1;
    long long ans=0;
    oper();
    scanf("%d",&times);
    while(times--)
    {   sum=1;
        ans=0;
        int n,k;
        scanf("%d %d",&n,&k);
        int i;
        for(i=1;i<=k;i++)
            ans+=mat[n][i]-mat[n-1][i-1];
        for(i=1;i<=n;i++)
            sum*=i;
        printf("%.4lf\n",1.0*ans/sum);

    }

    return 0;
}








