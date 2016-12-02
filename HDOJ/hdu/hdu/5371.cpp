#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 200020
using namespace std;
int a[MAX],b[MAX];
int r[MAX];
int len;
template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
void add()
{
    int i;
    memset(b,-1,sizeof(b));
    b[0]=-2;
    b[1]=-3;
    for(i=0; i<len; i++)
    {
        b[i*2+2]=a[i];
        b[i*2+3]=-3;
    }
    len=len*2+2;
    //puts(b);
}
void manacher()
{
    int i,j;
    int mx=0,p=0;
    memset(r,0,sizeof(r));
    for(i=1; i<len; i++)
    {
        if(mx>i)
            r[i]=min(r[2*p-i],mx-i);
        else
            r[i]=1;
        while(1)
        {
            //printf("%d %d\n",i+r[i],i-r[i]);
            if(b[i+r[i]]==b[i-r[i]])
                r[i]++;
            else
                break;
        }
        if(i+r[i]>mx)
        {
            mx=i+r[i];
            p=i;
        }
    }
}
int main()
{
    int t,i;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d",&len);
        for(i=0; i<len; i++)
            scan_d(a[i]);
        cas++;
           int ans=0;
    add();
    manacher();
    for(i=1; i<=len; i+=2)
    {
        if(b[i]!=-3)
            continue;
        if(r[i]<ans)
                continue;
        if(i+2*ans>len)
                continue;
        for(int j=r[i]-1; j>ans; j-=2)
        {
                if(r[i+j]>=j)
                {
                    ans=max(ans,j);
                    break;
                }
        }
    }
    printf("Case #%d: %d\n",cas,ans/2*3);
    }
    return 0;
}

