#include<stdio.h>
int main()
{
    int n,i,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n<=m)
        {
            for(i=n;i<=m;i++)
            {
                if(i<m) printf("%d ",i);
                else printf("%d\n",i);
            }
        }
        else
        {
            if(n%(m+1)==0)
                printf("none\n");
            else
                printf("%d\n",n%(m+1));
        }
    }
return 0;
}
