#include "stdio.h"
#include "string.h"
#include "math.h"
#include "algorithm"
#define MAX 3030
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
//叉积
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
//点积
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
//绕原点旋转角度B（弧度值），后x,y的变化
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }
}point[MAX];
struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
//两直线相交求交点
//第一个值为0表示直线重合，为1表示平行，为0表示相交,为2是相交
//只有第一个值为2时，交点才有意义
    pair<int,Point> operator &(const Line &b)const
    {
        Point res = s;
        if(sgn((s-e)^(b.s-b.e)) == 0)
        {
            if(sgn((s-b.e)^(b.s-b.e)) == 0)
                return make_pair(0,res);//重合
            else return make_pair(1,res);//平行
        }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return make_pair(2,res);
    }
}line[MAX];
int inter(Line l1,Line l2)
{
    return
        max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
        max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
        max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
        max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
        sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
        sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}
int main()
{
    int n,k;
    int i,j;
    double x,y;
    int len,temp;
    while(scanf("%d",&n)==1)
    {
        len=0;
        int ok=0;
        temp=0;
        while(n--)
        {
            scanf("%d",&k);
            for(i=1;i<=k;i++)
            {
                scanf("%lf%lf",&point[i].x,&point[i].y);
                if(i!=1)
                {
                    line[len].s=point[i-1];
                    line[len].e=point[i];
                    len++;
                    for(j=0;j<temp;j++)
                        if(inter(line[j],line[len-1]))
                    {
                        ok=1;
                        break;
                    }
                }
            }
            temp=len;
        }
        if(ok)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

