#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int mat[5000][4];
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    float g;
    scanf("%f",&g);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d %d %d",&mat[i][0],&mat[i][1],&mat[i][2],&mat[i][3]);
    float ans=a*b;
    for(int i=0;i<n;i++)
    {

        printf("%.2f++++++++++++\n",ans);
        ans-=3.145*mat[i][3]*mat[i][3];
    }

    printf("%.2f\n",ans);




    return 0;
}
