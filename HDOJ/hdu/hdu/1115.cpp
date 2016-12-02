#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    int n, i, j, t;
    double A ;       //有向面积
    double vs;      //各小三角形有向面积
    double cx , cy ;    //重心的位置坐标
    double x1, y1, x2, y2, x3, y3;
    cin >> t;
    while(t--) {
        cx = 0, cy = 0, A = 0;
        cin >> n;
        cin >> x1 >> y1 >> x2 >> y2;
        for(i = 2; i < n; ++i) {
            cin >> x3 >> y3;
            vs = (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1);     //有向面积
            A += vs;
            cx += (x1+x2+x3)*vs, cy += (y1+y2+y3)*vs;
            x2 = x3, y2 = y3;
        }
        cx /= (3.0*A), cy /= (3.0*A);
        printf("%.2lf %.2lf\n", cx, cy);
    }
    return 0;
}

