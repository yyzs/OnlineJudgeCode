#include <stdio.h>
int main()
{
    int n,count;
    char c;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        count=0;
        while((c=getchar())!='\n')
            if(c<0)
                count++;
        printf("%d\n",count/2);
    }    
    return 0;
}
