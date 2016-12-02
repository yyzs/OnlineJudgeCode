#include "stdio.h"
int main()
{
    char a[11];
    int i,j,n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(a);
        printf("6");
        printf("%s",a+6);
        printf("\n");
    }
    return 0;
}

