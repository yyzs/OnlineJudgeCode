#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 40000
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
long long sum[MAX<<2],ago[MAX<<2],s[MAX<<2],dis[MAX<<2],ans[100010];
int vis[MAX];
int n,q;
int num,cdy;

struct node
{
  int beg,end,id;
}node[100010];

void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%I64d",&sum[rt]);
        ago[num]=s[num]=sum[rt];
        num++;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void slove()
{
    int i;
    num--;
    cdy=1;
    sort(s+1,s+num+1);
    for(i=1;i<=num;i++)
    {
        if(i==1)
        {
            dis[cdy]=s[i];
            cdy++;
            continue;
        }
        if(s[i]==s[i-1])
            continue;
        dis[cdy]=s[i];
        cdy++;
    }
    cdy--;
}

int cmp(struct node a,struct node b)
{
    return a.end<b.end;
}

void update(int x,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=0;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m)
         update(x,lson);
    if(x>m)
         update(x,rson);
    pushup(rt);
}

long long query(int L,int R,int l,int r,int rt)
{
    if(l>=L&&r<=R)
        return sum[rt];
    int m=(l+r)>>1;
    long long ans=0;
    if(L<=m)
        ans+=query(L,R,lson);
    if(R>m)
        ans+=query(L,R,rson);
    return ans;
}

void print()
{
    int i;
    for(i=1;i<=q;i++)
         printf("%I64d\n",ans[i]);
}

int main()
{
  int current,i,temp,t;
  scanf("%d",&t);
  while(t--)
  {
      memset(vis,-1,sizeof(vis));
      scanf("%d",&n);
      num=1;
      build(1,n,1);
      scanf("%d",&q);
      slove();
      for(i=1;i<=q;i++)
      {
          scanf("%d%d",&node[i].beg,&node[i].end);
          node[i].id=i;
      }
      sort(node+1,node+q+1,cmp);
      temp=1;
      for(i=1;i<=n;i++)
      {
          current=lower_bound(dis,dis+cdy+1,ago[i])-dis;
          if(vis[current]!=-1)
                 update(vis[current],1,n,1);
          vis[current]=i;
          while(node[temp].end<=i&&temp<=q)
          {
                 ans[node[temp].id]=query(node[temp].beg,node[temp].end,1,n,1);
                 temp++;
          }
          if(temp>q)
                 break;
      }
      print();
  }
  return 0;
}

