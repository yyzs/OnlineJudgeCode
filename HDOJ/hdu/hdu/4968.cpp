#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int t[5][2]={85,100,80,84,75,79,70,74,60,69};
double m[5]={4,3.5,3,2.5,2};
int main()
{
    int cas,sum,n;
    int sum1,sum2;
    int a,b,c,d,e;
    double min,max,temp;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&sum,&n);
        min=100;
        max=0;
        for(a=0;a<=n;a++)
               for(b=0;b<=n-a;b++)
                   for(c=0;c<=n-a-b;c++)
                        for(d=0;d<=n-a;d++)
                       {
                           e=n-a-b-c-d;
                        sum1=a*t[0][0]+b*t[1][0]+c*t[2][0]+d*t[3][0]+e*t[4][0];
                        sum2=a*t[0][1]+b*t[1][1]+c*t[2][1]+d*t[3][1]+e*t[4][1];
                           if(n*sum>=sum1&&n*sum<=sum2)
                           {
                               temp=m[0]*a+m[1]*b+m[2]*c+m[3]*d+m[4]*e;
                               if(temp>max)
                                     max=temp;
                               if(temp<min)
                                    min=temp;
                           }
                       }
    printf("%.4f %.4f\n",min/n,max/n);
    }
    return 0;
}

