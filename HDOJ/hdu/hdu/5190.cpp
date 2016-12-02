#include "stdio.h"
#include "math.h"
#define MAX 110
int main()
{
    int n,m,a,b,min;
    int i,j;
    while(scanf("%d%d",&n,&m)==2)
    {
        int temp;
        min=100000;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            if(a>n)
                temp=b;
            else
                temp=(int)ceil((double)n/(double)a)*b;
          //  printf("%d\n",(int)ceil((double)n/(double)a));
            if(temp<min)
                min=temp;
        }
        printf("%d\n",min);
    }
    return 0;
}

