#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct Node
{
double x,y;
}node[100005];
int cmp(const Node a,const Node b)
{
return(a.x+a.y)<(b.x+b.y);
}
double dis(int a,int b)
{
return sqrt((node[a].x-node[b].x)*(node[a].x-node[b].x)+(node[a].y-node[b].y)*(node[a].y-node[b].y));
}
int main()
{
int n;
while(scanf("%d",&n),n)
{
for(int i=0;i<n;i++)
scanf("%lf%lf",&node[i].x,&node[i].y);
sort(node,node+n,cmp);
double mindis=INT_MAX,tempdis;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<(n<i+6?n:i+6);j++)
{
tempdis=dis(i,j);
if (tempdis<mindis) mindis=tempdis;
}
printf("%.2lf\n",mindis/2);
}
return 0;
}

