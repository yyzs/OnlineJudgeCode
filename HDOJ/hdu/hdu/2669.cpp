#include "stdio.h"
#include "string.h"
using namespace std;
void exgcd(int a,int b,int &d,int &x,int &y)
{
    if(!b){
        d=a;
        x=1;
        y=0;
    }
    else{
        exgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
int main()
{
    int a,b,g;
    int k;
    int x0,y0,x,y;
    while(scanf("%d%d",&a,&b)==2)
    {
        g=gcd(a,b);
        if(g!=1)
        {
            puts("sorry");
            continue;
        }
        exgcd(a,b,g,x0,y0);
        k=-10000;
        while(1){
        x=x0+k*b;
        y=y0-k*a;
        if(x>=0)
                break;
        k++;
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}

