#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp ( const void *a , const void *b )
{ return *(int *)a - *(int *)b; }

using namespace std;
int mat1[100001];
int mat2[100001];
int mat[200005];
int main(){

    memset(mat1,0,sizeof(mat1));
    memset(mat2,0,sizeof(mat2));
    memset(mat,0,sizeof(mat));
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&mat1[i]);
        scanf("%d",&mat[i]);

    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&mat2[i]);
        scanf("%d",&mat[i+n]);
    }
    qsort(mat,200005,sizeof(mat[0]),cmp);
    int z1=mat[(n+m)/2];
    int z2=mat[(n+m)/2+1];
    long long  sum1=0;
    long long  sum2=0;
    for(int i=0;i<n;i++)
    {
       if(mat1[i]<z1)
        sum1+=z1-mat1[i];
       if(mat1[i]<z2)
        sum2+=z2-mat1[i];

    }
    for(int i=0;i<m;i++)
    {
        if(mat2[i]<z1)
        sum1+=z1-mat1[i];
       if(mat2[i]<z2)
        sum2+=z2-mat1[i];
    }
    long long  ans=sum1>sum2? sum2: sum1;

    printf("%lld\n",ans);






	return 0;
}
