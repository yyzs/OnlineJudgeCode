#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char a[20];
int main()
{
    int ans=0;
    int t,n,i,len;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        itoa(n,a,2);
        len=strlen(a);
        ans=0;
        for(i=len-1;i>=0;i--)
             ans=ans*2+a[i]-'0';
        printf("%d\n",ans);
    }
    return 0;
}

