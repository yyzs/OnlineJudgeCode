#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "queue"
#define MAX 10010
using namespace std;
int bin[MAX];
int head[MAX*2];
int hash[MAX];
int cnt;
char s[20];
int n,m;
struct node
{
    int a,b;
}node[MAX*2];
struct edge
{
    int next,v;
}e[MAX*2];
int find(int x)
{
    int r=x;
    while(r!=bin[r])
          r=bin[r];
    return r;
}
void merge(int a,int b)
{
    bin[a]=b;
}
void addedge(int u,int v)
{
    e[cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
int main()
{
    int a,b,i,j;
    int ok1,ok2;
    int d=0;
    int u,v;
    int c;
    int t=0;
    int num;
    while(scanf("%d%d",&n,&m)==2)
    {
        cnt=0;
        num=n;
        memset(head,-1,sizeof(head));
        memset(hash,0,sizeof(hash));
        for(i=0;i<n;i++)
              bin[i]=i;
        t=0;
        while(m--)
        {
            scanf("%d%s%d",&a,s,&b);
            int fa=find(a);
            int fb=find(b);
            if(strcmp(s,"=")==0)
                {
                 if(fa!=fb)
                         {merge(fa,fb);
                          num--;
                         }
                }
            else
               if(strcmp(s,">")==0)
                {
                 node[t].a=a;
                 node[t].b=b;
                 t++;
                }
            else
              if(strcmp(s,"<")==0)
                {
                 node[t].a=b;
                 node[t].b=a;
                 t++;
                }
        }
        ok1=0;ok2=0;
        for(i=0;i<t;i++)
        {
            int fa=find(node[i].a);
            int fb=find(node[i].b);
            if(fa==fb)
                ok1=1;
            addedge(fa,fb);
            hash[fb]++;
        }
        priority_queue<int> que;
        d=0;
        for(i=0;i<n;i++)
        {
            if(!hash[i]&&i==find(i))
                  {que.push(i);
                   d++;
                  }
        }
        if(d>1)
             ok1=1;
        d=0;
        while(!que.empty())
        {
            u=que.top();
            que.pop();
            d++;
            if(!que.empty())
               ok1=1;
            //c=0;
             for(i=head[u];i!=-1;i=e[i].next)
            {
                v=e[i].v;
                hash[v]--;
                if(!hash[v])
                    {//printf("v:%d\n",v);
                     que.push(v);
                    // c++;
                    }
            }
            //if(c>1)
              //  ok1=1;
        }
        if(d!=num)
            ok2=1;
        if(ok2)
            puts("CONFLICT");
        else
            if(ok1)
              puts("UNCERTAIN");
        else
            puts("OK");
    }
    return 0;
}

