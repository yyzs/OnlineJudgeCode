#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long n,m,a;
    int sum,l;
    cin>>a;
    while(a--)
    {
        cin>>n>>m;
        if(n>m)
        {
            int t=n;
                n=m;
                m=t;
        }
        l=0;
        for(int i=n;i<=m;i++)
        {
            sum=0;
            for(int j=1;j<i;j++)
            {
                if(i%j==0)
                sum=sum+j;
            }
            if(sum==i)l++;

        }
        printf("%d\n",l);


    }
    return 0;
}
