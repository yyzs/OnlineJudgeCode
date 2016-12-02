#include "stdio.h"
#include "string.h"
int main()
{
        int x,y,w,n;
        while(scanf("%d%d%d%d",&x,&y,&w,&n)==4)
        {
                int temp=1+x/w;
                int c=n/temp;
                int m=n%temp;
                if(m==0)
                {
                        if(c!=0)
                                c-=1;
                        m=temp;
                }
               // printf("c,m,temp:%d %d %d\n",c,m,temp);
                int ans=c*(x+y)-1;
                if(m==1)
                        ans+=1;
                else
                        ans=ans+1+w*(m-1);
                printf("%d\n",ans);
        }
        return 0;
}

