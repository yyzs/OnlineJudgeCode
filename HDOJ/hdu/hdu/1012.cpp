#include "stdio.h"
int fab(int i)
{
    if(i==0)
       return 1;
    else
       return fab(i-1)*i;
}
int main()
{
    int i;
    double ans=0;
    printf("n e\n- -----------\n");
    for(i=0;i<=9;i++)
     {
         ans+=(1/(double)fab(i));
        if(i==0||i==1)
          printf("%d %.f\n",i,ans);
        if(i==2)
           printf("%d %.1f\n",i,ans);
        if(i>2)
           printf("%d %.9f\n",i,ans);     
    }
    scanf("%d",&i);
    return 0;
}
