#include "stdio.h"
#include "string.h"
int main()
{
    int n,i,j,len,b[5];
    char a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
     {
         for(j=0;j<5;j++)
           b[j]=0;
         scanf("%s",a);
         for(j=0;a[j];j++)
          {
              switch(a[j])
              {
                  case 'a':b[0]++;break;
                  case 'e':b[1]++;break;
                  case 'i':b[2]++;break;
                  case 'o':b[3]++;break;
                  case 'u':b[4]++;break;
              }
          }
          printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",b[0],b[1],b[2],b[3],b[4]);
          if(i!=n-1)
           printf("\n");
     }
     return 0;
}
