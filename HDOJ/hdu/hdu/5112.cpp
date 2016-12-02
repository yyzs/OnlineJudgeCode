#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 10000
#include "math.h"
#include "stdlib.h"
using namespace std;
struct node
{
    int t,x;
}node[MAX];
int cmp(struct node a,struct node b)
{
    if(a.t==b.t)
        return  a.x<b.x;
    return a.t<b.t;
}
int main()
{
    int cas=0;
    int t1,n,i,j;
    double max,temp;
    scanf("%d",&t1);
    while(t1--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&node[i].t,&node[i].x);
        sort(node,node+n,cmp);
        max=0;
        for(i=0;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                temp=fabs(node[i].x-node[j].x)/fabs(node[i].t-node[j].t);
                if(temp>max)
                     max=temp;
                else
                     break;
            }
        }
        cas++;
        printf("Case #%d: %.2f\n",cas,max);
    }
    return 0;
}

