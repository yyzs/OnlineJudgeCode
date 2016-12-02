#include "stdio.h"
#include "string.h"
char a[102];
int ans[102];
void sum()
{int len,z=101,i,temp;
 len=strlen(a);
 temp=0;
 for(i=len-1;z>=0;i--)
 {if(i<0)
        a[i]='0';
  temp=temp+(a[i]-'0')+ans[z];
  ans[z]=temp%10;
  temp/=10;
  z--;
  }
}
int main()
{int n,i,j;
 scanf("%d",&n);
 while(n--)
 {memset(a,0,sizeof(a));
  memset(ans,0,sizeof(ans));
  while(scanf("%s",a)&&strcmp(a,"0")!=0)
        {sum();
         memset(a,0,sizeof(a));
        }
   for(i=0;i<101&&ans[i]==0;i++);
   for(;i<102;i++)
              printf("%d",ans[i]);
   printf("\n");
   if(n!=0)
              printf("\n");
   }
   return 0;
}

