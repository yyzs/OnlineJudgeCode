#include <stdio.h>
#include <string.h>
int main()
{
    int i = 0, j = 0, n = 0, len = 0, total = 0;
    char a[51] = {0};
    scanf("%d",&n);
    getchar();
    for(i = 0; i<n; i++)
    {
        total = 0;
        gets(a);
        len = strlen(a);
        if(a[0]>='0' && a[0]<='9')
        {
            printf("no\n");
            continue;
        }
        for(j = 0; j<len; j++)
        {
            if(a[j]>='0'&&a[j]<='9' || a[j]>='a'&&a[j]<='z' || a[j]>='A'&&a[j]<='Z' || a[j] == '_')
                total++;
        }
        if(total == len)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

