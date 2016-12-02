#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
struct stu
{char name[200];
 int min,sec;
 int time;
 int id,rank;
}s[15];
int cmp1(struct stu a,struct stu b)
{
      if(a.time==b.time)
             return strcmp(a.name,b.name)<0;
      return a.time<b.time;
}
int main()
{
int n,i,j;
 int cas=0;
 while(scanf("%d",&n)==1&&n)
 {if(cas!=0)
        printf("\n");
  for(i=0;i<n;i++)
         {scanf("%s%d:%d",s[i].name,&s[i].min,&s[i].sec);
          s[i].id=i;
          s[i].time=s[i].min*60+s[i].sec;
          }
  sort(s,s+n,cmp1);
  for(i=0;i<n;i++)
          {
              if(i==0)
                   {
                       s[i].rank=1;
                       continue;
                   }
              if(s[i].time==s[i-1].time)
                    s[i].rank=s[i-1].rank;
              else
                    s[i].rank=i+1;
          }
  cas++;
  printf("Case #%d\n",cas);
  for(i=0;i<n;i++)
          printf("%s %d\n",s[i].name,s[i].rank);
  }
  return 0;
  }

