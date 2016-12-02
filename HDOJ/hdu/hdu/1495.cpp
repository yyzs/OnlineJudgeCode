#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct node{
       int x[3];
       int len;
       };

queue<node> q;

int map[101][101][101];
int dx[3];
double isok;

void bfs(int x,int y,int z)
{
    while(!q.empty())
      {q.pop();}   
      node p;
      p.x[0]=x;
      p.x[1]=y;
      p.x[2]=z;
      p.len=0;
      q.push(p);     
      while(!q.empty())    
      {
          node p=q.front();   
          q.pop();               
          for(int i=0;i<3;i++)
          for(int j=0;j<3;j++)
          {                      
                  if(j==i)    
                   continue;                                            
                   node p1;
                   if(p.x[i]<=dx[j]-p.x[j])         
                   {
                          p1.x[j]=p.x[j]+p.x[i];
                          p1.x[i]=0;
                   }
                   else                          
                   {
                         p1.x[i]=p.x[i]-(dx[j]-p.x[j]);
                         p1.x[j]=dx[j]; 
                   }
                   for(int ii=0;ii<3;ii++)            
                   {  if(ii==i||ii==j)
                          continue;
                          p1.x[ii]=p.x[ii];    
                   }        
                  p1.len=p.len;               
                  if(map[p1.x[0]][p1.x[1]][p1.x[2]]==1)    
                   continue; 
                  map[p1.x[0]][p1.x[1]][p1.x[2]]=1;        
                  p1.len++;                                
                  q.push(p1);                               
                  if((isok==p1.x[0]&&p1.x[0]==p1.x[1])||(isok==p1.x[0]&&p1.x[0]==p1.x[2])||(isok==p1.x[1]&&p1.x[1]==p1.x[2]))
                   {printf("%d\n",p1.len);return;}                                                                            
          }
      }
      printf("NO\n");
}

int main()
{
    int s,n,m;
    while(scanf("%d%d%d",&s,&n,&m)!=EOF&&!(s==0&&n==0&&m==0))
    {
          memset(map,0,sizeof(map));
          dx[0]=s;
          dx[1]=n;
          dx[2]=m;
          isok=s/2.0;
          bfs(s,0,0);
    }
    return 0;
}
