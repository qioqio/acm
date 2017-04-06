#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
//
        int mat[103][3];
//    int ans[103][3];
//
//    char name[102][50];


    int numbers;
    scanf("%d",&numbers);
    for(int i=0;i<numbers;i++)
    {
       int times;
       scanf("%d",&times);
       scanf("%s",name[i]);
       while(times--)
           {int a,b,c;
           scanf("%d-%d-%d",&a,&b,&c);
           if(a==b&&b==c)mat[i][0]++;
           else if(a>b && b>c)mat[i][1]++;
           else mat[i][2]++;
           }
    }





    return 0;
}
