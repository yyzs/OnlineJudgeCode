#include "stdio.h"
int a1[100],a2[100];
int b[11][2];
int main()
{
 int i,j,k;
 int t,n,d;
 scanf("%d",&t);
 while(t--)
 {
     scanf("%d%d",&n,&d);
     for(i=0;i<d;i++)
         scanf("%d%d",&b[i][0],&b[i][1]);
    for(i=0;i<=n;i++)
        {
            a1[i]=0;
            a2[i]=0;
        }
    for(i=0;i<=b[0][1]*b[0][0]&&i<=n;i+=b[0][0])
           a1[i]=1;
    for(i=1;i<d;i++)
     {
         for(j=0;j<=n;j++)
             for(k=0;k+j<=n&&k<=b[i][0]*b[i][1];k+=b[i][0])
                  a2[k+j]+=a1[j];
        for(j=0;j<=n;j++)
             {a1[j]=a2[j];
              a2[j]=0;}
     } 
     printf("%d\n",a1[n]);
 }    
    return 0;
}
