#include <stdio.h>
#include <string.h>

int main()
{
    char s1[200003],s2[100002];
    long i,l;
    while (gets(s1))
    {
        gets(s2);
        l = strlen (s1);
        for (i=0;i<l;i++) s1[i+l]=s1[i];
        s1[l+l]='\0';
        if (strstr(s1,s2))printf ("yes\n");
         else printf ("no\n");
    }
    return 0;
}
