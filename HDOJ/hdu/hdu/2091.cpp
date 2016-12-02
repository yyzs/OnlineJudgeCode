#include <stdio.h>
int main()
{
        int n,i,j;
        char ch;
        int firstline=1;
        while(scanf("%c",&ch)&&ch!='@')
        {
                scanf("%d",&n);
                if(firstline==0)
                        printf("\n");
                firstline=0;
                for(i=0;i<n;++i)
                {
                        for(j=0;j<2*n-1;++j)
                        {
                                if((j==(2*n-1)/2+i) || (j==(2*n-1)/2-i)||i==n-1)                                        printf("%c",ch);
                                else if(j<(2*n-1)/2+i)
                                        printf(" ");
                        }
                        printf("\n");
                }
                getchar();
        }
        return 0;
}

