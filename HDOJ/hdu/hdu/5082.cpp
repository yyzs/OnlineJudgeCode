#include "stdio.h"
#include "string.h"
int main()
{
    char a[40],b[50];
    int len1,len2,i;
    while(scanf("%s%s",a,b)!=EOF)
    {
        len1=strlen(a);
        len2=strlen(b);
        for(i=0;i<len1;i++)
             if(a[i]=='_')
                break;
        i++;
        for(;i<len1;i++)
              printf("%c",a[i]);
        printf("_small_");
        for(i=0;i<len2;i++)
              if(b[i]=='_')
                 break;
        i++;
        for(;i<len2;i++)
               printf("%c",b[i]);
        printf("\n");
    }
    return 0;
}

