#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    for(    i=1 ;    i<600   ;  i++     )
    {
        if(  i % 40  == 0)
        {
            if(  i %  13   == 0)
            {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
