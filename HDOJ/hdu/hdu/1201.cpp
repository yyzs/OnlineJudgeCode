#include "stdio.h"
#include "string.h"
int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
int run(int i)
{if((i%4==0&&i%100!=0)||i%400==0)
          return 1;
  return 0;
}
int main()
{int ans;
  int n,i,j;
  int year,mon,date;
  int ok,t;
  scanf("%d",&t);
  while(t--)
  {scanf("%d-%d-%d",&year,&mon,&date);
   ans=0;
   for(i=year;i<=year+18;i++)
    {  a[1]=28;
        if(i!=year+18&&i!=year)
       {if(run(i))
               ans+=366;
         else
               ans+=365;
         continue;
        }
        else
        if(i==year+18)
        {ok=1;
          a[1]=28;
         for(j=0;j<mon;j++)
         {if(run(i))
                 a[1]=29;
           if(j!=mon-1)
                     ans+=a[j];
            else
                    {if(date>a[j])
                              ok=0;
                      ans+=date;
                      }
            }
        }
        else
          if(i==year)
        {a[1]=28;
         if(run(i))
                  a[1]=29;
            for(j=mon-1;j<12;j++)
          {if(j==mon-1)
                    {ans+=(a[j]-date);
                       continue;
                    }
            ans+=a[j];
          }
        }
    }
        if(ok)
                   printf("%d\n",ans);
        else
                   printf("-1\n");
        }
      return 0;
}




