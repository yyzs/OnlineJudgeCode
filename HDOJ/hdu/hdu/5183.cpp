#include "stdio.h"
#include "set"
#include "algorithm"
#define LL long long
#define MAX 1000010
using namespace std;
set<LL> s;
LL sum[MAX];
int a[MAX];
int n,k;
void get(int &n)
{
    char c;
    int sign=1;
    while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')
        sign=-1,n=0;
    else
        n=c-'0';
    while((c=getchar())>='0'&&c<='9')
        n=n*10+c-'0';
    n*=sign;
}
int main()
{
    int t,i,j;
    int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        a[0]=0;
        sum[0]=0;
        for(i=1; i<=n; i++)
        {
            get(a[i]);
            if(i%2==1)
                sum[i]=sum[i-1]-a[i];
            else
                sum[i]=sum[i-1]+a[i];
        }
        cas++;
        printf("Case #%d: ",cas);
        s.clear();
        int ok=0;
        for(i=n; i>=0&&!ok; i--)
        {
            if(i%2==1)
            {
                if(s.find(sum[i]+k)!=s.end())
                    ok=1;
            }
            else
            {
                if(s.find(sum[i]-k)!=s.end())
                    ok=1;
            }
            s.insert(sum[i]);
        }
        if(ok)
            puts("Yes.");
        else
            puts("No.");
    }
}

