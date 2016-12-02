#include<stdio.h>
int main()
{
    int i,c,j,n,m;
    __int64  a[21]={0,0,1},sum;
    for(i=3;i<21;i++)
      a[i]=(i-1)*(a[i-1]+a[i-2]); // 这个算出的时i对夫妻全部错位的
      //种数
      while(scanf("%d",&c)!=EOF)
      {
          while(c--)
          {
              sum=1;
           scanf("%d%d",&n,&m);
            j=1;
           while(j<=m)
            {
             sum=sum*n/j;
             j++;n--;
            }
          printf("%I64d\n",sum*a[m]);
         }

      }
   return 0;
}
