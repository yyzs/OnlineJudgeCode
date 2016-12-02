#include "stdio.h"
#include "string.h"
int main()
{
    double score,sum;
    double s,p;
    int n,i;
    while(scanf("%d",&n)==1)
    {
        sum=0;
        score=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&s,&p);
            if(p!=-1)
                sum+=s;
            score=score+(int)((p-50)/10)*s;
        }
        if(sum!=0)
            printf("%.2lf\n",score/sum);
        else
            printf("-1\n");
    }
    return 0;
}

