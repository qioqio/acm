#include  <stdio.h>
int i,j,a[17]={0,1},l,r;
void oper2()
{

    if(j<=i)
     { r=a[j];
       a[j]=l+r;
       l=r;
       printf("%5d",a[j]);
       j++;
     }
}
void oper()
{   j=1;

    if(i<=16)
   {
    oper2();oper2();oper2();oper2();
    oper2();oper2();oper2();oper2();
    oper2();oper2();oper2();oper2();
    oper2();oper2();oper2();oper2();
    printf("\n");
    i++;
   }j=1;
}
int  main()
{
   i=1;
    oper();oper();oper();oper();
    oper();oper();oper();oper();
    oper();oper();oper();oper();
    oper();oper();oper();oper();
    return 0;
}
