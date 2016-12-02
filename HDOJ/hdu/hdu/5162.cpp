#include "stdio.h"
#include "string.h"
#include "algorithm"
const int MAXN=10000;
using namespace std;
struct node
{
    int a,b,c;
    int id;
    int max;
    int rank;
}node[MAXN];
int maxnum(int a,int b,int c)
{
    if(a<b)
        a^=b^=a^=b;
    if(a<c)
        a^=c^=a^=c;
    return a;
}
int cmp(struct node a,struct node b)
{
    return  a.max>b.max;
}
int cmp1(struct node a,struct node b)
{
    return a.id<b.id;
}
int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            {scanf("%d%d%d",&node[i].a,&node[i].b,&node[i].c);
             node[i].max=maxnum(node[i].a,node[i].b,node[i].c);
             node[i].id=i;
            }
        sort(node,node+n,cmp);
        for(i=0;i<n;i++)
            node[i].rank=i+1;
        sort(node,node+n,cmp1);
        for(i=0;i<n;i++)
        {
            if(i)
                printf(" %d",node[i].rank);
            else
                printf("%d",node[i].rank);
        }
        printf("\n");
    }
    return 0;
}

