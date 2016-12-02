#include "stdio.h"
#include "string.h"
#include "map"
#define MAX 100010
#include "vector"
#include "algorithm"
using namespace std;
vector<int> g[MAX];
int q[MAX],c[MAX],has[MAX];
inline void scan_d(int &ret)
{
    char c;
    ret=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
}
struct node
{
    int h,id;
    int has;
} node[MAX];
int cmp(struct node a,struct node b)
{
    if(a.h==b.h)
        return a.id<b.id;
    return a.h<b.h;
}
int main()
{
    int n,m,i,j;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=0; i<n; i++)
        {
            scan_d(node[i].h);
            node[i].id=i;
            node[i].has=0;
        }
        sort(node,node+n,cmp);
        for(i=0; i<n; i++)
        {
            c[i]=node[i].h;
            has[i]=0;
        }
        for(i=0; i<m; i++)
        {
            scan_d(q[i]);
            int temp1=lower_bound(c,c+n,q[i])-c;
            int temp2=lower_bound(c,c+n,q[i]+1)-c;
            if(c[temp1]!=q[i])
            {
                printf("-1\n");
                continue;
            }
            if(temp2==n)
                temp2=n-1;
            else
                temp2-=1;
            int temp=lower_bound(has+temp1,has+temp2+1,0)-has;
            if(has[temp]==0&&node[temp].h==q[i])
            {
                printf("%d\n",node[temp].id+1);
                has[temp]=-1;
            }
            else
                puts("-1");
        }
    }
    return 0;
}

