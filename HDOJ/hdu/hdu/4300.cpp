#include "stdio.h"
#include "string.h"
#define MAX 100010
char match[30];
int hash[26];
char s1[MAX],s2[MAX];
int  next[MAX];
void getnext(char *a,int len){
    int i=-1,j=0;
    next[0]=-1;
    while(j<len){
        if(i == -1 || a[i] == a[j])next[++j]=++i;
        else i=next[i];
    }
}
int KMP(char *t,char *s,int len)
{
    int i,j=0;
    int lent=strlen(t);
    int lens=strlen(s);
    if(lent%2==1)
        i=lent/2+1;
    else
        i=lent/2;
    while(i<lent&&j<lens)
    {
        if(j==-1||t[i]==s[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
    }
    return j;
}
int main()
{
      int n,i,j;
      int t;
      int len;
      int ans;
      scanf("%d",&t);
      while(t--)
      {
          memset(hash,0,sizeof(hash));
          scanf("%s",match);
          for(i=0;i<26;i++)
          {
            hash[match[i]-'a']=i;
          }
          memset(s1,0,sizeof(s1));
          memset(s2,0,sizeof(s2));
          scanf("%s",s1);
          len=strlen(s1);
          for(i=0;i<len;i++)
          {
               s2[i]=hash[s1[i]-'a']+'a';//密文变明文
          }
          getnext(s2,len);
          ans=len-KMP(s1,s2,len);
          if(ans*2==len)
          {printf("%s\n",s1);continue;}
          printf("%s",s1);
          for(j=KMP(s1,s2,len);j<ans;j++)
                   printf("%c",s2[j]);
         printf("\n");
      }
      return 0;
}

