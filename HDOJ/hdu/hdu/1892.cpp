#include  "stdio.h"
#include  "string.h"
int a[1010][1010];
char s[100];
int c[1010][1010];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x1,int y1,int del)
{
    int i,j;
    for(i=x1;i<=1001;i+=lowbit(i))
            for(j=y1;j<=1001;j+=lowbit(j))
                   c[i][j]+=del;
}
int sum(int x1,int y1)
{
    int i,j;
    int sum=0;
    for(i=x1;i>0;i-=lowbit(i))
          for(j=y1;j>0;j-=lowbit(j))
                sum+=c[i][j];
     return sum;
}
int main()
{
    int t,cas;
    int q;
    int i,j;
    int num;
    int x1,y1,x2,y2,n;
    scanf("%d",&t);
    cas=0;
    while(t--)
    {
         memset(a,0,sizeof(a));
         memset(c,0,sizeof(c));
         cas++;
         printf("Case %d:\n",cas);
         scanf("%d",&q);
         memset(a,0,sizeof(a));
         for(i=1;i<=1001;i++)
             for(j=1;j<=1001;j++)
                   {a[i][j]=1;
                     add(i,j,1);
                   }
         while(q--)
         {
             memset(s,0,sizeof(s));
             scanf("%s",s);
             if(s[0]=='S')
             {scanf("%d%d%d%d",&x1,&y1,&x2,&y2);x1++;y1++,x2++;y2++;
               if(x1>x2)
                      x1^=x2^=x1^=x2;
               if(y1>y2)
                      y1^=y2^=y1^=y2;
                printf("%d\n",sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1));
             }
             if(s[0]=='A')
             {scanf("%d%d%d",&x1,&y1,&n);x1++;y1++;
               a[x1][y1]+=n;
               add(x1,y1,n);
             }
             if(s[0]=='D')
             {
                 scanf("%d%d%d",&x1,&y1,&n);x1++;y1++;
                 if(a[x1][y1]>=n)
                           { a[x1][y1]-=n;
                              add(x1,y1,-n);
                           }
                 else
                            {n=a[x1][y1];
                              a[x1][y1]=0;
                              add(x1,y1,-n);
                            }
             }
             if(s[0]=='M')
             {
                 scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n);x1++;y1++;x2++;y2++;
                 if(a[x1][y1]>=n)
                 {a[x1][y1]-=n;
                   a[x2][y2]+=n;
                   add(x1,y1,-n);
                   add(x2,y2,n);
                 }
                 else
                 {
                   n=a[x1][y1];
                   a[x2][y2]+=a[x1][y1];
                   a[x1][y1]=0;
                   add(x1,y1,-n);
                   add(x2,y2,n);
                 }
             }
         }
    }
    return 0;
}

