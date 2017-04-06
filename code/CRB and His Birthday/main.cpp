#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a,int b,int c)
{

    if(a>=b && a>=c)return a;
    if(b>=a && b>=c)return b;
    return c;
}
 int mat[1001][2001];
 int mat2[1001][3];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

    int times;
    scanf("%d",&times);
    while(times--)
    {
        memset(mat,0,sizeof(mat));
        memset(mat2,0,sizeof(mat2));

        int n,m;
        scanf("%d %d",&m,&n);
        int i,j,k;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d",&mat2[i][0],&mat2[i][1],&mat2[i][2]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=0;j<m+1;j++)
            {
                if(j<mat[i][0])
                    mat[i][j]=mat[i-1][j];
//                    system("pause");
//                printf("%%%% %d %%%%\n",mat[i][j]);}
                else
                    mat[i][j]=max(mat[i-1][j],mat[i-1][j-mat2[i][0]]+mat2[i][1]+mat2[i][2],mat[i][j-mat2[i][0]]+mat2[i][1]);
//                    system("pause");
//                printf("%%%% %d %%%%\n",mat[i][j]);}
            }
        }

    int ans=0;
    for(i=0;i<=m;i++)
    {
        if(ans<=mat[n][i])
            ans=mat[n][i];
    }
    printf("%d\n",ans);
    }
	return 0;
}
