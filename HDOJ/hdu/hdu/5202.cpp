#include "stdio.h"
#include "string.h"
#define MAX 1010
char a[MAX],b[MAX];
int n;
int is()
{
    int l=0,r=n-1;
    while(l<r)
    {
        if(b[l]!=b[r])
            return 0;
        l++;
        r--;
    }
    return 1;
}
int judge()
{
    int i,j;
    if(!is())
        return 1;
    for(i=n-1;i>=0;i--)
    {
        if(a[i]=='?')
        {
            b[i]='b';
            if(!is())
                return 1;
            b[i]='a';
        }
    }
    return 0;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)==1)
    {
        memset(b,0,sizeof(b));
        scanf("%s",a);
        for(i=0;i<n;i++)
        {
            if(a[i]=='?')
                b[i]='a';
            else
                b[i]=a[i];
        }
        if(!judge())
            puts("QwQ");
        else
            puts(b);
    }
    return 0;
}

