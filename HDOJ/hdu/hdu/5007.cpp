#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char a[10000000];
char b[5][10]={"Apple","iPhone","iPod","iPad","Sony"};
int main()
{
    int len,i;
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        len=strlen(a);
        a[len++]=c;
        for(i=0;i<4;i++)
        {
            if(strstr(a,b[i])!=NULL)
            {
                puts("MAI MAI MAI!");
                memset(a,0,sizeof(a));
                break;
            }
        }
        if(strstr(a,b[4])!=NULL)
        {
            puts("SONY DAFA IS GOOD!");
            memset(a,0,sizeof(a));
            continue;
        }
    }
    return 0;
}

