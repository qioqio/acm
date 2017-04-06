#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int mat[134];
bool cmp(int  a,int  b)
{
    if(a>b) return 1;
    else return 0;
}
int main()
{
    int n,g,s,c,m;
    scanf("%d %d %d %d %d",&n,&g,&s,&c,&m);
    while(n!=0)
    {
        for(int i=0;i<n;i++)
        {
            int x,y,z,t;
            scanf("%d %d:%d:%d",&t,&x,&y,&z);
           // printf("%%%%%%%%%d %d:%d:%d\n",t,x,y,z);
            mat[i]=t*100000-(x*3600+y*60+z);
        }
        int num=mat[m-1];
        sort(mat,mat+n,cmp);
        if(num>=mat[g-1])
        {
            printf("Accepted today? I've got a golden medal :)\n");
        }
        else if(num>=mat[g+s-1])
        {
            printf("Accepted today? I've got a silver medal :)\n");
        }
        else if(num>=mat[g+s+c-1])
        {
            printf("Accepted today? I've got a copper medal :)\n");
        }
        else printf("Accepted today? I've got an honor mentioned :)\n");
        scanf("%d %d %d %d %d",&n,&g,&s,&c,&m);
    }
    return 0;
}
