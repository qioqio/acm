#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char  mat[1000000];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);

#endif
int flag=0;

    while(gets(mat)!=NULL)
    {

        int i;
        for(i=0;mat[i];i++)
        {
            if(mat[i]=='"' && flag==0)
            {printf("\`\`");flag=1;}
            else if(mat[i]=='"' && flag==1)
            {printf("\'\'");flag=0;}
            else printf("%c",mat[i]);

        }
        printf("\n");
    }


    return 0;
}
