#include "stdio.h"
#include "string.h"
int main()
{char a[51];
 int b[4];
 int n,i,j,len,k,count;
  scanf("%d\n",&n);
  for(k=0;k<n;k++)
   {
    count=0;
    memset(a,0,sizeof(a));
    gets(a);
    len=strlen(a);
    for(i=0;i<4;i++)
     b[i]=0;
    for(j=0;j<len;j++)
     {if(a[j]>='A'&&a[j]<='Z')
         b[0]++;
      if(a[j]>='a'&&a[j]<='z')
         b[1]++;
      if(a[j]>='0'&&a[j]<='9')
         b[2]++;
      if(a[j]=='~'||a[j]=='!'||a[j]=='@'||a[j]=='#'||a[j]=='$'||a[j]=='%'||a[j]=='^')
         b[3]++;
     }
     for(j=0;j<4;j++)
      if(b[j])
        count++;
    if(count>=3&&len>=8&&len<=16)
       printf("YES\n");
    else
       printf("NO\n");
     }
    return 0;
}
