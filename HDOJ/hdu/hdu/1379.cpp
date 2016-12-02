#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
struct sr
{char a[60];
 int ans;
 }s[120];
 int cmp(struct sr a,struct sr b)
 {
     return a.ans>b.ans;
 }
int main()
{int i,j,k;
 int n,m;
 int len,t;
 scanf("%d",&t);
 while(t--)
 {scanf("%d%d",&n,&m);
  for(i=0;i<m;i++)
          memset(s[i].a,0,sizeof(s[i].a));
  for(i=0;i<m;i++)
          {scanf("%s",s[i].a);
           s[i].ans=0;
           }
  for(i=0;i<m;i++)
          {
           for(j=0;j<n-1;j++)
                  for(k=j+1;k<n;k++)
                     if(s[i].a[j]>s[i].a[k])
                         s[i].ans++;
           }
  sort(s,s+n,cmp);
  for(i=m-1;i>=0;i--)
          printf("%s\n",s[i].a);
  }
  return 0;
  }

