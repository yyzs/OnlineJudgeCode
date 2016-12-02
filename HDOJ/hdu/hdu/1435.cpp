#include "stdio.h"
#include "string.h"
#define MAX 220
#include "algorithm"
using namespace std;
int n,t;
int temp[MAX];
int anssend[MAX],ansreceive[MAX];
int sender[MAX][MAX],receiver[MAX][MAX];
double ans1[MAX][MAX],ans2[MAX][MAX];
struct send
{
    int num,f;
    double x,y,z;
}s[MAX];
struct receive
{
    int num,f;
    double x,y,z;
}r[MAX];
struct point
{
     int num;
     int f;
     double dis;
}p[MAX];
double ans(double x1,double y1,double z1,double x2,double y2,double z2)
{
     return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
}
int cmp(struct point a,struct point b)
{
     if(a.dis==b.dis)
             return a.f>b.f;
     return a.dis<b.dis;
}
int find(int w,int m)
{
    int i;
    for(i=0;i<n;i++)
        if(receiver[w][i]==m)
              break;
    return i;
}
void match()
{
      int  i,j,ok;
      memset(anssend,-1,sizeof(anssend));
      memset(ansreceive,-1,sizeof(ansreceive));
      memset(temp,-1,sizeof(temp));
      while(1)
      {
           ok=1;
           for(i=0;i<n;i++)
           {
                if(anssend[i]==-1)
                        {ok=0;
                         temp[i]++;
                         if(ansreceive[sender[i][temp[i]]]==-1)
                                {anssend[i]=temp[i];
                                 ansreceive[sender[i][temp[i]]]=i;
                                 break;
                                 }
                         if(find(sender[i][temp[i]],ansreceive[sender[i][temp[i]]])>find(sender[i][temp[i]],i))
                                {anssend[i]=temp[i];
                                 anssend[ansreceive[sender[i][temp[i]]]]=-1;
                                 ansreceive[sender[i][temp[i]]]=i;
                                 break;
                                }
                         }
            }
            if(ok)
                 break;
        }
}
int main()
{
   int i,j;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      for(i=0;i<n;i++)
              scanf("%d%d%lf%lf%lf",&s[i].num,&s[i].f,&s[i].x,&s[i].y,&s[i].z);
      for(i=0;i<n;i++)
              scanf("%d%d%lf%lf%lf",&r[i].num,&r[i].f,&r[i].x,&r[i].y,&r[i].z);
      for(i=0;i<n;i++)
              for(j=0;j<n;j++)
                   {ans1[i][j]=ans(s[i].x,s[i].y,s[i].z,r[j].x,r[j].y,r[j].z);
                    ans2[j][i]=ans1[i][j];
                   }
      for(i=0;i<n;i++)
              {
                 for(j=0;j<n;j++)
                      {
                         p[j].dis=ans1[i][j];
                         p[j].num=j;
                         p[j].f=r[j].f;
                        }
                 sort(p,p+n,cmp);
                 for(j=0;j<n;j++)
                       sender[i][j]=p[j].num;
                }
       for(i=0;i<n;i++)
              {
                 for(j=0;j<n;j++)
                      {
                         p[j].dis=ans2[i][j];
                         p[j].num=j;
                         p[j].f=s[j].f;
                        }
                 sort(p,p+n,cmp);
                 for(j=0;j<n;j++)
                       receiver[i][j]=p[j].num;
                }
       match();
       for(i=0;i<n;i++)
                printf("%d %d\n",i+1,sender[i][anssend[i]]+1);
    }
    return 0;
}

