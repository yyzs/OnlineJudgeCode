#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 800010
using namespace std;
char s[4100][210];
int next[210];
char ans[210],temp[210];
void getnext(char b[210],int m)
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
int kmp(char* str1,char* str2,int len1,int len2)
{ int i=0,j=0;
  for(i=0;i<len1;)
        {
          if(j>len2-1)
              break;
          if(j==-1||str1[i]==str2[j])
          {
              j++;
            i++;
               }
            else
              j=next[j];
        }
   if(j>=len2)
       return i-len2+1;
   else
       return -1;
}
int main()
{
    int n,i,j,k;
    int len1,len2,len;
    int max;
    while(scanf("%d",&n)==1,n)
    {
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        len=strlen(s[0]);
        max=0;
        for(i=0;i<len;i++)
        {
            for(j=len-1;j>=i;j--){
            if(j-i+1<max)
                break;
            int m=0;
            for(k=i;k<=j;k++)
               temp[m++]=s[0][k];
            temp[m]='\0';
            //printf("%s\n",temp);
            memset(next,0,sizeof(next));
            getnext(temp,m);
            int ok=1;
            for(k=1;k<n;k++)
                {len2=strlen(s[k]);
                 if(kmp(s[k],temp,len2,m)==-1)
                      {
                         // printf("%s %s\n",s[k],temp);
                          ok=0;
                          break;
                      }
                }
            if(ok)
            {
                if(max==j-i+1)
                    {if(strcmp(ans,temp)>0)
                         strcpy(ans,temp);
                    }
                else
                    if(max<j-i+1)
                        {strcpy(ans,temp);
                         max=j-i+1;
                        }
            }
           }
       }
        if(max==0)
        {
            puts("IDENTITY LOST");
            continue;
        }
        printf("%s\n",ans);
    }
    return 0;
}

