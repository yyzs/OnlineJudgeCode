#include<stdio.h>
int main()
{

int a,i,n,c=0,t=0;
while(scanf("%d",&n)!=EOF)
{
if(n==0) break;
t=0;
c=0;
for(i=0;i<n;i++)
{
scanf("%d",&a);
if(a<c)
t=t+((c-a)*4+5);
else if(a==c)
t=t+5;
else if(a>c)
t=t+((a-c)*6+5);
c=a;
    }
printf("%d\n",t);
}
return 0;
}

