#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
long long a[100000]= {1,2,3,4,5,6,7,8,9};
int main()
{
    int i,j,t;
    int len=9,n,m,temp1=0;
    long long l,r;
    for(i=temp1; i<len; i++)
    {
        if(a[i]>1000000000)
            break;
        n=a[i]%10;
        if(n==1)
        {
            a[len++]=a[i]*10+1;
        }
        if(n==2)
        {
            a[len++]=a[i]*10+2;
            a[len++]=a[i]*10+1;
        }
        if(n==3)
        {
            a[len++]=a[i]*10+3;
            a[len++]=a[i]*10+1;
        }
        if(n==4)
        {
            a[len++]=a[i]*10+4;
            a[len++]=a[i]*10+2;
            a[len++]=a[i]*10+1;
        }
        if(n==5)
        {
            a[len++]=a[i]*10+5;
            a[len++]=a[i]*10+1;
        }
        if(n==6)
        {
            a[len++]=a[i]*10+6;
            a[len++]=a[i]*10+3;
            a[len++]=a[i]*10+2;
            a[len++]=a[i]*10+1;
        }
        if(n==7)
        {
            a[len++]=a[i]*10+7;
            a[len++]=a[i]*10+1;
        }
        if(n==8)
        {
            a[len++]=a[i]*10+8;
            a[len++]=a[i]*10+4;
            a[len++]=a[i]*10+2;
            a[len++]=a[i]*10+1;
        }
        if(n==9)
        {
            a[len++]=a[i]*10+9;
            a[len++]=a[i]*10+3;
            a[len++]=a[i]*10+1;
        }
    }
    sort(a,a+len);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&l,&r);
        long long ans=0;
        for(i=0;i<len;i++)
            if(a[i]>=l&&a[i]<=r)
               ans++;
        printf("%I64d\n",ans);
    }
    return 0;
}

