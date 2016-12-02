#include "stdio.h"
#include "string.h"
#include <queue>
#define Maxn 100001
using namespace std;
int vis[Maxn];
int step[Maxn];//记录每一步位置所走的步数
queue <int> q;
int bfs(int n,int k)
{int head,next,i;
 q.push(n);
 step[n]=0;
 vis[n]=1;
 while(!q.empty())
 {head=q.front();
  q.pop();
  for(i=0;i<3;i++)
  {if(i==0)
            next=head-1;
   else  if(i==1)  next=head+1;
   else     next=head*2;
   if(next<0||next>=Maxn)  continue;
   if(!vis[next])
           {q.push(next);
            step[next]=step[head]+1;
            vis[next]=1;
            }
    if(next==k)
             return step[next];
     }
    }
}
int main()
{int n,k;
 while(scanf("%d%d",&n,&k)==2)
 {memset(step,0,sizeof(step));
  memset(vis,0,sizeof(vis));
  while(!q.empty())
            q.pop();
  if(n>=k)
            printf("%d\n",n-k);
  else
            printf("%d\n",bfs(n,k));
  }
  return 0;
}

