#include "stdio.h"
#include "string.h"
char a[5010];
int main()
{int i,j,ans;
 int len;
 memset(a,0,sizeof(a));
 while(scanf("%s",a)!=EOF)
 {len=strlen(a);
  ans=0;
  for(i=0;i<len;i++)
  {for(j=0;i+j<len&&i-j>=0;j++)
        {if(a[i+j]!=a[i-j])
            break;
         else
            ans++;
         }
   for(j=0;i-j>=0&&i+j+1<len;j++)
        {if(a[i+j+1]!=a[i-j])
             break;
         else
             ans++;
         }
    }
    printf("%d\n",ans);
    memset(a,0,sizeof(a));
  }
  return 0;
  }

