#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
struct student
{char num[7],name[10];
  int grade;
}s[100010];
int cmp1(struct student a,struct student b)
{
    return strcmp(a.num,b.num)<0;
}
int cmp2(struct student a,struct student b)
{
    if(strcmp(a.name,b.name)==0)
              return strcmp(a.num,b.num)<0;
   return strcmp(a.name,b.name)<0;
   }
int cmp3(struct student a,struct student b)
{
   if(a.grade==b.grade)
               return strcmp(a.num,b.num)<0;
    return a.grade<b.grade;
   }
int main()
{int n,c;
  int i;
  int cas=0;
 while(scanf("%d%d",&n,&c)==2&&n)
 {for(i=0;i<n;i++)
           {memset(s[i].name,0,sizeof(s[i].name));
             memset(s[i].num,0,sizeof(s[i].num));
             scanf("%s%s%d",s[i].num,s[i].name,&s[i].grade);
             }
    if(c==1)
           sort(s,s+n,cmp1);
    if(c==2)
           sort(s,s+n,cmp2);
    if(c==3)
           sort(s,s+n,cmp3);
      cas++;
     printf("Case %d:\n",cas);
     for(i=0;i<n;i++)
            printf("%s %s %d\n",s[i].num,s[i].name,s[i].grade);
     }
     return 0;
     }

