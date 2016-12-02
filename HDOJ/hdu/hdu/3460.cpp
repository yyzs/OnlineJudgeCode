/*题意:打印机有三种操作，插入，删除，打印.
给你一些单词，问你最少的操作数.
建立字典树，答案是所有节点数*2-最长链
2015.3.31 22:39*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int number,len;
struct node
{
    struct node *next[26];
};
struct node *root;
void insert(char *a)
{
    struct node *now,*newnode;
    int len1,k,i,j;
    int temp;
    len1=strlen(a);
    now=root;
    if(len1>len)
        len=len1;
    for(i=0;i<len1;i++)
    {
        k=a[i]-'a';
        if(now->next[k]==NULL)
        {
            number++;
            newnode=(struct node *)malloc(sizeof(struct node));
            for(j=0;j<26;j++)
                newnode->next[j]=NULL;
            now->next[k]=newnode;
            now=now->next[k];
        }
        else
            now=now->next[k];
    }
}
int main()
{
    int n,i,j;
    char a[60];
    while(scanf("%d",&n)==1)
    {
        number=0;
        len=0;
        root=(struct node *)malloc(sizeof(struct node));
        for(i=0;i<26;i++)
            root->next[i]=NULL;
        for(i=0;i<n;i++)
        {scanf("%s",a);
         insert(a);
        }
        printf("%d\n",number*2-len+n);
    }
}

