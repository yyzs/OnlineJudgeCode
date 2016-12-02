#include "stdio.h"
#include "string.h"
#include "math.h"
long long  f[21];
int main()
{
    int n,i;
    double a,ans;
    f[0]=0;
    f[1]=1;
    for(i=2;i<=20;i++)
        f[i]=f[i-1]+f[i-2];
    while(scanf("%d",&n)==1)
    {
        if(n<=20)
           {printf("%I64d\n",f[n]);
            continue;
           }
        a=(1.0+sqrt(5.0))/2.0;
        ans=-0.5*log10(5.0)+(double)n*log10(a);
        int answer;
        ans=ans-floor(ans);
        ans=pow(10.0,ans);
        answer=(int)(ans*1000);
        printf("%d\n",answer);
    }
    return 0;
}

