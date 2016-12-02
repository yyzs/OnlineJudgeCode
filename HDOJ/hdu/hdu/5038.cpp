#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#define MAX 10010
using namespace std;
int hash[MAX],f[1000100];
vector<int> v;
int main()
{
    int t,cas=0,num,d;
    int i,j,n,x;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        printf("Case #%d:\n",cas);
        scanf("%d",&n);
        memset(f,0,sizeof(f));
        memset(hash,0,sizeof(hash));
        //s = 10000 - (100 - w)^2
        d=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            hash[10000-(100-x)*(100-x)]++;
        }
        int max=0;
        num=0;
        v.clear();
        for(i=0;i<=10000;i++)
        {
            f[hash[i]]++;
            if(hash[i]>max)
            {
                v.clear();
                v.push_back(i);
                max=hash[i];
                num=1;
            }
            else
              if(max&&hash[i]==max)
             {
                 v.push_back(i);
                 num++;
             }
        }
        d=0;
        for(i=1;i<=n;i++)
            if(f[i])
              d++;
        int len=v.size();
        if(d==1&&len>1)
            puts("Bad Mushroom");
        else
        {
            for(i=0;i<len;i++)
            {
                if(i)
                    printf(" %d",v[i]);
                else
                    printf("%d",v[i]);
            }
            puts("");
        }
    }
    return 0;
}


