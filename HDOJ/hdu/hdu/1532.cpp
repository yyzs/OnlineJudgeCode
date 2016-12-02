#include "stdio.h"
#include "string.h"
#include <queue>
#include "algorithm"
#define INF 100000000
#define MAX 220
using namespace std;
int p[MAX];
int flow[MAX][MAX];
int a[MAX];
int cap[MAX][MAX];
int main()
{
  int n,m;
  int si,ei,c;
  int s,t;
  int f;
  while(scanf("%d%d",&n,&m)==2)
  {
      memset(cap,0,sizeof(cap));
     while(n--)
     {
       scanf("%d%d%d",&si,&ei,&c);
       cap[si][ei]+=c;
     }
     s=1;
     t=m;
     f=0;
     queue<int> q;
     memset(p,-1,sizeof(p));
     memset(flow,0,sizeof(flow));
     for(;;)
     {  memset(a,0,sizeof(a));
        a[s]=INF;
        q.push(s);
       while(!q.empty())
         {
          int u=q.front();
          q.pop();
          for(int v=1;v<=m;v++)
             if(!a[v]&&cap[u][v]>flow[u][v])
             {
              p[v]=u;q.push(v);
              a[v]=a[u]<(cap[u][v]-flow[u][v])?a[u]:cap[u][v]-flow[u][v];
              }
           }
       if(a[t]==0)
            break;
       for(int u=t;u!=s;u=p[u])
           {
             flow[p[u]][u]+=a[t];
             flow[u][p[u]]-=a[t];
            }
        f+=a[t];
      }
      printf("%d\n",f);
  }
  return 0;
}

