#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int  main()
{
    char a[1000000];
    int i,len=0,n;
    while(1)
    {  memset(a,0,sizeof(a));
        scanf("%s",&a);
        len=strlen(a);
        if(a[0]=='0')
           break;
        n=-1;
        while(n==-1||n>=10)
         {
             len=strlen(a);
             n=0;
             for(i=0;i<len;i++)
               n+=a[i]-48;
              itoa(n,a,10);
         }
         printf("%d\n",n);
    }
    return 0;
}
