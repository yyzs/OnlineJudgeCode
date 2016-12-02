#include <stdio.h>
#include <iostream>
#define N 1000005
using namespace std;
long long a[N],b[N],c[N];
int main()
{
    long long tmax,ans;
    int n,cas,i,j,tsum,ti,tj;
    int p;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&p);
        for (j=0; j<n; j++)    cin>>a[j];
        ans=p;
        for(int i=0; i<n; i++)
        {
            long long temp=a[i];
            a[i]=p;
            c[n-1]=n-1;
            b[n-1]=a[n-1];
            tmax=a[n-1];
            ti=tj=n-1;
            for (j=n-2; j>=0; j--)
            {
                if(b[j+1]>0)
                {
                    b[j]=a[j]+b[j+1];
                    c[j]=c[j+1];
                }
                else
                {
                    b[j]=a[j];
                    c[j]=j;
                }
                if(b[j]>=tmax)
                {
                    tmax=b[j];
                    ti=j;
                    tj=c[j];
                }
            }
            a[i]=temp;
            if(tmax>ans)
                ans=tmax;
        }
        cout<<ans<<endl;
    }
    return 0;
}

