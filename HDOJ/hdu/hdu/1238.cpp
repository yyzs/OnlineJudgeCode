#include "stdio.h"
#define INF 10000
#include "string.h"
#include "algorithm"
using namespace std;
int next1[110],next2[110],n;
char match1[110],match2[110];
struct node
{
    int len;
    char s[110];
}node[110];
void getnext(char b[110],int m,int next[110])
{
   int i=0,j=-1;
   next[i]=-1;
   while(i<m)
   {
      if(j==-1||b[j]==b[i])
      {i++;
       j++;
       next[i]=j;
        }
      else
        j=next[j];
    }
}
int cmp(struct node a,struct node b)
{
    return a.len<b.len;
}
int kmp(char  a[110],char  b[110],int n,int m,int next[110])
{int i=0,j=0;
  for(i=0;i<n;)
  {if(j>m-1)
           break;
    if(j==-1||a[i]==b[j])
          {i++;
           j++;
           }
     else
          j=next[j];
    }
    if(j>=m)
          return i-m+1;
    else
         return -1;
}
int slove(int beg,int end)
{
    int i,j=0,ok;
    memset(match1,0,sizeof(match1));
    memset(match2,0,sizeof(match2));
    memset(next1,0,sizeof(next1));
    memset(next2,0,sizeof(next2));
    for(i=beg;i<=end;i++)
         match1[j++]=node[0].s[i];
    j=0;
    for(i=end;i>=beg;i--)
         match2[j++]=node[0].s[i];
    getnext(match1,end-beg+1,next1);
    getnext(match2,end-beg+1,next2);
    ok=1;
    for(j=1;j<n;j++)
    {
          if(kmp(node[j].s,match1,node[j].len,end-beg+1,next1)==-1&&kmp(node[j].s,match2,node[j].len,end-beg+1,next2)==-1)
          {ok=0;
           break;
          }
    }
    if(ok)
        return end-beg+1;
    return 0;
}
int main()
{
    int t,temp;
    int i,k;
    int min,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            memset(node[i].s,0,sizeof(node[i].s));
            scanf("%s",node[i].s);
            node[i].len=strlen(node[i].s);
        }
        sort(node,node+n,cmp);
        ans=0;
        for(i=0;i<node[0].len;i++)
        {
            for(k=i+ans;k<node[0].len;k++)
                  {temp=slove(i,k);
                   if(temp>ans)
                      ans=temp;
                  }
        }
        printf("%d\n",ans);
    }
    return 0;
}

