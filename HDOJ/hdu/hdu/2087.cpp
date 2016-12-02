#include "stdio.h"
#include "string.h"
#define MAX 1001
char  str1[MAX],str2[MAX];
int next1[MAX],next2[MAX];
void getnext1(char b[MAX],int m)
{
   int i=0,j=-1;
   next1[i]=-1;
   while(i<m)
   {
      if(j==-1||b[j]==b[i])
      {i++;
       j++;
       next1[i]=j;
        }
      else
        j=next1[j];
    }
}
void getnext2(char b[MAX],int m)
{
   int i=0,j=-1;
   next2[i]=-1;
   while(i<m)
   {
      if(j==-1||b[j]==b[i])
      {i++;
       j++;
       next2[i]=j;
        }
      else
        j=next2[j];
    }
}
int kmp(char* str1,char* str2,int len1,int len2,int next[MAX])
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
    int n,m;
    int t,i;
    int d;
    long long ans;
    while(scanf("%s",str1)!=EOF)
    {
          memset(next1,0,sizeof(next1));
          memset(next2,0,sizeof(next2));
          if(strcmp(str1,"#")==0)
                     break;
          scanf("%s",str2);
          n=strlen(str1);
          m=strlen(str2);
          getnext2(str2,m);
          t=kmp(str1,str2,n,m,next2);
          if(t==-1)
          {printf("0\n");continue;}
          t-=1;
          //printf("%d\n",t);
          ans=1;
          for(i=0;i<n-t+1;i++)
                   str1[i]=str1[i+t];
          str1[n-t+1]='\0';
          n=n-t+1;
          getnext1(str1,n);
          //for(i=0;i<n;i++)
               // printf("%d\n",next1[i]);
          for(i=m;i<=n;)
          {
                    t=next1[i+1];
                    while(next1[t+1]>m)
                            t=next1[t+1]-1;
                    if(t==m)
                            {i+=m;ans+=1;}
                    else
                           i+=1;
          }
          printf("%I64d\n",ans);
          memset(str1,0,sizeof(str1));
          memset(str2,0,sizeof(str2));
    }
    return 0;
}

