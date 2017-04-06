#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mat1[300],mat2[300];
char ma1[300],ma2[300];
char ans[300];
int main(){

    while(scanf("%s  %s",mat1,mat2)!=EOF)
    {
        int x,y,n,m;
        x=strlen(mat1);
        y=strlen(mat2);
        for(n=0;n<x;n++)
        {
            ma1[n]=mat1[x-1-n];
        }
        ma1[x]='\0';
        for(m=0;m<y;m++)
        {
            ma2[m]=mat2[y-1-m];
        }
        ma2[y]='\0';
        if(x<y)
        {
            for(n=x;n<y;n++)
            {
                ma1[n]='A';
            }
            ma1[y]='\0';
        }
        if(y<x)
        {
            for(n=y;n<x;n++)
            {
                ma2[n]='A';
            }
            ma2[x]='\0';

        }

        int s=0;
        n=strlen(ma1);

        for(int i=0;i<n;i++)
        {
            ans[i]=ma1[i]+ma2[i]+s-'A';
            if(ans[i]>'z')
            {
                s=1;
                ans[i]-=26;
            }
            else s=0;

        }
        if(s==1)
            {
                ans[n]='B';
            }
        else ans[n]='A';
        int z;



    for(int i=n;i>=0;i--)
        {
            if(ans[i]=='A')
                n--;
            else
                break;
        }
       for(int i=n;i>=0;i--)
           printf("%c",ans[i]);
       printf("\n");
    }
	return 0;
}
