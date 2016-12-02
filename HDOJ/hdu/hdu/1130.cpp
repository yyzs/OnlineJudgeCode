#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define Max 101
#define Base 10000
int a[101][Max];
int mutiply(int a[],int m,int len)
{int i,arry=0;
 for(i=len-1;i>=0;i--)
    {arry+=a[i]*m;
     a[i]=arry%Base;
     arry/=Base;
     }
}
int divide(int a[],int m,int len)
{int i,div=0;
 for(i=0;i<len;i++)
  {div=div*Base+a[i];
   a[i]=div/m;
   div%=m;
   }
}
int main()
{int m,n;
 int i,j;
 int k;
 memset(a[1],0,sizeof(a[1]));
 for(i=2,a[1][Max-1]=1;i<Max;i++)
 {memcpy(a[i],a[i-1],sizeof(a[1]));
  mutiply(a[i],4*i-2,Max);
  divide(a[i],i+1,Max);
  }
  while(scanf("%d",&k)==1)
  {i=0;
   for(;a[k][i]==0&&i<Max;)
      i++;
   printf("%d",a[k][i++]);
   for(;i<Max;i++)
      printf("%04d",a[k][i]);
    printf("\n");
   }
   return 0;
}
