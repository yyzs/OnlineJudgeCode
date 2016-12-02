#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char a[10];
int main()
{int n;
 int len,i;
 long long sum1,sum2;
 int t;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d",&n);
  if(n%8==0)
       {
        printf("Lucky number!\n");
        continue;
        }
   memset(a,0,sizeof(a));
   sum1=0;
   sum2=0;
   itoa(n,a,10);
   len=strlen(a);
   for(i=0;i<len;i++)
        {sum1=sum1+(a[i]-'0');
         sum2=sum2+(a[i]-'0')*(a[i]-'0');
         }
   if(sum1%8==0||sum2%8==0)
          printf("Lucky number!\n");
   else
          printf("What a pity!\n");
  }
  return 0;
}

