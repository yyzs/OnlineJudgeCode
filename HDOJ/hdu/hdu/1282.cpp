#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char a[20],b[20];
int num[1000];
int judge()
{int len,i,m;
 len=strlen(a);
 m=0;
 memset(b,0,sizeof(b));
 for(i=len-1;i>=0;i--)
      b[m++]=a[i];
 for(i=0;i<len;i++)
      if(a[i]!=b[i])
         return 0;
 return 1;
 }
 int sum()
 {int s=0,m=0,i,len;
  int c,d;
  len=strlen(a);
  memset(b,0,sizeof(b));
   for(i=len-1;i>=0;i--)
      b[m++]=a[i];
  c=atoi(a);
  d=atoi(b);
  return c+d;
}
int main()
{int ok,i,j,m;
 int n,ans;
 while(scanf("%d",&n)==1)
 {
   memset(num,0,sizeof(num));
   memset(a,0,sizeof(a));
   num[0]=n;
   itoa(n,a,10);
   ans=0;
   while(!judge())
      {ans++;
       num[ans]=sum();
       memset(a,0,sizeof(a));
       itoa(num[ans],a,10);
       }
    printf("%d\n",ans);
    for(i=0;i<=ans;i++)
        {if(i==0)
              printf("%d",num[i]);
         else
              printf("--->%d",num[i]);
        }
    printf("\n");
  }
  return 0;
}

