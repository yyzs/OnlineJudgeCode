#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "vector"
#define MAX 200010
using namespace std;
vector<int> v;
int a[MAX];
int d[MAX][20];
void RMQ_init(int n)
{
    for(int i=0; i<n; i++)
    {
        d[i][0]=a[i];
    }
    for(int j=1; (1<<j)<=n; j++)
        for(int i=0; i+(1<<j)-1<n; i++)
        {
            d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
        }
}
int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1)  k++;
    return max(d[L][k],d[R-(1<<k)+1][k]);
}
int main()
{
    int sum;
    int n,k;
    int maxnum=0;
    while(scanf("%d%d",&n,&k)==2)
    {
        if(n<0&&k<0)
             break;
        sum=0;
        maxnum=0;
        for(int i=0;i<n;i++)
              {scanf("%d",&a[i]);
                sum+=a[i];
                if(a[i]>maxnum)
                       maxnum=a[i];
                }
        if(sum<=k)
        {
               puts("-1");
               continue;
        }
        RMQ_init(n);
        for(int ans=1;ans<=n;ans++)
        {
             if(ans==n)
             {
                  printf("%d\n",ans);
                  break;
             }
              if(ans*maxnum<=k)
                      continue;
              int temp=0;
              for(int j=0;j+n/ans-1<n-n%ans;j+=n/ans)
                      temp=temp+RMQ(j,j+n/ans-1);
             if(temp>k)
             {
                     printf("%d\n",ans);
                     break;
             }
        }
    }
    return 0;
}

