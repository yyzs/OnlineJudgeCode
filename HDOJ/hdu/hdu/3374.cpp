#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 1000001
using namespace std;
char a[MAX];
int next[MAX];
int len;
void getnext(char b[MAX],int m)
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
int getmin(int len)
{
    int i=1,j=0,k=0,t;
    while(i<len&&j<len&&k<len)
    {
        t=a[(i+k)%len]-a[(j+k)%len];
        if(t==0)
               k++;
        else{
              if(t>0)
                 i+=k+1;
              else
                 j+=k+1;
              if(i==j)
                  j+=1;
              k=0;
    }
    }
    return min(i,j);
}
int getmax(int len)
{
    int i=1,j=0,k=0,t;
    while(i<len&&j<len&&k<len)
    {
        t=a[(i+k)%len]-a[(j+k)%len];
        if(t==0)
              k++;
        else{
                if(t<0)
                   i+=k+1;
                else
                    j+=k+1;
                if(i==j)
                    j+=1;
               k=0;
        }
    }
    return min(i,j);
}
int main()
{
    int i,ans;
    int mina,maxa;
    while(scanf("%s",a)!=EOF)
    {
        len=strlen(a);
        memset(next,0,sizeof(next));
        getnext(a,len);
        mina=getmin(len);
        maxa=getmax(len);
        ans=len-next[len];
        if(len%ans==0)
               ans=len/ans;
        else
               ans=1;
        printf("%d %d %d %d\n",mina+1,ans,maxa+1,ans);
    }
    return 0;
}

