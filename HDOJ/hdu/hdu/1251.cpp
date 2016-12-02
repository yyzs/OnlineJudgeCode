#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char a[20];
struct node
{
    struct node *next[26];
    int w;
};
struct node *root=NULL;
void insert(char *a)
{
    int i,len,j;
    len=strlen(a);
    struct node *current,*newnode;
    current=root;
    for(i=0;i<len;i++)
    {
        int k=a[i]-'a';
        if(current->next[k]==NULL)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            for(j=0;j<26;j++)
                newnode->next[j]=NULL;
            newnode->w=1;
            current->next[k]=newnode;
            current=current->next[k];
        }
        else
        {
            current=current->next[k];
            current->w=current->w+1;
        }
    }
}
int find(char *a)
{
    int len,i,j;
    struct node *current;
    current=root;
    len=strlen(a);
    if(len==0)
        return 0;
    for(i=0;i<len;i++)
    {
        int k=a[i]-'a';
        if(current->next[k]!=NULL)
            current=current->next[k];
        else
            return 0;
    }
    return current->w;
}
int main()
{
   int i;
   root=(struct node *)malloc(sizeof(struct node));
   for(i=0;i<26;i++)
       root->next[i]=NULL;
   root->w=0;
   while(gets(a))
   {
       if(strcmp(a,"")==0)
          break;
       insert(a);
   }
   while(scanf("%s",a)!=EOF)
   {
       printf("%d\n",find(a));
   }
   return 0;
}

