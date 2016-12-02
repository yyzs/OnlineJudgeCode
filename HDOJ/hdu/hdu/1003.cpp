#include <stdio.h>
#define N 1000005
int a[N],b[N],c[N];
int main()
{
    int n,cas,i,j,tsum,tmax,ti,tj;
//     freopen("in.txt","r",stdin);
//     freopen("out.txt","w",stdout);
    scanf("%d",&cas);
    for (i=1;i<=cas;i++)
    {
        scanf("%d",&n);
        for (j=0;j<n;j++)    scanf("%d",&a[j]);
        c[n-1]=n-1;
        b[n-1]=a[n-1];
        //注意tmax，ti，tj初始化
        tmax=a[n-1];
        ti=tj=n-1;
        for (j=n-2;j>=0;j--)
        {
            if(b[j+1]>0)    {//这里不能是>=
                b[j]=a[j]+b[j+1];
                c[j]=c[j+1];
            }else{
                b[j]=a[j];
                c[j]=j;
            }
            if(b[j]>=tmax){
                tmax=b[j];
                ti=j;
                tj=c[j];
            }
        }
        printf("Case %d:\n",i);
        printf("%d %d %d\n",tmax,ti+1,tj+1);
        if(i!=cas)    printf("\n");
    }
}
