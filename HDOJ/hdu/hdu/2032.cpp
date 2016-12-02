#include <stdio.h>
#include <string.h>
#include <ctype.h>
int a[1000][1000];

int main()
{
    int i,j,n;
    a[0][0]=1;a[1][0]=1;a[1][1]=1;
    while(scanf("%d",&n)>0)
    {
        for(i=2;i<n;i++)
        {
            a[i][0]=1;
            for(j=1;j<=i-1;j++)
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
            a[i][i]=1;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(j!=0) printf(" ");
                printf("%d",a[i][j]);
            }

            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
