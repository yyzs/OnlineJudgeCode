#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "stdlib.h"
#define MAX 2000010
using namespace std;
char a[MAX],b[1005][55];
int ans[1005];
struct node
{
    struct node *next[26];
    struct node *fail;
    int  num;//是否是结尾
    int  number;//字符串编号
}*q[500010];
struct node *root;
void insert(char a[55],int number)
{
     int len,i,j;
     int k;
     struct node *current,*newnode;
     len=strlen(a);
     current=root;
     if(len==0)
                 return;
     for(i=0;i<len;i++)
     {
                 k=a[i]-'A';
                 if(current->next[k]==NULL)
                 {newnode=(struct node *)malloc(sizeof(struct node));
                   for(j=0;j<26;j++)
                         newnode->next[j]=NULL;
                   newnode->fail=NULL;
                   newnode->number=0;
                   newnode->num=0;
                   current->next[k]=newnode;
                   current=current->next[k];
                 }
                 else
                    current=current->next[k];
     }
     current->num=current->num+1;
     current->number=number;
}
void buildfail()
{
    int first=0,rear=0;
    struct node *current,*p;
    int i;
    q[rear++]=root;
    while(first!=rear)
    {
        current=q[first++];
        for(i=0;i<26;i++)
            {if(current->next[i]==NULL)
                       continue;
              if(current==root)
                       current->next[i]->fail=root;
              else
              {
                        p=current->fail;
                        while(p!=NULL)
                        {
                              if(p->next[i]!=NULL)
                              {
                                  current->next[i]->fail=p->next[i];
                                  break;
                              }
                              p=p->fail;
                        }
                        if(p==NULL)
                              current->next[i]->fail=root;
              }
              q[rear++]=current->next[i];
            }
    }
}
void find(char a[MAX])
{
      int len,i,k;
      struct node *current,*p;
      len=strlen(a);
      if(len==0)
              return;
      current=root;
      for(i=0;i<len;i++)
      {
             k=a[i]-'A';
             if(k<0||k>=26)
             {current=root;
               continue;
             }
             while(current->next[k]==NULL&&current!=root)
                    current=current->fail;
             current=current->next[k];
             if(current==NULL)
                    current=root;
             p=current;
             while(p!=root)
             {
                    if(p->num!=0)
                           ans[p->number]++;
                    p=p->fail;
             }
      }
}
int main()
{
     int n,i,j;
     while(scanf("%d",&n)==1)
     {memset(b,0,sizeof(b));
      memset(ans,0,sizeof(ans));
      root=(struct node *)malloc(sizeof(struct node));
     for(i=0;i<26;i++)
              root->next[i]=NULL;
     root->fail=NULL;
     root->num=0;
     root->number=0;
     for(i=1;i<=n;i++)
     {
            scanf("%s",b[i]);
            insert(b[i],i);
     }
     buildfail();
     memset(a,0,sizeof(a));
     scanf("%s",a);
     find(a);
     for(i=1;i<=n;i++)
                if(ans[i]!=0)
                       printf("%s: %d\n",b[i],ans[i]);
     }
    return 0;
}



