#include "stdio.h"
#include "string.h"
#define MAX 1000
int man[MAX][MAX],woman[MAX][MAX];
char a[MAX];
int  ansman[MAX],answoman[MAX];
int  temp[MAX];
char name[MAX];
int n;
int find(int w,int m)
{
    int i;
    for(i=0;i<n;i++)
        if(woman[w][i]==m)
              break;
    return i;
}
void match()
{
    int i,j;
    int ok;
    memset(ansman,-1,sizeof(ansman));
    memset(answoman,-1,sizeof(answoman));
    memset(temp,-1,sizeof(temp));
    while(1)
    {  ok=1;
       for(i=0;i<n;i++)
          {
              if(ansman[i]==-1)
                    {ok=0;
                     temp[i]++;
                     if(answoman[man[i][temp[i]]]==-1)
                                {ansman[i]=temp[i];
                                 answoman[man[i][temp[i]]]=i;
                                 break;
                                 }
                     if(find(man[i][temp[i]],answoman[man[i][temp[i]]])>find(man[i][temp[i]],i))
                                {ansman[i]=temp[i];
                                 ansman[answoman[man[i][temp[i]]]]=-1;
                                 answoman[man[i][temp[i]]]=i;
                                 break;
                                }
                    }
           }
       if(ok)
           break;
    }
}
int main()
{
    int i,j;
    int len;
    int t;
    int flag=1;
    scanf("%d",&t);
    while(t--)
    {
        if(!flag)
              printf("\n");
        flag=0;
        scanf("%d",&n);
        getchar();
        memset(a,0,sizeof(a));
        gets(a);
        memset(man,0,sizeof(man));
        memset(woman,0,sizeof(woman));
        for(j=0;j<n;j++)
        {
           memset(name,0,sizeof(name));
           scanf("%s",name);
           len=strlen(name);
           for(i=2;i<len;i++)
                  man[name[0]-'a'][i-2]=name[i]-'A';
         }
        for(j=0;j<n;j++)
        {
           memset(name,0,sizeof(name));
           scanf("%s",name);
           len=strlen(name);
           for(i=2;i<len;i++)
                  woman[name[0]-'A'][i-2]=name[i]-'a';
         }
        match();
        for(i=0;i<n;i++)
             printf("%c %c\n",i+'a',man[i][ansman[i]]+'A');
      }
      return  0;
}

