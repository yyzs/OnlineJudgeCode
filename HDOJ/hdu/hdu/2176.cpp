#include "stdio.h"
#include "string.h"
#include "set"
#include "algorithm"
#define MAX 200001
using namespace std;
int a[MAX];
int main()
{
    int i,j;
    int n,m;
    int ans;
    while(scanf("%d",&m)==1,m)
    {
        ans=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&a[i]);
            ans=(ans^a[i]);
        }
        if(ans==0)
              printf("No\n");
        else
             {
                 printf("Yes\n");
                 for(i=1;i<=a[i];i++)
                 {
                     if((ans^a[i])<a[i])
                     {
                         printf("%d %d\n",a[i],ans^a[i]);
                     }
                 }
             }
    }
    return 0;
}

