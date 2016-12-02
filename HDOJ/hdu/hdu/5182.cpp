#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 1000
using namespace std;
struct node
{
    int a,b,c;
    int id;
}node[MAX];
int cmp(struct node x,struct node y)
{
    if(x.c==y.c&&x.b==y.b)
         return x.id<y.id;
    if(x.c==y.c)
         return x.b<y.b;
    return x.c>y.c;
}
int main()
{
    int n,i,j;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {scanf("%d%d",&node[i].a,&node[i].b);
         node[i].id=i;
         node[i].c=node[i].a-node[i].b;
        }
        sort(node,node+n,cmp);
        for(i=0;i<n;i++)
        {
            if(!i)
                printf("%d",node[i].id);
            else
                printf(" %d",node[i].id);
        }
        printf("\n");
    }
    return 0;
}

