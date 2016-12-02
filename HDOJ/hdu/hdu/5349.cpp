#include "stdio.h"
#include "algorithm"
#include "set"
using namespace std;
set<int> s;
int main()
{
    int n,a,b;
    while(scanf("%d",&n)==1)
    {
        s.clear();
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a);
            if(a==1)
            {
                scanf("%d",&b);
                s.insert(b);
            }
            if(a==2)
            {
                if(s.size()==0)
                    continue;
                s.erase(*s.begin());
            }
            if(a==3)
            {
                if(s.size()==0)
                    puts("0");
                else
                    printf("%d\n",(*s.rbegin()));
            }
        }
    }
    return 0;
}

