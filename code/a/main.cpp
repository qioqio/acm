#include <stdio.h>
#include <stdlib.h>

int numbers[501] = { };

int comp(const void * a, const void * b){
    { return *(int *)a - *(int *)b; }

}
int main()
{
  //  printf("%d\n",numbers[500]);
int i;
for(i=0;i<500;i++)
{
    numbers[i]=i;

}
qsort(numbers,500,sizeof(numbers[0]),comp);

for(i=0;i<500;i++)
{
    printf("%d\n",numbers[i]);

}





for(i=0;i<500;i++)
{
    numbers[i]=1000-i;

}
qsort(numbers,500,sizeof(numbers[0]),comp);

for(i=0;i<500;i++)
{
    printf("%d\n",numbers[i]);

}
system("pause");
return 0;
}
