#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX 110
int ans[MAX],max[MAX];
char str[MAX][MAX];
char a[MAX],b[MAX];
int len;
int dir[11]={0,0,0,3,6,9,12,15,19,22,26};
struct node
{
    struct node *next[26];
    int w;
};
struct node *root;
void insert(char *a,int w)
{
    int i,len1,j;
    struct node *p,*newnode;
    p=root;
    len1=strlen(a);
    for(i=0;i<len1;i++)
    {
        int k=a[i]-'a';
        if(p->next[k]==NULL)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            for(j=0;j<26;j++)
                newnode->next[j]=NULL;
            newnode->w=w;
            p->next[k]=newnode;
            p=p->next[k];
        }
        else
        {
            p=p->next[k];
            p->w+=w;
        }
    }
}
void dfs(struct node *p,int step)
{
    int i;
    if(step==len-1)
        return;
    int beg,end;
    struct node *now;
    beg=dir[a[step]-'0'];
    end=dir[a[step]-'0'+1]-1;
    for(i=beg;i<=end;i++)
    {
        if(p->next[i]==NULL)
            continue;
        now=p->next[i];
        if(now->w>max[step])
            {max[step]=now->w;
             b[step]=i+'a';
             memcpy(str[step],b,step+1);
             ans[step]=i;
            }
        b[step]=i+'a';
        dfs(now,step+1);
    }
}
int main()
{
    int n,m,cas,t,w,i,j;
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        printf("Scenario #%d:\n",cas);
        scanf("%d",&n);
        root=(struct node *)malloc(sizeof(struct node));
        for(j=0;j<=26;j++)
            root->next[j]=NULL;
        root->w=0;
        for(i=1;i<=n;i++)
        {
            scanf("%s%d",a,&w);
            insert(a,w);
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%s",a);
            memset(max,0,sizeof(max));
            memset(b,0,sizeof(b));
            len=strlen(a);
            dfs(root,0);
            for(j=0;j<len-1;j++)
               {
                   if(max[j]==0)
                      puts("MANUALLY");
                   else
                      printf("%s\n",str[j]);
               }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

