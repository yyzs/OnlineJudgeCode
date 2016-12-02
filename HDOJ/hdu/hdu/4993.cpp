#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int main()
{
    int t;
    int a,b,c;
    int ans;
    int x,y;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d%d",&a,&b,&c);
        for(x=1;x*a<c;x++)
        {
            y=(c-x*a)/b;
            if(a*x+b*y==c)
               ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

