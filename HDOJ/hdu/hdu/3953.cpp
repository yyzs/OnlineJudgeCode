#include "stdio.h"
#include "string.h"
char a[110],b[110];
int main()
{
    int t,len1,len2;
    int i,j;
    int cas=0;
    long long ans=0;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        scanf("%s%s",a,b);
        len1=strlen(a);
        len2=strlen(b);
        ans=0;
        for(i=0;i<len1;i++)
            ans+=(a[i]-'0');
        for(i=0;i<len2;i++)
            ans+=(b[i]-'0');
        printf("Case %d: %I64d\n",cas,ans);
    }
    return 0;
}

