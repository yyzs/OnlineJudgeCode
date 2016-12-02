#include "stdio.h"
#include "string.h"
#include "vector"
#define MAX 20000000
using namespace std;
int v[1300000];
bool vis[MAX];
int temp;
bool dis[150];
void init()
{
    temp=0;
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    for(int i=2;i<MAX;i++)
    {
        if(vis[i]==true)
               continue;
        v[temp++]=i;
      //  printf("%d\n",i);
        for(int j=i+i;j<MAX;j+=i)
                vis[j]=true;
    }
    for(int i=1;i<temp;i++)
          if(v[i]-v[i-1]<150)
              dis[v[i]-v[i-1]]=true;
}
int slove(int a,int b)
{
    if(!dis[b-a])
           return -1;
    for(int i=1;i<temp;i++)
        if(v[i-1]>=a&&v[i]-v[i-1]==b-a)
             return v[i-1]-a;
    return -1;
}
int main()
{
    int cas=0;
    int t;
    int a,b;
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a>b)
             a^=b^=a^=b;
        cas++;
        printf("Case %d: %d\n",cas,slove(a,b));
    }
    return 0;
}

