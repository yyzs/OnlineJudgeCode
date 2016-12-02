#include "stdio.h"
#include "string.h"
char a[100],b[100];
int vis[300];
char ans[100];
int main()
{int n,i,j;
 int m;
 int t;
 int len1,len2;
 int num;
 scanf("%d",&t);
 while(t--)
 {scanf("%d",&m);
  getchar();
  memset(a,0,sizeof(a));
  memset(vis,0,sizeof(vis));
  memset(b,0,sizeof(b));
  memset(ans,0,sizeof(ans));
  gets(a);
  len1=strlen(a);
  for(i=0;i<len1;i++)
         if(a[i]!=' ')
             vis[a[i]]=0;
  scanf("%d",&n);
  getchar();
  gets(b);
  len2=strlen(b);
  for(i=0;i<len2;i++)
         if(b[i]!=' ')
             vis[b[i]]=1;
   num=0;
   m=0;
   for(i=0;i<len1;i++)
         {if(!vis[a[i]]&&a[i]!=' ')
             {num++;
              ans[m++]=a[i];
             }
          }
   if(num==0)
          {printf("Samuel can install the software without installing anything else.\n");
           continue;
          }
   printf("Samuel has to install another %d package(s) in addition,the packages is/are ",num);
   for(i=0;i<num;i++)
   {if(i==0)
         printf("%c",ans[i]);
    else
         printf(",%c",ans[i]);
    if(i==num-1)
         printf(".");
    }
    printf("\n");
   }
   return 0;
}


