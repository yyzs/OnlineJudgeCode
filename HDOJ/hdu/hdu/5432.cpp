#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#define MAX 10010
#define eps 1e-10
#include "math.h"
using namespace std;
int a[MAX],b[MAX],n;
double slove(double h)
{
        double sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
                if(b[i]<h)
                {
                        sum2+=(double)(a[i]*a[i])*(double)b[i]/3.0;
                        continue;
                }
                double c=((double)b[i]-h)*(double)a[i]/(double)b[i];
                double temp=c*c*(b[i]-h)/3.0;
                sum1+=temp;
                sum2+=((double)(a[i]*a[i])*(double)b[i]/3.0-temp);
        }
        return sum1-sum2;
}
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                double l=1.0,r=0.0;
                for(int i=0;i<n;i++)
                        {
                                scanf("%d",&b[i]);
                                if(b[i]>r)
                                        r=b[i];
                        }
                for(int i=0;i<n;i++)
                        scanf("%d",&a[i]);
                double m;
                while(fabs(l-r)>eps)
                {
                        m=(l+r)/2.0;
                        double ans=slove(m);
                      //  printf("\nm,ans:%lf %lf\n",m,ans);
                        if(ans>0)
                                l=m;
                        else
                                r=m;
                }
                printf("%d\n",(int)m);
        }
        return 0;
}

