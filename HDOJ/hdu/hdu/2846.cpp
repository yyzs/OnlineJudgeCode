#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct tree
{
    int id;
    int num;
    tree *next[27];
}tree;
char s[400];
tree *root=(tree *)malloc(sizeof(tree));
void creat(char str[],int k)
{
    int len=strlen(str);
    tree *p=root,*q;
    for(int i=0;i<len;i++)
    {
        int x=str[i]-'a';
        if(p->next[x]==NULL)
        {
            q=(tree *)malloc(sizeof(tree));
            q->id=k;
            q->num=1;
            for(int j=0;j<27;j++)
                q->next[j]=NULL;
            p->next[x]=q;
        }
        p=p->next[x];
        if(p->id!=k)
        {
            p->id=k;
            p->num++;
        }
    }
}
int find(char str[])
{
    int len=strlen(str);
    tree *p=root;
    for(int i=0;i<len;i++)
    {
        int x=str[i]-'a';
        if(p->next[x])
            p=p->next[x];
        else
            return 0;
    }
    return p->num;
}
void del(tree *root)
{
    for(int i=0;i<27;i++)
    {
        if(root->next[i])
            del(root->next[i]);
    }
    free(root);
}
int main()
{
    int n,m;
    for(int i=0;i<27;i++)
        root->next[i]=NULL;
    root->num=0;
    root->id=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        for(int j=0;j<len;j++)
        {
            creat(s+j,i);
        }
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%s",s);
        printf("%d\n",find(s));
    }
    return 0;
}
