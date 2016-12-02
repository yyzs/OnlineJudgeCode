#include "stdio.h"
#include "string.h"
int next[1000010];
char s[1000010];
int getnext(char b[1000010],int m)
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
int main()
{
    int n;
    int i;
    int cas=0;
    while(scanf("%d",&n)==1&&n)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        memset(next,0,sizeof(next));
        getnext(s,n);
        printf("Test case #%d\n",++cas);
        for(i=1;i<n;i++)
        {
            if(next[i+1]!=0&&(i+1)%(i+1-next[i+1])==0)
            {
                printf("%d %d\n",i+1,(i+1)/(i+1-next[i+1]));
            }
        }
        printf("\n");
    }
    return 0;
}

