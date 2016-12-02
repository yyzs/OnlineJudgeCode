#include<stdio.h>
#include<math.h>
int fun(int n,int flag)
{
  int t,m;
  m=(int)sqrt(n);
  for(t=2;t<=m;t++)
   if(n%t==0)
   flag=0;
  return flag;
}
int main()
{
    long x,y,sum,flag,i;
    while(scanf("%ld%ld",&x,&y)!=EOF)
    {
      if(x==0&&y==0)
      break;
      flag=1;
      for(i=x;i<=y;i++)
      {
        sum=i*i+i+41;
        flag=fun(sum,flag);
        if(flag==0)
        break;
      }
      if(flag==1)
      printf("OK\n");
      else
      printf("Sorry\n");
    }
}
