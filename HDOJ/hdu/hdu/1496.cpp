#include "stdio.h"
#include "string.h"
#define F 1000000
int hash[3000010];
int main()
{int a,b,c,d;
 int x1,x2,x3,x4,i,j,k;
 long long ans;
 while(scanf("%d%d%d%d",&a,&b,&c,&d)==4)
 {if((a>0&&b>0&&c>0&&d>0)||(a<0&&b<0&&c<0&&d<0))
           {
               printf("0\n");
               continue;
           }
  memset(hash,0,sizeof(hash));
  for(i=1;i<=100;i++)
     for(j=1;j<=100;j++)
         hash[-d*i*i+F-c*j*j]++;
  ans=0;
  for(i=1;i<=100;i++)
          for(j=1;j<=100;j++)
                  if(hash[i*a*i+b*j*j+F]!=0&&i!=0&&j!=0)
                      ans+=hash[a*i*i+b*j*j+F];
  printf("%I64d\n",ans*16);
  }
  return 0;
}

