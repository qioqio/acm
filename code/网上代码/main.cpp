#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30


int in[N],out[N],father[N],visited[N];

int find(int x)
{
    if(x==father[x]) return x;
    return find(father[x]);
}

int main()
{
    int test,i,n;
    char s[1001];
    scanf("%d",&test);
    while(test--)
    {   scanf("%d",&n);
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(visited,false,sizeof(visited));
        for(i=0;i<N;i++) father[i]=i;
        int x,y;
        for(i=0;i<n;i++)
        {
            scanf(" %s",s);
            x=s[0]-'a';
            y=s[strlen(s)-1]-'a';
            out[x]++;
            in[y]++;
            father[x]=father[y]=find(x);
            visited[x]=visited[y]=true;
        }
        int r=0;
        for(i=0;i<N;i++)
        {
            if(visited[i]&&i==father[i])
            {
                r++;
            }
        }
        if(r>1)
        {printf("The door cannot be opened.\n");continue;}
        bool flag=false;int z;
        x=0;y=0;z=0;
        for(i=0;i<N;i++)
        {
            if(visited[i]&&in[i]!=out[i])
            {
                if(in[i]==out[i]+1)
                {
                    x++;
                }
                else if(in[i]+1==out[i])
                {
                    y++;
                }
                else z++;
            }
        }
        if(z){printf("The door cannot be opened.\n");continue;}
        if((x==y && y==1)||(x==0 && y==0)){printf("Ordering is possible.\n");continue;}
        else printf("The door cannot be opened.\n");

    }
    return 0;
}
