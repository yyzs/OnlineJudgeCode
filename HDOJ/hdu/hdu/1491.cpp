#include "stdio.h"
#include "string.h"
int mon[]={31,28,31,30,31,30,31,31,30,21};
int main()
{int m,d;
 int t;
 int ans,i;
 scanf("%d",&t);
 while(t--)
 {scanf("%d%d",&m,&d);
  if(m==10&&d==21)
            {printf("It's today!!\n");
             continue;
             }
  if((m==10&&d>21)||m>10)
            {printf("What a pity, it has passed!\n");
             continue;
             }
  ans=0;
  for(i=m-1;i<10;i++)
            {
                if(i==m-1)
                      ans=ans+mon[i]-d;
                else
                      ans=ans+mon[i];
            }
  printf("%d\n",ans);
  }
  return 0;
}

