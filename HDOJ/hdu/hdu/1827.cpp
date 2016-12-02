#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int cast[1010];
int head[1010];
int temp[1010];
int dfn[1010];
int low[1010];
int stack[1010];
int is_one[1010];
int N,M,m;
int the_min_people;
int the_min_cast;
int the_min;
int the_number;
int a,b;
struct Node
{
    int t,next;
}Edge[2010];
int Tarbfs(int k,int lay,int& scc_num)
{
    temp[k] = 1;
    low[k] = lay;
    dfn[k] = lay;
    stack[++ m] = k;
    for(int i = head[k];i != 0;i = Edge[i].next)
    {
        if(temp[Edge[i].t] == 0)
        {
            Tarbfs(Edge[i].t,++ lay,scc_num);
        }
        if(temp[Edge[i].t] == 1)
              low[k] = min(low[k],low[Edge[i].t]);
    }
    if(dfn[k] == low[k])
    {
        scc_num ++;
        do
        {
            low[stack[m]] = scc_num;
            temp[stack[m]] = 2;
        }while(stack[m --] != k);
    }
    return 0;
}
int Tarjan(int n)
{
    int scc_num = 0,lay = 1;
    m = 0;
    memset(temp,0,sizeof(temp));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    for(int i = 1;i <= n;i ++)
    {
        if(temp[i] == 0)
            Tarbfs(i,lay,scc_num);
    }
    return scc_num;
}
int main()
{
    while(scanf("%d%d",&N,&M) != EOF)
    {
        memset(Edge,0,sizeof(Edge));
        memset(head,0,sizeof(head));
        memset(cast,0,sizeof(cast));
        the_min_cast = 0;
        the_min_people = 0;
        for(int i = 1;i <= N;i ++)
            scanf("%d",&cast[i]);
        for(int i = 1;i <= M;i ++)
        {
            scanf("%d%d",&a,&b);
            Edge[i].t = b;
            Edge[i].next = head[a];
            head[a] = i;
        }
        the_number = Tarjan(N);
        for(int i = 1;i <= the_number;i ++)
            is_one[i] = 0;
        for(int i = 1;i <= the_number;i ++)
        {
            int indegree = 0;
            for(int j = 1;j <= N;j ++)
            {
                for(int k = head[j];k != 0;k = Edge[k].next)
                {
                    if(low[Edge[k].t] == i && low[j] != i)
                    {
                        indegree = 1;
                        break ;
                    }
                }
                if(indegree == 1)
                    break ;
            }
            if(indegree == 0)
               is_one[i] = 1;
        }
        for(int i = 1;i <= the_number;i ++)
        {
            if(is_one[i] == 1)
            {
                the_min_people ++;
                the_min = 100000000;
                for(int j = 1;j <= N;j ++)
                {
                    if(low[j] == i && cast[j] < the_min)
                         the_min = cast[j];
                }
                the_min_cast += the_min;
            }
        }
        printf("%d %d\n",the_min_people,the_min_cast);
    }
    return 0;
}
