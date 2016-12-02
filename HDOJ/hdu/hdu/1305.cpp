#include "stdio.h"
#include "malloc.h"
#define kind 10
char str[13];
struct Node
{int end,i;
 Node *next[kind];
 void init()
   {
      end=0;
      for(i=0;i<kind;i++)
            next[i]=NULL;
    }
}node;
int insert(Node *root,char *word)
{Node *p=root;
 int i;
 int t;
 for(i=0;word[i];i++)
    {t=word[i]-'0';
     if(p->next[t]==NULL)
           {p->next[t]=new Node;
            p=p->next[t];
            p->init();
            }
     else
           {p=p->next[t];
            if(!word[i+1])
                  return 0;
            if(p->end==1)
                  return 0;
            }
      if(!word[i+1])
           p->end=1;
      }
  return 1;
}
void remove(Node *root)
{
    int i;
    if(root==NULL)
           return;
    for(i=0;i<kind;i++)
           remove(root->next[i]);
    free(root);
}
int main()
{
 int ok;
 int cas=0;
  while(scanf("%s",str)!=EOF)
  {Node *root=new Node();
  root->init();
  ok=1;
  ok=insert(root,str);
  while(scanf("%s",str))
   {
     if(str[0]=='9')
            break;
     if(ok)
        ok=insert(root,str);
   }
   cas++;
   if(ok)
        printf("Set %d is immediately decodable\n",cas);
   else
        printf("Set %d is not immediately decodable\n",cas);
   remove(root);
  }
  return 0;
}



