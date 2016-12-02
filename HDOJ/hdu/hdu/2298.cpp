    #include<iostream>  
    #include<cstdio>  
    #include<cmath>  
      
    using namespace std;  
    const double PI=acos(-1.0);  
    const double g=9.8;  
      
    int main()  
    {  
        int t;  
        double x,y,v;  
        double a,b,c,d,p1,p2;  
        cin>>t;  
        while(t--)  
        {  
            cin>>x>>y>>v;  
            a=g*x*x;  
            b=-2*v*v*x;  
            c=2*v*v*y+g*x*x;  
            d=b*b-4*a*c;  
            if(d<0)  
            {  
                printf("-1\n");  
                continue;  
            }  
            p1=atan((-b+sqrt(d))/a/2);  
            p2=atan((-b-sqrt(d))/a/2);  
            if((p1<0||p1>PI/2)&&(p2<0||p2>PI/2))  
                printf("-1\n");  
            else if(p1<0||p1>PI/2)  
                printf("%.6lf\n",p2);  
            else if(p2<0||p2>PI/2)  
                printf("%.6lf\n",p1);  
            else  
                printf("%.6lf\n",min(p1,p2));  
        }  
        return 0;  
    }  
