# include <stdio.h>
# include <math.h>
int main()
{
    int k;
    __int64 a,b;
    while(scanf("%d",&k)!=EOF)
    {
        scanf("%I64d%I64d",&a,&b);
        if((pow(2,k-1)-1-a)<b||((-1)*pow(2,k-1)-a)>b)
            printf("Yes\n");
        else
            printf("WaHaHa\n");
    }
    return 0;
}

