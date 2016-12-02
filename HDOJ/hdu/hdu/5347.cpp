#include "stdio.h"
double a[]={1312,2372.3,520.2,932,800.6,1086.5,1402.3,1313.9,1681.0,2080.7,495.8,737.7,577.5,786.5,1011.8,999.6,1251.2,1520.6};
double find(int u)
{
        if(u==35)
                return 1139.9;
        if(u==36)
                return 1350.8;
        if(u==53)
                return 1008.4;
        if(u==54)
                return 1170.4;
        if(u==85)
                return 930;
        if(u==86)
                return 1037;
        return a[u-1];
}
int main()
{
        int u,v;
        double fu,fv;
        while(scanf("%d%d",&u,&v)==2)
        {
                fu=find(u);
                fv=find(v);
                if(fu>fv)
                        puts("FIRST BIGGER");
                else
                        puts("SECOND BIGGER");
        }
        return 0;
}
