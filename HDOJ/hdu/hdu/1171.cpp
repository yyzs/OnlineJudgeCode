#include "stdio.h"
int a1[250001],a2[250001],b[55][2];
int main()
{
    int i,j,k,n;
    int ans,sum=0;
    while(scanf("%d",&n)==1&&n>=0)
    {
        sum=0;
        for(i=0;i<n;i++)
                {scanf("%d%d",&b[i][0],&b[i][1]);
                 sum+=b[i][0]*b[i][1];
                }
        for(i=0;i<=sum;i++)
                {a1[i]=0;
                 a2[i]=0;
                }
        for(i=0;i<=b[0][0]*b[0][1];i+=b[0][0])
                a1[i]=1;
        for(i=1;i<n;i++)
                {for(j=0;j<=sum;j++)
                      for(k=0;k<=b[i][0]*b[i][1]&&k+j<=sum;k+=b[i][0])
                         a2[k+j]+=a1[j];
                 for(j=0;j<=sum;j++)
                      {a1[j]=a2[j];
                       a2[j]=0;
                      }
                }
        ans=sum/2;
        for(;ans>=0;ans--)
                if(a1[ans]!=0)
                  {printf("%d %d\n",sum-ans,ans);                  
                   break;}
    }
    return 0;
}
