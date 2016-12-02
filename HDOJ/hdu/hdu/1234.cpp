#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
struct student
{char name[20];
 int a,b,c,d,e,f;
}s[100];
int cmp1(struct student m,struct student n)
{
   if(m.a==n.a)
        {if(m.b==n.b)
           {
             return m.c<n.c;
           }
          else
            return m.b<n.b;
        }
    else
        return m.a<n.a;
}
int cmp2(struct student m,struct student n)
{
   if(m.d==n.d)
        {if(m.e==n.e)
           {
             return m.f>n.f;
           }
          else
            return m.e>n.e;
        }
    else
        return m.d>n.d;
}

int main()
{int i,j,m;
 int t;
 scanf("%d",&t);
 while(t--)
 {for(i=0;i<100;i++)
          memset(s[i].name,0,sizeof(s[0].name));
  scanf("%d",&m);
  for(i=0;i<m;i++)
          scanf("%s%d:%d:%d%d:%d:%d",s[i].name,&s[i].a,&s[i].b,&s[i].c,&s[i].d,&s[i].e,&s[i].f);
  sort(s,s+m,cmp1);
  printf("%s",s[0].name);
  sort(s,s+m,cmp2);
  printf(" %s\n",s[0].name);
  }
  return 0;
}

