#include "stdio.h"
#include "string.h"
#include "stdlib.h"
using namespace std;
struct node
{node *next[26];
 char pipei[20];
};
node root;
void insert(char *pi,char *str)
{
  int len=strlen(str);
  int i,j;
  int k;
  node *p=&root,*q;
  for(i=0;i<len;i++)
  {k=str[i]-'a';
   if(p->next[k]==NULL)
       {q=(node *)malloc(sizeof(node));
        for(j=0;j<26;j++)
             q->next[j]=NULL;
        strcpy(q->pipei,"");
        p->next[k]=q;
        p=p->next[k];
        }
    else
       p=p->next[k];
   }
   strcpy(p->pipei,pi);
}
char* find(char *str)
{int len=strlen(str);
 int i,k;
 node *p=&root;
 for(i=0;i<len;i++)
 {k=str[i]-'a';
  if(p->next[k]==NULL)
         break;
  p=p->next[k];
  }
  if(strcmp(p->pipei,"")!=0&&str[i]==0)
           return p->pipei;
  return 0;
};
int main()
{char s1[15], s2[15], s3[15];
 char str[1000];
    int i;
    scanf("%s", s3);
    while(scanf("%s",s1) && strcmp(s1,"END")!=0)
    {
        scanf("%s", s2);
        insert(s1, s2);
    }
    scanf("%s", s3);
    getchar();
    while(gets(str)&&strcmp(str,"END")!=0)
    {
        int len = strlen(str);
        str[len] = ' ';
        str[++len] = 0;
        char ss[1000];
        int k = 0;
        for(i=0; i<len; ++i)
        {
            if(!(str[i]>='a' && str[i]<='z'))
            {
                ss[k] = 0;
                char *t=find(ss);
                if(t)
                    printf("%s", t);
                else
                    printf("%s", ss);
                k = 0;
                if(i != len-1)
                    printf("%c", str[i]);
            }
            else
            {
                ss[k++] = str[i];
            }
        }
        printf("\n");
    }
    return 0;
}

