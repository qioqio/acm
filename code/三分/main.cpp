#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

double mat[15001][2];
int number;
double cal(double x)
{
    double  ans=0;
    for(int i=0;i<number;i++)
        ans+=fabs(mat[i][0]-x)*mat[i][1];
    return ans;
}
int main(){


    scanf("%d",&number);
    memset(mat,0,sizeof(mat));

    for(int i=0;i<number;i++)
    {
        scanf("%d %d",&mat[i][0],&mat[i][1]);
    }
    double l=0,r=50000,mid,midmid;
    while(l+0.0000001<r)
    {
            mid=(l+r)/2;
            midmid=(mid+l)/2;
            double cmid=cal(mid);
            double cmidmid=cal(midmid);
            if(cmid>cmidmid)
                r=mid;
            else l=midmid;
    }
    printf("%.5f\n",l);



	return 0;
}
