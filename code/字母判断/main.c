#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char mat1[1000];
char mat2[1000];
int legal()
{
    int i;
    for(i=1;mat1[i];i++)
    {
        if(mat1[i]>='a' && mat1[i]<='z')return 0;
    }
    return 1;

}
int main()
{
    while(scanf(" %s",&mat1)!=EOF)
    {   memset(mat2,'\0',sizeof(mat2));
        if(legal())
        {
            int i;
            for(i=0;mat1[i];i++)
            {
                 if(mat1[i]>='a' && mat1[i]<='z')mat2[i]=mat1[i]+'A'-'a';
                 else mat2[i]=mat1[i]+'a'-'A';

            }
            printf("%s\n",mat2);
        }
        else printf("%s\n",mat1);

    }
    return 0;
}
