#include "stdio.h"           
main()                       
{int n,a,sum,i;              
 while(scanf("%d",&n)!=EOF)  
 {sum=0;                     
  for(i=1;i<=n;i++)          
   {scanf(" %d",&a);         
    sum+=a;                  
       }                        
   printf("%d\n",sum);       
   }                         
   return 0;                 
 }                           
                             
