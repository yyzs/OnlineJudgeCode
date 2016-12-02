#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#define INF 1000
char  a[1511][11],b[11];
int dp[20][20];
int min(int a,int b)
{
    return a<b?a:b;
}
void debug(int len1,int len2)
{
    int i,j;
    for(i=1;i<=len1;i++)
    {for(j=1;j<=len2;j++)
            printf("%d ",dp[i][j]);
      printf("\n");
    }
}
int  slove(char a[],char b[])
{
    int len1,len2;
    int i,j;
    int cost;
    len1=strlen(a);
    len2=strlen(b);
    memset(dp,0,sizeof(dp));
    for(i=0;i<len1;i++)
        dp[i+1][0]=i+1;
    for(i=0;i<len2;i++)
        dp[0][i+1]=i+1;
    for(i=0;i<len1;i++)
    {
         for(j=0;j<len2;j++)
         {
             if(a[i]==b[j])
                    cost=0;
             else
                    cost=1;
             dp[i+1][j+1]=min(dp[i][j+1]+1,dp[i+1][j]+1);
             dp[i+1][j+1]=min(dp[i][j]+cost,dp[i+1][j+1]);
         }
    }
    //printf("%s %s:\n",a,b);
    //debug(len1,len2);
    return dp[len1][len2];
}
int main()
{
    int n,m;
    int  t;
    int i,j;
    int d,cas=0;
    int ans;
    int len1,len2;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        printf("Case #%d:\n",cas);
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
               scanf("%s",a[i]);
        while(m--)
        {
               ans=0;
               scanf("%s%d",b,&d);
               for(j=0;j<n;j++)
               {
                   len1=strlen(a[j]);
                   len2=strlen(b);
                   if(abs(len1-len2)>d)
                         continue;
                   if(slove(a[j],b)<=d)
                         ans++;
               }
               printf("%d\n",ans);
        }
    }
    return 0;
}

