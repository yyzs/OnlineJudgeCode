#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX 100010
char a[30],b[30];
int bin[MAX],cnt[MAX];
struct node
{
    struct node *next[80];
    int id;
};
struct node *root;
void insert(char *a,int num)
{
    int i,j,k;
    int len=strlen(a);
    struct node *newnode,*nownode;
    nownode=root;
    for(i=0; i<len; i++)
    {
        int k=a[i]-'A';
        if(nownode->next[k]==NULL)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->id=-1;
            for(j=0; j<80; j++)
                newnode->next[j]=NULL;
            nownode->next[k]=newnode;
            nownode=nownode->next[k];
        }
        else
            nownode=nownode->next[k];
    }
    nownode->id=num;
}
int find(char *a)
{
    int len=strlen(a);
    int i,j,k;
    struct node *now=root;
    for(i=0; i<len; i++)
    {
        k=a[i]-'A';
        if(now->next[k]==NULL)
            return -1;
        now=now->next[k];
    }
    return now->id;
}
int find1(int x)
{
    return bin[x]==x?bin[x]:bin[x]=find1(bin[x]);
}
void DELETE(struct node *now)
{
    int i;
    if(now==NULL)
        return;
    for(i=0;i<60;i++)
    {
        if(now->next[i]!=NULL)
            DELETE(now->next[i]);
    }
    delete(now);
}
int main()
{
    int num,temp;
    int t,n,i,j,ans;
    int fa,fb;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d",&n);
            num=0;
            root=(struct node *)malloc(sizeof(struct node));
            root->id=-1;
            for(i=0; i<80; i++)
                root->next[i]=NULL;
            for(i=0; i<n; i++)
            {
                scanf("%s%s",a,b);
                temp=find(a);
                // printf("temp:%d\n",temp);
                if(temp==-1)
                {
                    bin[num]=num;
                    cnt[num]=1;
                    fa=num;
                    insert(a,num);
                    num++;
                }
                else
                    fa=find1(temp);
                temp=find(b);
                if(temp==-1)
                {
                    bin[num]=num;
                    cnt[num]=1;
                    fb=num;
                    insert(b,num);
                    num++;
                }
                else
                    fb=find1(temp);
                if(fa==fb)
                {
                    printf("%d\n",cnt[fa]);
                    continue;
                }
                if(cnt[fa]<cnt[fb])
                {
                    bin[fa]=fb;
                    cnt[fb]+=cnt[fa];
                    cnt[fa]=0;
                    printf("%d\n",cnt[fb]);
                }
                else
                {
                    bin[fb]=fa;
                    cnt[fa]+=cnt[fb];
                    cnt[fb]=0;
                    printf("%d\n",cnt[fa]);
                }
            }
            DELETE(root);
        }
    }
    return 0;
}

