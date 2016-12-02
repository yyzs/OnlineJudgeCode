#include "stdio.h"
#include "algorithm"
#include "string.h"
using namespace std;
int main()
{int a[10];
 int i,j,ok=0;
 int flag,temp;
 while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3])==4)
 {
     if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0)
              break;
     if(ok)
           printf("\n");
     ok=1;
     sort(a,a+4);
     flag=1;
     temp=a[0];
     do
     {
         if(a[0]==0)
             continue;
         if(flag)
             {printf("%d%d%d%d",a[0],a[1],a[2],a[3]);
              flag=0;
             }
         else
             if(temp==a[0])
                 printf(" %d%d%d%d",a[0],a[1],a[2],a[3]);
         else
             printf("\n%d%d%d%d",a[0],a[1],a[2],a[3]);
          temp=a[0];
     }while(next_permutation(a,a+4));
     printf("\n");
 }
    return 0;
}

