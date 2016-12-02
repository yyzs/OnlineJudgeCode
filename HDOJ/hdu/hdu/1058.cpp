#include "stdio.h"
int a[5850];
int f[4]={2,3,5,7},pac[4]={1,1,1,1},ori[4]={2,3,5,7};
int min(int a,int b,int c,int d)
{
    if(a>b)
       a=b;
    if(a>c)
       a=c;
    if(a>d)
       a=d;
    return a;
}
int  main()
{int n;
 int i,j,ten;
 a[1]=1;
 for(i=2;i<=5842;i++)
   {a[i]=min(f[0],f[1],f[2],f[3]);
    for(j=0;j<4;j++)
       if(a[i]==f[j])
          {pac[j]+=1;
           f[j]=a[pac[j]]*ori[j];
           }
    }
  while(scanf("%d",&n)==1)
     { if(n==0)
          break;
        printf("The %d",n);
        ten = n/10%10;
        if(n%10 == 1 && ten != 1)
            printf("st");
        else if(n%10 == 2 && ten != 1)
            printf("nd");
        else if(n%10 == 3 && ten != 1)
            printf("rd");
        else
            printf("th");
        printf(" humble number is %d.\n",a[n]);

     }
  return 0;
  }

