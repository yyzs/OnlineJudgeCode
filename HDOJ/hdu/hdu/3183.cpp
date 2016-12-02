#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "vector"
#define MAX 200010
using namespace std;
vector<int> v;
int a[MAX];
char s[MAX];
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
            d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
        }
}
int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1)  k++;
    return min(d[L][k],d[R-(1<<k)+1][k]);
}
int main()
{
    int n,k;
    char s[1010];
    while(scanf("%s%d",s,&k)==2)
    {
         n=strlen(s);
         if(k>=n)
         {
              puts("0");
              continue;
        }
        for(int i=0;i<n;i++)
           a[i]=s[i]-'0';
        RMQ_init(n);
        int temp=n-k;
        int len=0;
        int pos=-1;
        int ok=0;
        for(int i=0;i<temp;i++)
        {
             // printf("l,r:%d %d\n",pos+1,n-(temp-i));
              int now=RMQ(pos+1,n-(temp-i));
              if(now!=0)
                   ok=1;
              if(ok)
                   printf("%d",now);
              for(int j=pos+1;j<=n-(temp-i);j++)
              {
                 if(a[j]==now)
                  {
                     pos=j;
                     break;
                  }
              }
        }
        if(!ok)
            printf("0");
        printf("\n");
    }
    return 0;
}

