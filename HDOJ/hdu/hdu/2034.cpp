#include "stdio.h"
int sort(int c[100],int k)
{
    int i,j,s;
    for(i=0;i<k-1;i++)
      for(j=i+1;j<k;j++)
       if(c[i]>c[j])
        {
            s=c[i];
            c[i]=c[j];
            c[j]=s;
            }
}
int main()
{int n,m;
 int a[100],b[100],ok=1,c[100];
 int i,j,flag,k;/*flag-decide if have cell*/
 while(scanf("%d %d",&n,&m)!=EOF)
  {
    k=0;
    flag=0;
    if(n==0&&m==0)
       break;
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    for(i=0;i<m;i++)
       scanf("%d",&b[i]);/*input*/
    for(i=0;i<n;i++)
      {ok=1;
       for(j=0;j<m;j++)
        if(a[i]==b[j])
           {ok=0;
            break;
           }
        if(ok)
           {c[k++]=a[i];
            flag=1;
           }
        }/*判断是否为，是则输出*/
       if(!flag)
         printf("NULL\n");
        else
         {
             sort(c,k);
             for(i=0;i<k;i++)
              printf("%d ",c[i]);
             printf("\n");
         }
    }
    return 0;
 }

