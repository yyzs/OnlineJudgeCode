#include "cstdio"
#include "cstring"
#include "cstdlib"
#include "utility"
#include "set"
#include "vector"
using namespace std;
const int N=1003;
vector<int> a[N];
void solve(int n,int m)
{
    for(int i=0; i<n; i++)
        scanf("%*d%*d");
    if(m==0)
    {
        printf("1 %d\n",n);
        return;
    }
    for(int i=1; i<=n; i++)
    {
        a[i].clear();
    }
    int cnt3=0,cnt4=0;
    set<pair<int,int> > g;
    for(int i=0; i<m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y)
            swap(x,y);
        a[x].push_back(y);
        g.insert(make_pair(x,y));
    }
    for(set<pair<int,int> >::iterator i=g.begin(); i!=g.end(); i++)
    {
        int x=i->first,y=i->second;
        for(vector<int>::iterator j=a[x].begin(); j!=a[x].end(); j++)
        {
            int u=*j;
            if(g.count(make_pair(x,u))&&g.count(make_pair(y,u)))
            {
                cnt3++;
                for(vector<int>::iterator k=a[y].begin(); k!=a[y].end(); k++)
                {
                    int v=*k;
                    if(g.count(make_pair(x,v))&&g.count(make_pair(u,v))&&g.count(make_pair(y,v)))
                    {
                        cnt4++;
                    }
                }
            }
        }
    }
    if(cnt4>0)
    {
        printf("4 %d\n",cnt4);
        return;
    }
    if(cnt3>0)
    {
        printf("3 %d\n",cnt3);
        return;
    }
    printf("2 %d\n",m);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        solve(n,m);
    }
    return 0;
}

