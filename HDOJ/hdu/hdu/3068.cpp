#include "stdio.h"
#include "string.h"
#define MAX 220320
char a[MAX],b[MAX];
int r[MAX];
int len;
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
void add()
{
  int i;
  b[0]='$';
  b[1]='#';
  len=strlen(a);
  for(i=0;i<len;i++)
  {b[i*2+2]=a[i];
   b[i*2+3]='#';
  }
  len=len*2+2;
  b[len]='\0';
  //puts(b);
}
void manacher()
{
    int i,j;
    int mx=0,p=0;
    memset(r,0,sizeof(r));
    for(i=1;i<len;i++)
    {
         if(mx>i)
               r[i]=min(r[2*p-i],mx-i);
         else
               r[i]=1;
         while(1)
               { //printf("%d %d\n",i+r[i],i-r[i]);
                 if(b[i+r[i]]==b[i-r[i]])
                       r[i]++;
                 else
                       break;
               }
         if(i+r[i]>mx)
              {mx=i+r[i];
               p=i;
              }
    }
}
void slove()
{
   int ans=0;
   int i;
   add();
   manacher();
   for(i=1;i<=len;i++)
         ans=max(ans,r[i]);
   printf("%d\n",ans-1);
}
int main()
{
    while(scanf("%s",a)!=EOF)
           slove();
    return 0;
}

