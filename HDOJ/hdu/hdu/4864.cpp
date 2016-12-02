//题意：给你n个机器和m个任务，机器和任务有两个属性：x和y。每个机器只能完成一个任务，且满足机器的x和y大于等于任务的x和y，每完成一个任务，获得500×x+2×//y的价值。问你最多获得多少价值和最多完成多少个任务
//思路：容易想到贪心的做法，按照x和y从大到小的顺序对任务和机器排序，枚举任务，则能完成此任务的机器的x必须大于任务的x，又因为价值中x的比重较大，所以在
//满足x条件中的机器筛选。筛选出满足条件的最小的y。
#include "algorithm"
#include "map"
#include "stdio.h"
#include "utility"
#define MAX 100000
using namespace std;
struct node
{
    int x,y;
} mac[MAX],tak[MAX];
int cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y>b.y;
    return a.x>b.x;
}
int main()
{
    int n,m,cnt;
    long long ans;
    map<int, int> mpp;
    while(scanf("%d%d",&n,&m)==2)
    {
        mpp.clear();
        for(int i=0; i<n; i++)
            scanf("%d%d",&mac[i].x,&mac[i].y);
        for(int i=0; i<m; i++)
            scanf("%d%d",&tak[i].x,&tak[i].y);
        sort(mac,mac+n,cmp);
        sort(tak,tak+m,cmp);
        int j=0;
        ans=0;
        cnt=0;
        for(int i=0; i<m; i++)
        {
            while(j<n&&mac[j].x>=tak[i].x)
            {
                mpp[mac[j].y]++;
                j++;
            }
            map<int, int>::iterator it=mpp.lower_bound(tak[i].y);
            if(it!=mpp.end())
            {
                int t=it->first;
                ans=ans+tak[i].x*500+tak[i].y*2;
                cnt++;
                mpp[t]--;
                if(mpp[t]==0)
                    mpp.erase(t);
            }
        }
        printf("%d %lld\n",cnt,ans);
    }
    return 0;
}

