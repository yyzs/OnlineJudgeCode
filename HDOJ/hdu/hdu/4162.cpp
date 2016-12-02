#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 300010
using namespace std;
char a[MAX];
int b[MAX];
int getmin(int len)
{
    int i=1,j=0,k=0,t;
    while(i<len&&j<len&&k<len)
    {
        t=b[(i+k)%len]-b[(j+k)%len];
        if(t==0)
              k++;
        else{
            if(t>0)
                 i+=k+1;
            else
                j+=k+1;
            if(i==j)
                j++;
            k=0;
        }
    }
    return min(i,j);
}
int main()
{
    int len,i;
    while(scanf("%s",a)!=EOF)
    {
        memset(b,0,sizeof(b));
        len=strlen(a);
        a[len]=a[0];
        for(i=0;i<len;i++)
        {

            int temp=a[i+1]-a[i];
            if(temp<0)
                  temp+=8;
            b[i]=temp;
        }
        int ans=getmin(len);
        for(i=ans;i<len;i++)
            printf("%d",b[i]);
        for(i=0;i<ans;i++)
            printf("%d",b[i]);
        puts("");
    }
    return 0;
}

