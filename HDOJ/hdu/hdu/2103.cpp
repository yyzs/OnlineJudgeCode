#include "stdio.h"                         
int main()                                 
{                                          
    int n,m,i,j;                              
    int t,a,money=1;                          
    int s=0,ok=1;                             
    scanf("%d",&t);                           
    while(t--)                                
    {   s=0;                                  
        ok=1;                                 
        money=1;                              
        scanf("%d%d",&m,&n);                     
        if(n>m)                               
        {for(i=1;i<=m;i++)                       
          {                                      
              scanf("%d",&a);                       
            if(!ok)                           
               {s+=money;                     
                money*=2;                     
               }                              
            if(a==1)                       
                ok=0;                      
          }                                      
        for(i=m+1;i<=n;i++)                
           {scanf("%d",&a);                
            s+=money;                            
            money*=2;                      
           }                               
        printf("%d",s);                    
        if(s!=0)                           
          printf("0000");                  
        printf(" RMB\n");                  
        }                                        
        else                                     
         {for(i=1;i<=n;i++)                      
          {                                      
              scanf("%d",&a);                       
            if(!ok)                           
               {s+=money;                     
                money*=2;                     
               }                              
            if(a==1)                          
                  ok=0;                       
                                                    
          }                                      
           printf("%d",s);                       
          if(s!=0)                               
            printf("0000");                      
          printf(" RMB\n");                         
         }                                       
    }                                         
}                                          
