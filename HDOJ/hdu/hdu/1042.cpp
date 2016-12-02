#include "stdio.h"
#include "string.h"
#define Maxn 10001
#define Base 10000
int a[10005];
int mutiply(int a[],int m,int len)
{
    int arry=0,i=0;
    for(i=len-1;i>=0;i--)
     {
         arry=arry+a[i]*m;
         a[i]=arry%Base;
         arry/=Base;
     }
}
int main()
{
    int i;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        a[Maxn-1]=1;
        if(n==0)
           printf("1\n");
        else
        {
         for(i=1;i<=n;i++)
           mutiply(a,i,Maxn);
        for(i=0;i<Maxn&&a[i]==0;i++)
            ;
        printf("%d",a[i++]);
        for(;i<Maxn;i++)
          printf("%04d",a[i]);
        printf("\n");
        }
    }
    return 0;
}
