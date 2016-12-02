#include "stdio.h"
int d[3]={1,2,5},b[3];
int a1[10001],a2[10001];
int main()
{int i,j,k;
 while(scanf("%d%d%d",&b[0],&b[1],&b[2])==3)
  {if(b[0]==0&&b[1]==0&&b[2]==0)
              break;
   for(i=0;i<10000;i++)
    {
        a1[i]=0;
        a2[i]=0;
    }
    for(i=0;i<=b[0];i++)
        a1[i]=1;
    for(i=1;i<=2;i++) 
        {for(j=0;j<10000;j++)
            for(k=0;k<=b[i]*d[i]&&k+j<10000;k+=d[i])
                 a2[j+k]+=a1[j];
         for(j=0;j<10000;j++)
                {
                    a1[j]=a2[j];a2[j]=0;
                }
        }
     for(i=0;i<10000;i++)
            if(a1[i]==0)
            {
                printf("%d\n",i);
                break;
            }
  }
  return 0;
}
