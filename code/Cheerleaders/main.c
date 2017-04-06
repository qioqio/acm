#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mod 1000007

int  mat[505][505];
void oper2()
{
    int i,j;
    memset(mat,0,sizeof(mat));
    for(i=0;i<=405;i++)
        {mat[i][0]=1;mat[i][i]=1;}
    for(i=1;i<=405;i++)
        for(j=1;j<i;j++)
            mat[i][j]=(mat[i-1][j-1]+mat[i-1][j])%mod;

}

int f(int a,int b)
{
    return mat[a][b];
}
int oper(int a,int b,int c)
{ int ans=0;

    ans+=mat[a*b][c]%mod;
    ans-=(2*mat[a*b-a][c]+mod)%mod;
    ans-=(2*mat[a*b-b][c]+mod)%mod;

    ans+=4*mat[a*b-a-b+1][c]%mod;
    ans+=mat[a*b-2*a][c]%mod;
    ans+=mat[a*b-2*b][c]%mod;

    ans-=(2*mat[a*b-2*a-b+2][c]+mod)%mod;
    ans-=(2*mat[a*b-a-2*b+2][c]+mod)%mod;

    ans+=mat[a*b-2*b-2*a+4][c]%mod;


   /* int t1,t2,t3,t4;
    t1=(2*mat[(n-1)*m][k]+2*mat[n*(m-1)][k])%mod;
    t2=(4*mat[(n-1)*(m-1)][k]+mat[(n-2)*m][k]+mat[n*(m-2)][k])%mod;
    t3=(2*mat[(n-2)*(m-1)][k]+2*mat[(n-1)*(m-2)][k])%mod;
    t4=mat[(n-2)*(m-2)][k];*/


    return (ans+mod)%mod;

}
int main()
{

    int times;
    scanf("%d",&times);
    int i,j;
    oper2();
    for(i=1;i<=times;i++)
      {
        int m,n,k;
        scanf("%d %d %d",&m,&n,&k);
        printf("Case %d: %d\n",i,oper(m,n,k));
      }

    return 0;
}



