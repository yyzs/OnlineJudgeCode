#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"
char a[100];
int change(char s[])
 {
     if(strcmp(s,"B]") == 0)return 0;
     if(strcmp(s,"KB]") == 0)return 1;
     if(strcmp(s,"MB]") == 0)return 2;
     if(strcmp(s,"GB]") == 0)return 3;
     if(strcmp(s,"TB]") == 0)return 4;
     if(strcmp(s,"PB]") == 0)return 5;
     if(strcmp(s,"EB]") == 0)return 6;
     if(strcmp(s,"ZB]") == 0)return 7;
     if(strcmp(s,"YB]") == 0)return 8;
 }
int main()
{
   double ans;
   int t,cas=0,x;
   int m;
   scanf("%d",&t);
   while(t--)
   {
       memset(a,0,sizeof(a));
       scanf("%d[%s",&x,a);
       m=change(a);
       ans=pow(1000.0,m)/pow(1024.0,m);
       ans=1-ans;
       printf("Case #%d: %.2lf%%\n",++cas,ans*100);
     }
     return 0;
}

