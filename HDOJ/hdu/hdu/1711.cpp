#include "stdio.h"
#include "string.h"
int n,m,a[1000010],b[10010],next[10010];
int getnext(int b[10010],int m)
{
   int i=0,j=-1;
   next[i]=-1;
   while(i<m-1)
   {
      if(j==-1||b[j]==b[i])
      {i++;
       j++;
       if(b[i]!=b[j])
             next[i]=j;
        else
             next[i]=next[j];
        }
      else
        j=next[j];
    }
}
int kmp(int a[1000010],int b[10010],int n,int m)
{int i=0,j=0;
  for(i=0;i<n;)
  {if(j>m-1)
           break;
    if(j==-1||a[i]==b[j])
          {i++;
           j++;
           }
     else
          j=next[j];
    }
    if(j>=m)
          return i-m+1;
    else
         return -1;
}
int main()
{int t,i,j,res;
  scanf("%d",&t);
  while(t--)
  {memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(next,0,sizeof(next));
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
            scanf("%d",&a[i]);
     for(i=0;i<m;i++)
             scanf("%d",&b[i]);
     getnext(b,m);
    res=kmp(a,b,n,m);
     printf("%d\n",res);
     }
     return 0;
}

