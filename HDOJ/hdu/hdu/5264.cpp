#include "stdio.h"
#include "string.h"
char a[10010],b[10010],c[10010];
int main()
{
    int t,len,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        len=strlen(a);
        for(i=0; i<len; i++)
        {
            if(i%2==0)
                b[i/2]=a[i];
            else
                c[i/2]=a[i];
        }
        for(i=0; i<len/2; i++)
            printf("%c",b[i]);
        puts("");
        for(i=len/2-1; i>=0; i--)
            printf("%c",c[i]);
        puts("");
    }
    return 0;
}

