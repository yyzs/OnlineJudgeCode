#include "stdio.h"
int main()
{
    long long a,b; 
    int t;
    scanf("%d",&t); 
    while(t--)
    {
        scanf("%I64d%I64d",&a,&b);
        if(a%b==0)
          printf("YES\n");
        else
         printf("NO\n");
    }
    return 0;
}
