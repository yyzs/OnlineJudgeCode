#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100001]={0};
    int n = 0;
    int i = 0;
    int a[26] = {0};
    while(gets(s))
    {
        n = strlen(s);
        for(i = 0; i < n; i++)
        {
            if(s[i] >= 97 && s[i] <= 122)
            {
                a[s[i]-97]++;
            }
        }
        for(i = 0; i < 26; i++)
        {
            printf("%c:%d\n",97+i,a[i]);
        }
        printf("\n");
        while(i--)
        {
            a[i] = 0;
        }
    }
    return 0;
}

