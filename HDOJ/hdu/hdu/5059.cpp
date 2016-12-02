#include "stdio.h"
#include "string.h"
#define MAX 110
char s[MAX];
int main()
{
    long long a,b,c;
    int i,ok;
    int len;
    int beg;
    while(gets(s))
    {
        ok=1;
        len=strlen(s);
        scanf("%I64d%I64d",&a,&b);
        if(len>=18||len==0)
             ok=0;
        c=0;
        if(s[0]=='-')
            beg=1;
        else
            beg=0;
        if(beg==1&&len==1)
            ok=0;
        for(i=beg;i<len;i++)
        {
            if(i==beg&&len!=1)
            {
                if(s[i]=='0')
                {
                    ok=0;
                    break;
                }
            }
            if(!(s[i]>='0'&&s[i]<='9'))
                {
                   ok=0;
                   break;
                }
            c=c*10+s[i]-'0';
        }
        if(beg==1)
           c*=-1;
        if(c<a||c>b)
            ok=0;
        if(c==0&&len!=1)
            ok=0;
        if(ok)
            puts("YES");
        else
           puts("NO");
        getchar();
    }
    return 0;
}



