#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    edge *c=(*edge) a;
    edge *d=(*edge) b;
    if (c->aa==d->aa){
          if(c->a==d->a)
          {

              return c->b - c->b;//min > max



          }
        else {
            return c->a - c->a;//min > max
        }



    }else{
        return c->aa - d->aa;//min >max
    }
}
typedef struct edge
{
    int aa;
    int a;
    int b;
    char c[10];
    char v;
}e[100];
int main()
{
    int i;
    for(i=0;i<100;i++)
    {
        scanf("%d %d %d %s %c",&e[i].aa,&a,&b,c,&v);




    }
    qsort(e,100,sizeof(e[1]),cmp);
    return 0;
}
