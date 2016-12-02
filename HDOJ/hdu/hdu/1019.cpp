#include "stdio.h"
int gcd(int a,int b)
{
    if(a%b==0)
      return b;
    else
      return gcd(b,a%b);
}
int main()
{int a,ans;
 int n,m,i,j;
 while(scanf("%d",&n)==1)
  {for(i=0;i<n;i++)
     {scanf("%d",&m);
      if(m==1)
        {
            scanf("%d",&a);
            printf("%d\n",a);
        }
      else
      {
       ans=1;
       for(j=0;j<m;j++)
         {scanf("%d",&a);
          ans=a/gcd(ans,a)*ans;
          }
        printf("%d\n",ans);
      }
      }
    }
   return 0;
  }

