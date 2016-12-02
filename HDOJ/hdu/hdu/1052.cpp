#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
int cmp(int a,int b)
{
     return a>b;
}
int tian[1005],qi[1005];
int main()
{int n,i,j;
  int res,headt,tailt;
  int headq,tailq;
   while(scanf("%d",&n)&&n)
   {memset(tian,0,sizeof(tian));
     memset(qi,0,sizeof(qi));
     for(i=0;i<n;i++)
               scanf("%d",&tian[i]);
     for(i=0;i<n;i++)
               scanf("%d",&qi[i]);
     sort(tian,tian+n,cmp);
     sort(qi,qi+n,cmp);
     res=0;
     headt=0;headq=0;
     tailt=n-1;tailq=n-1;
     for(i=0;i<n;i++)
     {if(qi[headq]>tian[headt])
         {headq++;
           tailt--;
           res-=2;
           }
       else
         if(qi[headq]<tian[headt])
           {headq++;
             headt++;
             res+=2;
             }
       else
         if(qi[headq]==tian[headt])
            {
               if(qi[tailq]<tian[tailt])
                  {tailq--;
                    tailt--;
                    res+=2;
                  }
                else
                  if(qi[tailq]>=tian[tailt])
                    {if(qi[headq]>tian[tailt])
                            res-=2;
                     tailt--;
                     headq++;
                     }
                }
          }
          res*=100;
          printf("%d\n",res);
          }
         return 0;
         }

