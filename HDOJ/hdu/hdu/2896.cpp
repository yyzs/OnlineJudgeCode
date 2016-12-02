#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 100010
#include "algorithm"
using namespace std;
int ans[550];
char a[MAX],b[220];
struct node
{
     struct node *next[94];
     struct node *fail;
     int flag,num;
     int  number;
}*q[500010];
struct node *root;
void insert(char a[220],int num)
{
      int len=strlen(a),i,j;
      int k;
      struct node *current,*newnode;
      current=root;
      if(len==0)
               return;
      for(i=0;i<len;i++)
      {
              k=a[i]-33;
              if(current->next[k]==NULL)
              {
                   newnode=(struct node *)malloc(sizeof(struct node));
                   for(j=0;j<94;j++)
                          newnode->next[j]=NULL;
                   newnode->fail=NULL;
                   newnode->num=0;
                   newnode->flag=0;
                   newnode->number=0;
                   current->next[k]=newnode;
                   current=current->next[k];
              }
              else
                   current=current->next[k];
      }
      current->num=num;
      current->number=current->number+1;
}
void buildfail()
{
      struct node *current,*p;
      int first=0,rear=0,i;
      q[rear++]=root;
      while(first!=rear)
      {
          current=q[first++];
          for(i=0;i<94;i++)
          {
              if(current->next[i]==NULL)
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
int find(char a[MAX],int flag)
{
     int len=strlen(a);
     int res=0;
     int i,j,k;
     struct node *current,*p;
     if(len==0)
             return 0;
     current=root;
     for(i=0;i<len;i++)
     {
            k=a[i]-33;
            while(current->next[k]==NULL&&current!=root)
                      current=current->fail;
            current=current->next[k];
            if(current==NULL)
                      current=root;
            p=current;
            while(p!=root&&p->flag!=flag)
            {
                     if(p->number!=0)
                        {ans[res]=p->num;
                          res++;
                        }
                    p->flag=flag;
                    p=p->fail;
            }
     }
     return res;
}
int main()
{
      int i,j,total;
      int n,m;
      int temp;
      total=0;
      scanf("%d",&n);
      root=(struct node *)malloc(sizeof(struct node));
      for(i=0;i<94;i++)
              root->next[i]=NULL;
       root->num=0;
       root->flag=0;
       root->number=0;
       root->fail=NULL;
        for(i=1;i<=n;i++)
      {
           memset(b,0,sizeof(b));
           scanf("%s",b);
           insert(b,i);
      }
      buildfail();
      scanf("%d",&m);
      total=0;
      for(i=1;i<=m;i++)
      {
           memset(ans,0,sizeof(ans));
           scanf("%s",b);
           temp=find(b,i);
           if(temp==0)
                    continue;
           total++;
           sort(ans,ans+temp);
           printf("web %d: ",i);
           for(j=0;j<temp;j++)
           {
                    if(j==0)
                           printf("%d",ans[j]);
                    else
                           printf(" %d",ans[j]);
           }
           printf("\n");
      }
      printf("total: %d\n",total);
      return 0;
}



