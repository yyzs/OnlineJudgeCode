#include "stdio.h"
#include "string.h"
#define Max 210
#define Base 10000
int a[210][210];
int res[210];
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
 int i;
 int cas=1;
 while(scanf("%d%d",&m,&n)==2)
 {if(m==0&&n==0)
      break;
  if(m<n)
    { printf("Test #%d:\n",cas++);
     printf("0\n");
     continue;
     }
  /*if(n==0)
    {printf("1\n");
     continue;
     }*/
  memset(a[1],0,sizeof(a[1]));
  a[1][Max-1]=1;
  for(i=1;i<=m+n;i++)
  {if(i==1)
          continue;
   memcpy(a[i],a[i-1],sizeof(a[1]));
   mutiply(a[i],i,Max);
   /*divide(a[i],m+1,Max);*/
   }
   memcpy(res,a[m+n],sizeof(a[1]));
   mutiply(res,m+1-n,Max);
   divide(res,m+1,Max);
   printf("Test #%d:\n",cas++);
   for(i=0;i<Max&&res[i]==0;i++)
        ;
   printf("%d",res[i++]);
   for(;i<Max;i++)
       printf("%04d",res[i]);
   printf("\n");
   }
   return 0;
   }

