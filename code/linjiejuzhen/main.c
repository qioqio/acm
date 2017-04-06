#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int father[30];
int from[30];
int to[30];
int v[30];
char s[10000];

int find(int x)
{
    if(x==father[x]) return x;
    return find(father[x]);
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
#endif


    int times;
    scanf("%d",&times);
    while(times--)
    {
        memset(v,0,sizeof(v));
        memset(from,0,sizeof(from));
        memset(to,0,sizeof(to));

        int n;
        scanf("%d",&n);

        int i;
        int x=0,y=0,z=0;
        for(i=0;i<N;i++)
        {father[i]=i;}
        for(i=0;i<n;i++)
        {
            scanf(" %s",s);
            x=s[0]-'a';
            y=s[strlen(s)-1]-'a';
            to[x]++;
            from[y]++;
            father[x]=father[y]=find(x);
            v[x]=v[y]=1;

        }
        int r=0;
        for(i=0;i<N;i++)
        {
            if(i==father[i] && v[i])
                r++;
        }
        if(r>1){printf("The door cannot be opened.\n");continue;}
        x=y=z=0;
        for(i=0;i<N;i++)
        {   if(v[i] && from[i]!=to[i])
            {if(from[i]==to[i]+1)x++;
            else if(from[i]==to[i]-1)y++;
            else z++;}

        }

        if(z){printf("The door cannot be opened.\n");continue;}
        if((x==y && y==1)||(x==0 && y==0)){printf("Ordering is possible.\n");continue;}
        else printf("The door cannot be opened.\n");


    }
    return 0;



}
