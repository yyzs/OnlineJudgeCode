#include "stdio.h"
#include "string.h"
#define N 1000005
#define kind 26
#include "stdlib.h"
using namespace std;
struct Node
{Node * next[26];
  int flag;
  };
  Node * root;
  int num;
  void insert(char * s)
  {
     Node *p,*q=root;
     int i,j,len=strlen(s);
     for(i=0;i<len;i++)
          {if(q->next[s[i]-'a'])
                     q=q->next[s[i]-'a'];
            else
                    {p=(Node *)malloc(sizeof(Node));
                      p->flag=0;
                      for(j=0;j<kind;j++)
                                  p->next[j]=NULL;
                      q->next[s[i]-'a']=p;
                      q=p;
                      }
            }
       if(!q->flag)
             num++;
        q->flag=1;
    }
int main()
{int i,j;
 char s[N],s1[1005];
 while(gets(s) && s[0]!='#' )
    {
        root = (Node *)malloc(sizeof(Node));
        for(int i=0;i<26;i++) root->next[i]=NULL;
        num=0;
        for(int j=0;j<strlen(s);j++){
            while(s[j++]==' ') ; j--;
            if(j==strlen(s)) break;
            int k=0;
            while(s[j]!=' ' && j<strlen(s)) s1[k++]=s[j++];
            s1[k] = '\0';
            insert(s1);
        }

        printf("%d\n",num);
    }
    return 0;
}


