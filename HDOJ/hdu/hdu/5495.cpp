#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 100010
using namespace std;
int a[MAX],b[MAX];
int g1[MAX],g2[MAX];
int vis1[MAX],vis2[MAX];
int main()
{
        int t,n;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                for(int i=1;i<=n;i++)
                        {scanf("%d",&a[i]);
                         g1[a[i]]=i;
                         }
                for(int i=1;i<=n;i++)
                        {scanf("%d",&b[i]);
                         g2[b[i]]=i;
                         }
                memset(vis1,0,sizeof(vis1));
                memset(vis2,0,sizeof(vis2));
                int ans=0;
                for(int i=1;i<=n;i++)
                {
                        if(vis1[i])
                                continue;
                        int temp=i;
                        int now=0;
                        while(!vis1[temp])
                        {
                                vis1[temp]=1;
                                temp=b[temp];
                                temp=g1[temp];
                                now++;
                        }
                        if(now==1)
                                ans+=1;
                        else
                                ans+=now-1;
                }
                printf("%d\n",ans);
        }
        return 0;
}

