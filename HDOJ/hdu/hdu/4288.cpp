#include "stdio.h"
#include "string.h"
char a[20];
int s[100005];
int main()
{
    int n,i,len,j;
    int ok,x,temp;
    long long sum;
    while(scanf("%d",&n)==1)
    {
        len=0;
        while(n--)
        {
            scanf("%s",a);
            if(a[0]=='a')
            {
                scanf("%d",&x);
                for(i=len++; i>0; i--)
                {
                    if(s[i-1]>x)
                           s[i]=s[i-1];
                    else
                           break;
                }
                s[i]=x;
            }
            else if(a[0]=='d')
            {
                scanf("%d",&x);
                for(i=0; i<len; i++)
                    if(s[i]==x)
                        break;
                for(j=i; j<len-1; j++)
                    s[j]=s[j+1];
                len-=1;
            }
            else
            {
                sum=0;
                for(i=0;; i++)
                {
                    temp=i*5+3-1;
                    if(temp>=len)
                        break;
                    sum+=s[temp];
                }
                printf("%I64d\n",sum);
            }
        }
    }
    return 0;
}

