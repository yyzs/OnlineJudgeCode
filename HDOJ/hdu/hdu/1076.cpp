#include "stdio.h"
int leap(int Y)
{
    if ((Y%4==0 && Y%100!=0)||Y%400==0)
         return 1;
    else
         return 0;
}
int main()
{
    int t,y,n,ans,i,count;
    scanf("%d",&t);
    while(t--)
    {   ans=0;count=0;
        scanf("%d%d",&y,&n);
        for(i=y;;i++)
          {
              if(leap(i))
                 ans++;
            if(ans==n)
               {count=i;break;}   
          }
          printf("%d\n",count);
    }
    return 0;
}
