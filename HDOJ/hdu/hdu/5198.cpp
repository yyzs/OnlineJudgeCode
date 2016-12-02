#include "stdio.h"
#include "string.h"
#define MAX 110
int hash[MAX];
char a[MAX];
int main()
{
    int len,i;
    int num,ok;
    while(scanf("%s",a)!=EOF)
    {
        for(i=0;i<=20;i++)
            hash[i]=0;
        num=0;
        ok=1;
        len=strlen(a);
        for(i=0;i<len;i++)
        {
            if(i==0)
            {
                hash[a[i]-'a']++;
                num++;
                continue;
            }
            if(a[i]==a[i-1])
                hash[a[i]-'a']++;
            else
            {
                if(hash[a[i]-'a'])
                    {ok=0;
                     break;
                    }
                else
                {
                    num++;
                    hash[a[i]-'a']++;
                }
            }
        }
        if(num!=3||!ok)
            {puts("NO");
             continue;
            }
        int num1=0;
        ok=1;
        for(i=0;i<26;i++)
        {
            if(hash[i])
            {
                if(num1)
                {
                    if(hash[i]!=num1)
                        ok=0;
                }
                else
                    num1=hash[i];
            }
        }
        if(ok)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

