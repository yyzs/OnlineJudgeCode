#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 300
using namespace std;
struct node
{
    int w;
    char a[100];
}node[MAX];
int cmp(struct node a,struct node b)
{
    if(a.w==b.w)
        return strcmp(a.a,b.a)<0;
    return a.w>b.w;
}
int main()
{
    int n,m,i,j;
    int max,min;
    char a[100];
    while(scanf("%d",&n)==1,n)
    {
        for(i=0;i<n;i++)
             scanf("%s%d",&node[i].a,&node[i].w);
        sort(node,node+n,cmp);
        for(i=0;i<n;i++)
             printf("%s %d\n",node[i].a,node[i].w);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",a);
            for(i=0;i<n;i++)
                if(strcmp(node[i].a,a)==0)
                   break;
            for(j=0;j<n;j++)
                if(node[j].w<=node[i].w)
                   break;
            max=j+1;
            int temp=0;
            for(;j<i;j++)
                if(node[j].w==node[i].w)
                  temp++;
            min=temp+1;
            if(min==1)
                printf("%d\n",max);
            else
                printf("%d %d\n",max,min);
        }
    }
    return 0;
}

