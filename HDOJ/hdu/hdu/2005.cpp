#include "stdio.h"
dic(int a)
{
    if((a%4==0&&a%100!=0)||a%400==0)
      return 1;
    else
      return 0;
}
int main()
{
 int a,b,c,res,i;
 int s1[]={31,29,31,30,31,30,31,31,30,31,30,31},s2[]={31,28,31,30,31,30,31,31,30,31,30,31};
 while(scanf("%d/%d/%d\n",&a,&b,&c)!=EOF)
  {
      res=0;
      if(dic(a))
          for(i=0;i<b-1;i++)
           res+=s1[i];
      else
          for(i=0;i<b-1;i++)
            res+=s2[i];
    res+=c;
    printf("%d\n",res);
    }
    return 0;
}
    int a,b,c;

