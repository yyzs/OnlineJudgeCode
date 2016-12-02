#include "stdio.h"
#include "algorithm"
#include "queue"
#include "string.h"
#define MAX 1000010
using namespace std;
int vis[MAX],vis1[MAX];
struct node
{
    int l,r;
    int id;
} node[MAX];
struct node1
{
    int r;
    int id;
    bool operator<(const node1& a)const
    {
        return r>a.r;
    }
    node1(int _r,int _id):r(_r),id(_id) {}
    node1() {}
};
int cmp(struct node a,struct node b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}
int main()
{
    int t,n,m;
    int ans=0;
    int judge=0;
    scanf("%d",&t);
    while(t--)
    {
        priority_queue<node1> q;
        memset(vis,0,sizeof(vis));
        memset(vis1,0,sizeof(vis1));
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&node[i].l);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&node[i].r);
            node[i].id=i+1;
        }
        sort(node,node+n,cmp);
        ans=0;
        int j=0;
        while(1)
        {
            while(j<n&&node[j].l<=ans)
            {
                q.push(node1(node[j].r,node[j].id));
             //   printf("id:%d\n",node[j].id);
                j++;
            }
            judge=0;
            while(!q.empty())
            {
                node1 temp=q.top();
                q.pop();
                if(temp.r>=ans)
                {
                    ans++;
                    vis1[ans]=temp.id;
                    vis[temp.id]=1;
                    judge=1;
                    break;
                }
            }
            if(!judge)
                break;
        }
        judge=0;
        printf("%d\n",ans);
        for(int i=1; i<=ans; i++)
        {
            if(!judge)
                printf("%d",vis1[i]);
            else
                printf(" %d",vis1[i]);
            judge=1;
        }
        for(int i=1; i<=n; i++)
        {
            if(vis[i])
                continue;
            if(judge)
                printf(" %d",i);
            else
                printf("%d",i);
            judge=1;
        }
        puts("");
    }
    return 0;
}

