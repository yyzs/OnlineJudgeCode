#include "stdio.h"
#include "string.h"
#include "math.h"
#include "algorithm"
#define INF 1e-10
using namespace std;
int main()
{
    int t;
    int h,m,s;
    while(scanf("%d",&t)==1)
    {
        for(h=0; h<12; h++)
            for(m=0; m<=59; m++)
                for(s=0; s<=59; s+=10)
                {
                    int ss=h*3600+m*60+s;
                    int  a=30*120*ss/36;
                    while(a>360*12000)
                       a-=360*12000;
                    int b=1200*ss;
                    while(b>360*12000)
                      b-=360*12000;
                    int d=abs(a-b);
                    if(d>180*12000)
                        d=360*12000-d;
                    if(d==t)
                        printf("%02d:%02d:%02d\n",h,m,s);
                }
    }
    return 0;
}

