#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
int min(int a,int b)
{
    return a<=b?a:b;
}
int main()
{
    int a[21][11],ans[21][11];
    int n,k;
    int i,j,y,m;
    while(scanf("%d%d",&n,&k)==2)
    { memset(a,0,sizeof(a));
      memset(ans,0,sizeof(ans));
      for(i=0;i<n;i++)
        for(j=0;j<k;j++)
          scanf("%d",&a[i][j]);
      for(i=n-2;i>=0;i--)
         for(j=0;j<k;j++)
          {
              ans[i][j]=ans[i+1][0]+abs(a[i][j]-a[i+1][0]);
              for(y=0;y<k;y++)    
                  ans[i][j]=min(ans[i][j],ans[i+1][y]+abs(a[i][j]-a[i+1][y]));
            }
       m=ans[0][0];
       for(j=0;j<k;j++)
          if(ans[0][j]<m)
            m=ans[0][j];
       printf("%d\n",m);    
    }
    return 0;
}
