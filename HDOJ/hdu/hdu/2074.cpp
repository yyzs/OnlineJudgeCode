#include "stdio.h"
#include "string.h"
char c[100][100];
int main()
{int i,j,n;
 char b,a;
 int flag=0,ans;
 while(scanf("%d %c %c",&n,&b,&a)==3)
 {memset(c,0,sizeof(c));
  if(!flag)
        flag=1;
  else
       printf("\n");
  if(n==1)
       {
           printf("%c\n",b);
           continue;
       }
  for(i=n/2;i>=0;i--)
  {if(i==n/2&&((n+1)/2%2)==0)
       {for(j=0;j<n;j++)
          {if(j%2==0)
                c[i][j]=a;
           else
                c[i][j]=b;
           }
        continue;
       }
   else
     if(i==n/2&&((n+1)/2)%2==1)
     {for(j=0;j<n;j++)
          {if(j%2==0)
                c[i][j]=b;
           else
                c[i][j]=a;
           }
        continue;
       }
   for(j=0;j<n;j++)
         c[i][j]=c[i+1][j];
   ans=(n/2-i)*2-1;
   for(j=n/2;j>=n/2-ans/2;j--)
         {if(c[i+1][j]==a)
             c[i][j]=b;
          else
             c[i][j]=a;
          }
    for(j=n/2;j<=n/2+ans/2;j++)
         {if(j==n/2)
                continue;
          else
               {if(c[i+1][j]==a)
                    c[i][j]=b;
                else
                    c[i][j]=a;
               }
           }
     }
     for(i=n/2;i<n;i++)
         {if(i==n/2)
              continue;
          for(j=0;j<n;j++)
              c[i][j]=c[n-1-i][j];
          }
    c[0][0]=' ';
    c[0][n-1]=' ';
    c[n-1][0]=' ';
    c[n-1][n-1]=' ';
    for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
         printf("%c",c[i][j]);
     printf("\n");
     }
   }
   return 0;
}







