#include "stdio.h"
#include "string.h"
#define MAX 100010
char  a[MAX];
int hash[26];
int main()
{
    int len,i,j;
    int num;
    int t;
    long long ans=0;
    scanf("%d",&t);
    while(t--){
        scanf("%s",a);
        scanf("%d",&num);
        len=strlen(a);
        ans=0;
        memset(hash,0,sizeof(hash));
        j=0;
        for(i=0;i<len;i++){
             int flag=0;
             for(;j<len;j++){
                int k=a[j]-'a';
                if(!flag&&j!=0)
                     {
                         flag=1;
                         if(hash[k]>num)
                              break;
                     }
                else
                     {flag=1;
                       hash[k]++;
                     }
                 if(hash[k]>num)
                       break;
             }
             if(j>=len)
                 j=len;
             ans=ans+j-i;
             hash[a[i]-'a']--;
             //printf("%d %d %d\n",i,j,hash[0]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

