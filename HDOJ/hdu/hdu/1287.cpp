#include "stdio.h"
#include "string.h"
#include "ctype.h"
#define Maxn 10000
char b[Maxn];
int a[Maxn];
int main()
{int i,j;
 int n;
 int ok;
 while(scanf("%d",&n)==1)
 {for(i=0;i<n;i++)
     scanf("%d",&a[i]);
 for(i='A';i<='Z';i++)
     {ok=1;
      for(j=0;j<n;j++)
       {if(isupper(a[j]^i))
           b[j]=a[j]^i;
        else
           {ok=0;
            break;
            }
        }
     if(ok)
        break;
     }
   if(i>='A'&&i<='Z')
      puts(b);
    memset(b,0,sizeof(b));
    }
    return 0;
    }

