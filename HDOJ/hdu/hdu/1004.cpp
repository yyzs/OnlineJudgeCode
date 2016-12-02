#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char a[1000][15];
int vis[1000],max,ans;
int main()
{
    int n,i,j;
    while(scanf("%d",&n)==1)
    {max=0;
     ans=0;
     if(n==0)
         break;
     for(i=0;i<n;i++)
         {
             memset(a[i],0,sizeof(a[i]));
             scanf("%s",a[i]);
            vis[i]=0;        
         }   
      for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
         if(!strcmp(a[i],a[j]))
           vis[i]++;
     for(i=0;i<n;i++)
        if(vis[i]>=max)
         {max=vis[i];
          ans=i;}
     printf("%s\n",a[ans]);
    }    
    return 0;
}
