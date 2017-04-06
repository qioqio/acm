#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int times;

    long long a,b;
    scanf("%d",&times);
    while(times--)
    {
        scanf("%lld %lld",&a,&b);


        long long ans=a;
        while(b--)
        {
           loop: if((ans%4==0&&ans%100!=0) ||ans%400==0)
                        {
                            ans++;
                             continue;


                        }

            else
            {ans++;
            goto loop;
            }



        }
        printf("%lld\n",ans-1);



















    }
    return 0;
}
