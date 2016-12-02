#include "stdio.h"
#include "string.h"
char a[230];
int main()
{int len;
 int n,k,i;
 char c;
 double ans;
 memset(a,0,sizeof(a));
 while(scanf("%c",&c)!=EOF)
 {getchar();
  scanf("%s",a);
  len=strlen(a);
  if(isalpha(c))
         c=toupper(c);
  for(i=0;i<len;i++)
         if(isalpha(a[i]))
              a[i]=toupper(a[i]);
  k=0;
  for(i=0;i<len;i++)
         if(a[i]==c)
              k++;
  ans=(double)k/(double)len;
  printf("%.5lf\n",ans);
  memset(a,0,sizeof(a));
  getchar();
  }
  return 0;
  }

