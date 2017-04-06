#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mat1[100000];
int mat2[100000];

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
#endif
    int times;
    scanf("%d",&times);
    while(times--)
    {
        int n;
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++)
            scanf("%d",&mat1[i]);
        for(i=0;i<n-1;i++)
            scanf("%d",&mat2[i]);
        for(i=0;i<n-1;i++)
            mat1[n-1]=mat1[n-1]^mat1[i]^mat2[i];
        printf("Team %08d didn't sign in!\n",mat1[n-1]);
    }
    return 0;
}
