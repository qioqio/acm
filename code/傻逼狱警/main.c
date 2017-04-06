#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mat[1000];

void oper(int a)
{
    memset(mat,0,sizeof(mat));
    int i,j;
    for(i=1;i<=a;i++)
    {   j=i;
        while(j<=a)
        {
            mat[j]=!mat[j];
            j+=i;
        }
    }
    int ans=0;
    for(i=1;i<=a;i++)
        if(mat[i]!=0)ans++;
    printf("%d\n",ans);
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        scanf("%d",&m);
        oper(m);
    }
    return 0;
}
