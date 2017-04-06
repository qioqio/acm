#include <iostream>
#include<stdio.h>
using namespace std;
char mat[20];
int main()
{
    int times;
    scanf("%d",&times);
    for( int i=0;i<times;i++)
    {
        scanf("%s",mat);
        if(mat[0]=='3'&&mat[1]=='3')
            printf("He/She is from Zhejiang,");
        else if(mat[0]=='1'&&mat[1]=='1')
            printf("He/She is from Beijing,");
        else if(mat[0]=='7'&&mat[1]=='1')
            printf("He/She is from Taiwan,");
        else if(mat[0]=='8'&&mat[1]=='1')
            printf("He/She is from Hong Kong,");
        else if(mat[0]=='8'&&mat[1]=='2')
            printf("He/She is from Macao,");
        else if(mat[0]=='5'&&mat[1]=='4')
            printf("He/She is from Tibet,");
        else if(mat[0]=='2'&&mat[1]=='1')
            printf("He/She is from Liaoning,");
        else if(mat[0]=='3'&&mat[1]=='1')
            printf("He/She is from Shanghai,");
        printf("and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",mat[10],mat[11],mat[12],mat[13],mat[6],mat[7],mat[8],mat[9]);
    }

    return 0;
}
