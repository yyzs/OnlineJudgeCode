#include "algorithm"
#include "stdio.h"
#include "string.h"
#define MAX 131
using namespace std;
struct node
{
    int id;
    int t,w;
    int pla;
}node[MAX];
int cmp(struct node a,struct node b)
{
    if(a.w==b.w)
        return a.t<b.t;
    return a.w>b.w;
}
int main()
{
    int n,m;
    int g,s,c;
    int h,mm,ss,i;
    while(scanf("%d%d%d%d%d",&n,&g,&s,&c,&m)==5,n+g+s+c+m)
    {
         m-=1;
         for(i=0;i<n;i++)
              {scanf("%d %02d:%02d:%02d",&node[i].w,&h,&mm,&ss);
                node[i].t=h*3600+mm*60+ss;
                node[i].id=i;
                }
        sort(node,node+n,cmp);
        for(i=0;i<n;i++)
               {
                    if(node[i].id==m)
                    {
                         if(i<=g-1)
                                puts("Accepted today? I've got a golden medal :)");
                        else
                                if(i<=g+s-1)
                                    puts("Accepted today? I've got a silver medal :)");
                        else
                                if(i<=g+s+c-1)
                                    puts("Accepted today? I've got a copper medal :)");
                        else
                                puts("Accepted today? I've got an honor mentioned :)");
                        break;
                    }
               }
    }
}

