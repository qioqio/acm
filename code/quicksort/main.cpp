#include <iostream>
#include<stdio.h>
using namespace std;
const int n=10;    int mat[n];
int sort(int a,int b)
{
    int temp=mat[a];
    int l=a;
    int r=b;
    while(l<r)
    {
        while(l<r&&mat[r]>temp)
            r--;
        mat[l]=mat[r];
        while(l<r&&mat[l]<temp)
            l++;
        mat[r]=mat[l];

    }
    mat[l]=temp;
    return l;
}
void quicksort(int a,int b)
{
    if(a>=b-1)return;
    int x=sort(a, b);
    quicksort(a,x-1);
    quicksort(x+1,b);

}

int main()
{

    for(int i=0;i<n;i++)
    {
        mat[i]=n-i;
    }
    for(int i=0;i<n;i++)
    {


        printf("%d+++++++\n",mat[i]);
    }
    quicksort(0,9);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",mat[i]);
    }


    return 0;
}
