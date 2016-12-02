#include "stdio.h"
#include "cstring"
#include "ctype.h"
#include "algorithm"
#define MAX 1001
using namespace std;
char a[MAX];
int res[MAX];
void solve(int n,int b)
{
    int i,j,mx=0,len;
    memset(res,0,sizeof(res));
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
        len=strlen(a);
        reverse(a,a+len);
        for(j=0;j<len;j++)
        {
           if(isdigit(a[j]))
               res[j]+=a[j]-'0';
           else
               res[j]+=a[j]-'a'+10;
           mx=max(len,mx);
        }
    }
    for(j=0;j<mx;j++)
            res[j]%=b;
    while(mx>1&&res[mx-1]==0)
            --mx;
    for(j=mx-1;j>=0;j--)
    {
        if(res[j]<=9)
            printf("%d",res[j]);
        else
            printf("%c",res[j]-10+'a');
    }
    printf("\n");
}
int main()
{
    int n,b;
    while(scanf("%d%d",&n,&b)==2)
    {
        solve(n,b);
    }
}

