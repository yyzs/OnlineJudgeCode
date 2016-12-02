#include "stdio.h"
#include "algorithm"
#include "set"
using namespace std;
int main()
{
    int n,l,r,i,j;
    int a,b,c,k;
    while(scanf("%d",&n)==1,n)
    {
        set<int> s;
        s.clear();
        for(k=1;k<=n;k*=10)
        {
            c=n/k/11;
            b=n/k%11;
            if((b!=0||c!=0)&&b<10)
            {
                 a=(n-b*k-c*11*k)/2;
                 if(2*a+b*k+c*11*k==n) s.insert(a+b*k+c*10*k);
            }
            b--;
            if((b!=0||c!=0)&&b>=0)
            {
                 a=(n-b*k-c*11*k)/2;
                 if(2*a+b*k+c*11*k==n) s.insert(a+b*k+c*10*k);
            }
        }
        if(s.empty())
            puts("No solution.");
        else
        {
            set<int>::iterator it=s.begin();
            printf("%d",*it);
            while(++it!=s.end()) printf(" %d",*it);
            puts("");
        }
    }
    return 0;
}

