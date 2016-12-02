#include "stdio.h"
#include "string.h"
int map[26][26];
int vis[26][26];
char a[200];
int ok=0;
int dfs(int x,int y)
{
    int i;
    if(y==13||x==13)
             return 1;
    for(i=1;i<=26;i++)
             {
                 if(map[y][i]&&!vis[y][i])
                     {
                         vis[y][i]=1;
                         if(dfs(y,i))
                              return 1;
                     }
             }
    return 0;
}
int main()
{
  int i,j;
  int x,y,len;
  memset(a,0,sizeof(a));
  memset(map,0,sizeof(map));
  while(scanf("%s",a)!=EOF)
   { ok=0;
      memset(map,0,sizeof(map));
      len=strlen(a);
      x=a[0]-'a'+1;
      y=a[len-1]-'a'+1;
      map[x][y]=1;
      memset(a,0,sizeof(a));
      while(scanf("%s",a))
      {
          if(a[0]=='0')
                 break;
          len=strlen(a);
          x=a[0]-'a'+1;
          y=a[len-1]-'a'+1;
          map[x][y]=1;
          memset(a,0,sizeof(a));
      }
      memset(vis,0,sizeof(vis));
      /*for(i=1;i<=26;i++)
         {  printf("%d:",i);
             for(j=1;j<=26;j++)
                 printf("%d ",map[i][j]);
            printf("\n");
         }
        */
      if(map[2][13]==1)
            printf("Yes.\n");
      else
      { for(j=1;j<=26;j++)
            if(map[2][j]==1)
               {vis[2][j]=1;
                 if(dfs(2,j)==1)
                   {
                       ok=1;
                       break;
                   }
               }
      }
        if(ok)
            printf("Yes.\n");
        else
           printf("No.\n");
   }
  return 0;
}
