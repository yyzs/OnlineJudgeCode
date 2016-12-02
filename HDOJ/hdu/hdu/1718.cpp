#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 1010
using namespace std;
struct node
{
    int num,w;
}node[MAX];
int main()
{
    int num1,n;
    int i;
    int w,x;
    int rank;
    int ans;
    while(scanf("%d",&num1)==1)
    {
        n=0;
        while(scanf("%d%d",&x,&w)==2,x+w)
        {
            if(x==num1)
                ans=n;
            node[n].num=x;
            node[n].w=w;
            n++;
        }
        rank=1;
        for(i=0;i<n;i++)
            {
             if(node[i].w>node[ans].w)
                  rank++;
            }
        printf("%d\n",rank);
    }
    return 0;
}

