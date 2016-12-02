#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 200100
using namespace std;
struct node
{
    int x,cur;
}node[MAX];
int cmp(struct node a,struct node b)
{
    return a.x<b.x;
}
int main()
{
    int ans,temp;
    int n,i,j,t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        temp=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            node[temp].x=x;
            node[temp++].cur=1;
            node[temp].x=y+1;
            node[temp++].cur=-1;
        }
        sort(node,node+temp,cmp);
        ans=0;
        int res=0;
        for(i=0;i<temp;)
        {
            for(j=i;j<temp&&node[j].x==node[i].x;j++)
            {
                res+=node[j].cur;
            }
            if(res>ans)
                ans=res;
            i=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}

