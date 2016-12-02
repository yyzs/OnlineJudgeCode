#include "stdio.h"
int main()
{int a,b,n,i,c[50],ans,rel;
 while(1)
  {scanf("%d%d%d",&a,&b,&n);
    if(a==0&&b==0&&n==0)
       break;
   c[0]=1;
   c[1]=1; 
   for(i=2;i<48;i++)
      {
       c[i]=(a*c[i-1]%7+b*c[i-2]%7)%7;
      }
   ans=c[n%48-1];
   printf("%d\n",ans);
   }
 return 0;
}
