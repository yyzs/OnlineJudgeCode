#include "stdio.h"
int d[26]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26},b[26];
int a1[100],a2[100];
int main()
{int i,j,k;
 int  t,sum;
 scanf("%d",&t);
 while(t--)
  {for(i=0;i<26;i++)
        scanf("%d",&b[i]);
   for(i=0;i<100;i++)
    {
        a1[i]=0;
        a2[i]=0;
    }
    for(i=0;i<=b[0];i++)
        a1[i]=1;
    for(i=1;i<26;i++) 
        {for(j=0;j<100;j++)
            for(k=0;k<=b[i]*d[i]&&k+j<100;k+=d[i])
                 a2[j+k]+=a1[j];
         for(j=0;j<100;j++)
                {
                    a1[j]=a2[j];a2[j]=0;
                }
        }
     sum=0;
     for(i=1;i<=50;i++)  sum+=a1[i];
     printf("%d\n",sum);
      }
  return 0;
}

