#include "stdio.h"
#include "string.h"
#include "algorithm"
char ans[10001][110];
int minSub(char *p)
{
    int i=0,j=1,len=strlen(p),k=0;
    while(i<len&&j<len&&k<len)
    {
        if(k==len)  break;
        if(i==j)  j++;
        int ni=i+k,nj=j+k;
        if(ni>=len) ni-=len;
        if(nj>=len)   nj-=len;
        if(p[ni] > p[nj]) {i+=k+1;k=0;}
        else  if(p[ni]<p[nj])  {j+=k+1;k=0;}
        else k++;
    }
    return i;
}
int main()
{
    int i,j;
    int n;
    int res,len,temp;
    int ok;
    char a[220];
    char b[220];
    while(scanf("%d",&n)==1)
    {
        res=0;
        memset(ans,0,sizeof(ans));
        for(i=0;i<n;i++)
        {
            scanf("%s",a);
            temp=minSub(a);
            len=strlen(a);
            for(j=0;j<len;j++)
                  a[j+len]=a[j];
            memset(b,0,sizeof(b));
            for(j=temp;j<temp+len;j++)
                   b[j-temp]=a[j];
            ok=0;
            for(j=0;j<res;j++)
                   if(strcmp(b,ans[j])==0){
                     ok=1;
                     break;
                   }
            if(!ok)
                {strcpy(ans[res],b);
                 res++;
                }
        }
        printf("%d\n",res);
    }
    return 0;
}


