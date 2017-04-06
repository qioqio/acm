#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;



int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
    int n,k;
    int mat[5002];
    memset(mat,0,sizeof(mat));
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&mat[i]);
    }
    int times;
    scanf("%d",&times);
    while(times--)
    {
        int sum;
        scanf("%d",&sum);
        int ans=0;

        for(int i=n-1;i>=0;i--)
        {

            ans+=sum/(mat[i]);
            sum%=(mat[i]);
        }
        if(ans>k||sum!=0)
            printf("%d\n",-1);
        else printf("%d\n",ans);




    }

    return 0;
}
