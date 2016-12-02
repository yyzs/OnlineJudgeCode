#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "stdlib.h"
#define MAX 2000010
using namespace std;
char b[10001],c[100001][10001];
long long ans;
struct node
{
    struct node *next[26];
    struct node *fail;
    int  num;//是否是结尾
    int  number;//字符串编号
    int num2;
}*q[5000010];
struct node *root;
void insert(char a[10001],int number)
{
    int len,i,j;
    int k;
    struct node *current,*newnode;
    len=strlen(a);
    current=root;
    if(len==0)
        return;
    for(i=0; i<len; i++)
    {
        k=a[i]-'a';
        if(current->next[k]==NULL)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            for(j=0; j<26; j++)
                newnode->next[j]=NULL;
            newnode->fail=NULL;
            newnode->number=0;
            newnode->num=0;
            newnode->num2=0;
            current->next[k]=newnode;
            current=current->next[k];
        }
        else
            current=current->next[k];
    }
    current->num2=current->num2+1;
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
        for(i=0; i<26; i++)
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
void find(char a[10001])
{
    int len,i,k;
    struct node *current,*p;
    len=strlen(a);
    if(len==0)
        return;
    current=root;
    for(i=0; i<len; i++)
    {
        k=a[i]-'a';
        if(k<0||k>=26)
        {
            current=root;
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
                ans+=p->num2;
            p=p->fail;
        }
    }
}
int main()
{
    int n,i,j,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        root=(struct node *)malloc(sizeof(struct node));
        for(i=0; i<26; i++)
            root->next[i]=NULL;
        root->fail=NULL;
        root->num=0;
        root->number=0;
        root->num2=0;
        for(int i=1;i<=m;i++)
        {
                scanf("%s",c[i]);
        }
        for(i=1; i<=n; i++)
        {
            scanf("%s",b);
            insert(b,i);
        }
        buildfail();
        for(int i=1;i<=m;i++)
        {
                ans=0;
                find(c[i]);
                printf("%I64d\n",ans);
        }
    }
    return 0;
}

