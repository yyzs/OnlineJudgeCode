#include "stdio.h"
#include "string.h"
#include "algorithm"
#include <set>
#define MAX 10010
using namespace std;
int grundy[MAX];
int a[MAX];
int main()
{
    int n,m;
    int i;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(grundy,0,sizeof(grundy));
        grundy[0]=0;
        for(i=1;i<=m;i++)
               a[i]=i;
        for(i=1;i<=n;i++)
        {
            set<int> s;
            for(int j=1;j<=m;j++)
        {
              if(a[j]<=i)
                   s.insert(grundy[i-a[j]]);
        }
        int g=0;
        while(s.count(g)!=0)
               {
                   g++;
               }
        grundy[i]=g;
        }
        if(grundy[n]!=0)
               printf("Grass\n");
        else
               printf("Rabbit\n");
    }
    return 0;
}

