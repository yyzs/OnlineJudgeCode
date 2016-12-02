#include "stdio.h"
#include "string.h"
char a[10000],b[10000];
int dp[1000][1000];
int max(int a,int b)
{
  return a>b?a:b;
}
int main()
{int len1,len2,len;
 int i,j;
 while(scanf("%s%s",a,b)!=EOF)
 {len1=strlen(a);
  len2=strlen(b);
  len=max(len1,len2);
  for(i=0;i<=len;i++)
    {dp[i][0]=0;
     dp[0][i]=0;
     }
  for(i=1;i<=len1;i++)
     for(j=1;j<=len2;j++)
       {if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
   printf("%d\n",dp[len1][len2]);
   }
   return 0;
  }

