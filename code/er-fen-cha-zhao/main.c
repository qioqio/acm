#include <stdio.h>

#include <stdlib.h>
    int mat[10];
void find(int x)
{
    int l=0;
    int r=9;
    int min=(l+r)/2;
    while(l<r)
    {    min=(l+r)/2;
        if(mat[min]>l)
        l=min-1;
        else   r=min;
    }
    if(mat[l]<x)
    printf("%d\n",mat[l]);
    else
        printf("%d\n",-1);
}
int main()
{

    mat[0]=10;
    mat[1]=9;
    mat[2]=8;
    mat[3]=7;
    mat[4]=6;
    mat[5]=5;
    mat[6]=4;
    mat[7]=3;
    mat[8]=2;
    mat[9]=1;
    int x=6;
    find(x);
    return 0;
}
