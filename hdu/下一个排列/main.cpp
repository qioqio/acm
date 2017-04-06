#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
bool com(int a,int b)
{
    return a>b;

}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d %d %d\n",n&m,n|m,n^m);


    return 0;
}
