#include "stdio.h"
#include "string.h"
#include <queue>
#include  <algorithm>
using namespace std;
struct node
{int pos,dis;
};
struct cmp{
    bool operator () (node a,node b){
        if(a.pos!=b.pos)
            return a.pos>b.pos;
        else
            return a.dis>b.dis;
    }
};
int main()
{priority_queue<struct node,vector<node>,cmp> s;
  struct node t;
  int t1,n,car,flag,res,i;
  scanf("%d",&t1);
  while(t1--)
  {scanf("%d",&n);
    for(i=0;i<n;i++)
            {scanf("%d%d",&t.pos,&t.dis);
              s.push(t);
              }
    flag=1;
    car=-1;
    while(!s.empty())
    {t=s.top();
      s.pop();
      if(flag==1)
      {flag=0;
        t.pos+=t.dis;
        s.push(t);
        }
       else
          flag=1;
        res=t.pos;
        }
     printf("%d\n",res);
     }
     return 0;
    }

