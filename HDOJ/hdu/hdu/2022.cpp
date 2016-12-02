#include "stdio.h"
#include "math.h"
int main()
{long long a[100][100];
 int m,n;
 int x=0,y=0,s=0;
 int i,j;
 while(scanf("%d%d",&m,&n)==2)
 {
  x=0;y=0;s=0;
  for(i=0;i<m;i++)
   for(j=0;j<n;j++)
    {scanf("%lld",&a[i][j]);
     if(abs(a[i][j])>abs(s))
       {x=i;
        y=j;
        s=a[i][j];
        }
    }
  printf("%d %d %d\n",x+1,y+1,s);
 }
  return 0;
  }

