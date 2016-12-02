#include "stdio.h"
#define MAX 3000
int d[]={0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289};
int c1[MAX],c2[MAX];
int main()
{
    int n,i,j,k;
    while(scanf("%d",&n)==1,n)
    {
        for(i=0;i<=n;i++)
        {
            c1[i]=0;
            c2[i]=0;
        }
        for(i=0;i<=n;i++)
            c1[i]=1;
        for(i=2;i<=17;i++)
        {
            for(j=0;j<=n;j++)
                for(k=0;k+j<=n;k+=d[i])
                    c2[j+k]+=c1[j];
            for(j=0;j<=n;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}

