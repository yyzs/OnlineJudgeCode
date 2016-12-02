#include "stdio.h"
#include "string.h"
int a[12];
char b[12]={"pqruvwxyz"};
int main()
{
   int t,cas;
   int flag,i;
   scanf("%d",&t);
   while(t--)
   {
       for(i=0;i<10;i++)
              scanf("%d",&a[i]);
        flag=0;
        for(i=0;i<10;i++)
        {
            if(a[i]==0)
                    continue;
             if(flag==1&&a[i]>0)
              printf("+");
             flag=1;
            if(i==9)
            {
               printf("%d",a[i]);
               continue;
            }
            if(a[i]!=1&&a[i]!=-1)
                   printf("%d",a[i]);
            else
                  if(a[i]==-1)
                         printf("-");
             printf("%c",b[i]);
        }
        if(!flag)
             printf("0");
        puts("");
   }
   return 0;
}

