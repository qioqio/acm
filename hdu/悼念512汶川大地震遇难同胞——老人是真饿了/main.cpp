#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=1005;

struct mi
{
    int p,h;


}mat[maxn];
int cmp(mi a,mi b)
{
    return a.p<b.p;
}
int main()
{
    int times;
    scanf("%d",&times);

    while(times--)
    {
        memset(mat,0,sizeof(mat));

        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&mat[i].p,&mat[i].h);
        }
        sort(mat,mat+m,cmp);
        float sum=0;
        int i=0;
        while(n>=mat[i].p*mat[i].h)
        {
            sum+=mat[i].h;
            n-=mat[i].p*mat[i].h;
            i++;
        }
        if(n!=0)
        {
            sum+=1.0*n/mat[i].p;

        }
        printf("%.2f\n",sum);
    }


    return 0;
}
