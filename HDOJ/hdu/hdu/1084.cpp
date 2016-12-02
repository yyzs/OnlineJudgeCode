#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
struct student
{int slove;
 int hour,min,sec;
 int score;
 int time;
 int place;
 }s[110];
 int cmp2(struct student a,struct student b)
 {
     return a.place<b.place;
 }
int cmp1(struct student a,struct student b)
{
    if(a.slove==b.slove)
           return a.time<b.time;
    return a.slove>b.slove;
}
int main()
{int n;
 int i,j;
 int max;
 int ans;
 int num=0,next;
 while(scanf("%d",&n)==1&&n>0)
 {for(i=0;i<n;i++)
        {scanf("%d%d:%d:%d",&s[i].slove,&s[i].hour,&s[i].min,&s[i].sec);
         s[i].score=(s[i].slove*10+50);
         s[i].time=s[i].hour*3600+s[i].min*60+s[i].sec;
         s[i].place=i;
         }
   sort(s,s+n,cmp1);
   for(i=0;i<n;)
         {
            if(s[i].slove==5||s[i].slove==0)
                {i++;
                 continue;
                }
            num=1;
           for(j=i+1;j<n;j++)
               {if(s[j].slove!=s[i].slove)
                           break;
                else
                           num++;
               }
           next=j;
           if(num==1)
               s[i].score+=5;
            else
              for(j=i;j<i+num/2;j++)
               s[j].score+=5;
           i=next;
         }
    sort(s,s+n,cmp2);
    for(i=0;i<n;i++)
           printf("%d\n",s[i].score);
    printf("\n");
   }
   return 0;
}







