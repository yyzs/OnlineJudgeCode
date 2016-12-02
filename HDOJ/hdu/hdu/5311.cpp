#include "stdio.h"
#include "string.h"
char s[110];
char a1[]="anniversary";
char b1[110];
int judge(int n)
{
    for(int i=0; i<n; i++)
    {
        if(s[i]!='a')
            continue;
        for(int j=i; j<n; j++)
        {
            if(j-i+1>11)
                break;
            for(int a=j+1; a<n; a++)
            {
                for(int b=a; b<n; b++)
                {
                    if(b-a+1+j-i+1>11)
                        break;
                    for(int c=b+1; c<n; c++)
                    {
                        for(int d=c; d<n; d++)
                        {
                            if(d-c+1+b-a+1+j-i+1>11)
                                break;
                            if(d-c+1+b-a+1+j-i+1==11)
                            {
                                int len=0;
                                for(int ii=i; ii<=j; ii++)
                                    b1[len++]=s[ii];
                                for(int ii=a; ii<=b; ii++)
                                    b1[len++]=s[ii];
                                for(int ii=c; ii<=d; ii++)
                                    b1[len++]=s[ii];
                                b1[len]='\0';
                                if(strcmp(b1,a1)==0)
                                    return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        if(n<11)
        {
            puts("NO");
            continue;
        }
        if(judge(n))
              puts("YES");
        else
             puts("NO");
    }
    return 0;
}

