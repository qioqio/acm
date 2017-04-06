#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  leng 60000008

int m(int i)
{   if(i==0)return 1;
    if(i==1)return 10;
    if(i==2)return 100;
    if(i==3)return 1000;
    if(i==4)return 10000;
    if(i==5)return 100000;
    if(i==6)return 1000000;
    if(i==7)return 10000000;
    if(i==8)return 100000000;
    if(i==9)return 1000000000;
    return 0;

}
int mat[leng];
void oper(int j)
{
    int a;
    int mat2[7];
    mat2[6]=j%1000000;
    mat2[5]=(j/10)%100000;
    mat2[4]=(j/100)%10000;
    mat2[3]=(j/1000)%1000;
    mat2[2]=(j/10000)%100;
    mat2[1]=(j/100000)%10;
    a=j/1000000;
    /*move*/if(a!=1)mat[(a-1)*1000000+j%1000000]=1;
    if(a!=6)mat[(a+1)*1000000+j%1000000]=1;

    /*up*/mat[j+(m(6-a)%10)]=1;
    /*down*/mat[j-(m(6-a)%10)]=1;
   if(a!=1) mat[j-(mat2[6-a]*m(6-a))-(mat2[6-a-1]*m(6-a-1))+(mat2[6-a]*m(6-a-1))+(mat2[6-a-1]*m(6-a))]=1;
    if(a!=6)mat[j-(mat2[6-a]*m(6-a))-(mat2[6-a+1]*m(6-a+1))+(mat2[6-a]*m(6-a+1))+(mat2[6-a+1]*m(6-a))]=1;
}
int main()
{
    int times;
    scanf("%d",&times);
    while(times--)
    {

        int a;int b;
        scanf("%d %d",&a,&b);
        int i,j;
        memset(mat,0,sizeof(mat));
        mat[a+1000000]=1;
        i=0;
        for(j=0;j<leng;j++)
            {   i++;
                if(mat[j]!=0 && (j%1000000)==b){printf("%d\n",i);break;}
                if(mat[j]!=0)
                    oper(j);
                mat[j]=0;
            }
    }
    return 0;
}


















