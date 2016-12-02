#include "stdio.h"
#include "string.h"
#include "algorithm"
#define m 9973
using namespace std;
int exgcd(int a,int b,int &d,int &x,int &y){
    if(!b) {d=a;x=1;y=0;}
    else  {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}
int gcd(int a,int b)
{
    if(a%b==0)
           return b;
    return gcd(b,a%b);
}
int main()
{
    int x0,y0,x,y;
    int g,t;
    int n,a,b,m1,b1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&b);
        g=gcd(b,m);
        m1=m/g;
        b1=b/g;
        exgcd(b,m,g,x0,y0);
        x0=x0*(n/g);
        x=x0+m1;
        while(x<0)
             x+=m;
        printf("%d\n",x%m);
    }
    return 0;
}



