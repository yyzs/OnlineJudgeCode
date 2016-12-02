#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX  1000001
char a[MAX],b[55];
struct node
{
   int num;
   struct node *next[26];
   struct node *fail;
}*q[500010];
struct node *root;
void insert(char a[55])
{
    int i,len=strlen(a),j,k;
    struct node *current,*newnode;
    current=root;
    for(i=0;i<len;i++)
    {
        k=a[i]-'a';
        if(current->next[k]==NULL)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->num=0;
            for(j=0;j<26;j++)
                  newnode->next[j]=NULL;
            newnode->fail=NULL;
            current->next[k]=newnode;
            current=current->next[k];
        }
        else
            current=current->next[k];
    }
    current->num=current->num+1;
}
void buildfail()
{
    struct node *current,*p;
    int first=0,rear=0,i;
    q[rear++]=root;
    while(first!=rear)
    {
        current=q[first++];
        for(i=0;i<26;i++)
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
                    else
                        p=p->fail;
                }
                if(p==NULL)
                      current->next[i]->fail=root;
            }
            q[rear++]=current->next[i];
        }
    }
}
int find(char a[MAX])
{
    int len=strlen(a),i,j,k,ans=0;
    struct node *current,*p;
    current=root;
    for(i=0;i<len;i++)
    {
        k=a[i]-'a';
        while(current->next[k]==NULL&&current!=root)
                    current=current->fail;
        current=current->next[k];
        if(current==NULL)
                    current=root;
        p=current;
        while(p!=root&&p->num!=-1)
        {
            ans=ans+p->num;
            p->num=-1;
            p=p->fail;
        }
    }
    return ans;
}
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        root=(struct node*)malloc(sizeof(struct node));
        root->num=0;
        root->fail=NULL;
        for(i=0;i<26;i++)
              root->next[i]=NULL;
        for(i=0;i<n;i++)
        {
            scanf("%s",b);
            insert(b);
        }
        buildfail();
        scanf("%s",a);
        printf("%d\n",find(a));
    }
    return 0;
}

