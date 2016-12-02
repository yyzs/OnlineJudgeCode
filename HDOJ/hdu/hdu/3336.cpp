#include<iostream>
#include<cstring>
using namespace std;

const int maxn=200002;
char s[maxn];
int next[maxn],n;

int getnext()     //构造next指针 
{
   int i=0,j=next[0]=-1;
   while(i<n)
   {
     if(j==-1||s[i]==s[j])
           next[++i]=++j;
     else 
           j=next[j];
   }
 //for(i=0;i<=n;i++)
    //  printf("%d  ",next[i]);
  // printf("\n");
}

void gettans()
{
  int ren=0,i,k;
  for(i=n;i>=1;i--){
      k=i;     // 换回了 k  
      while(next[k]!=-1) ren++,k=next[k];
      if(ren>10007) ren%=10007;
  }   
  printf("%d\n",ren);
}

int main()
{
  int ca;scanf("%d",&ca);
  while(ca--&&scanf("%d",&n)){
      scanf("%s",s);
      getnext();
     gettans();
  }
  return 0;
}


