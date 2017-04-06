#include <stdio.h>
#include <stdlib.h>
int oper(int  n)
{
    if(n==1)return 1;
    else return n*oper(n-1);

}
int main()
{
    printf("n e\n- -----------\n0 1\n");
    int   n=1;
    double  ans=1;
    int j=1;
    for(n=1;n<10;n++)
    {

        ans+=(double)1/(double)oper(n);
        printf("%d %g\n",j++,ans);
    }
    return 0;
}
