#include "stdio.h"
#include "string.h"
#include "queue"
#include "algorithm"
#define INF 100000000
using namespace std;
int vis[10001];
int numn,numm;
struct node
{
    char a[5];
}n,m;
int getsum(struct node a)
{
    int sum=(a.a[0]-'0')*1000+(a.a[1]-'0')*100+(a.a[2]-'0')*10+a.a[3]-'0';
    return sum;
}
void bfs()
{
    int i,j;
    queue<node> que;
    que.push(n);
    for(i=0;i<10000;i++)
         vis[i]=INF;
    vis[numn]=0;
    while(!que.empty())
    {
        node q=que.front();
        que.pop();
        node now;
        int current=getsum(q);
        if(current==numm)
            break;
        for(i=0;i<4;i++)
        {
           strcpy(now.a,q.a);
           int temp;
           if(now.a[i]!='9')   now.a[i]=now.a[i]+1;
           else                now.a[i]='1';
           //printf("%s\n",now.a);
           temp=getsum(now);
           //printf("%d\n",vis[temp]);
           if(vis[temp]==INF)
           {
               que.push(now);
               vis[temp]=vis[current]+1;
           }
           strcpy(now.a,q.a);
           if(now.a[i]!='1')   now.a[i]=now.a[i]-1;
           else                now.a[i]='9';
           temp=getsum(now);
           if(vis[temp]==INF)
           {
               que.push(now);
               vis[temp]=vis[current]+1;
           }
        }
        for(i=0;i<3;i++)
        {
            int temp;
            strcpy(now.a,q.a);
            char c;
            c=now.a[i];
            now.a[i]=now.a[i+1];
            now.a[i+1]=c;
            temp=getsum(now);
            //printf("%s\n",now.a);
            if(vis[temp]==INF)
            {
                que.push(now);
                vis[temp]=vis[current]+1;
            }
        }
    }
    printf("%d\n",vis[numm]);
}
void debug()
{
    printf("%d %d\n",numn,numm);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%s%s",n.a,m.a);
       numn=getsum(n);
       numm=getsum(m);
       bfs();
    }
    return 0;
}

