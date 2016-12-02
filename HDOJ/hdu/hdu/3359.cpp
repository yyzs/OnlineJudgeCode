#include "stdio.h"
#include "string.h"
#define MAX  130
#include "math.h"
#include "algorithm"
#define INF 1e-10
using namespace std;
typedef double Matrix[MAX][MAX];
Matrix a,b;
void gauss(Matrix A, int n) {
    int i, j, k, r;
    for(i = 0; i < n; i++) {
        r = i;
        for(int j = i + 1; j < n; j++) {
            if(fabs(A[j][i]) > fabs(A[r][i])) r = j;
        }
        if(r != i) for(j = 0; j <= n; j++) swap(A[r][j], A[i][j]);

        for(k = i + 1; k < n; k++) {
            double f = A[k][i] / A[i][i];
            for(j = i; j <= n; j++) A[k][j] -= f * A[i][j];
        }
    }

    for(i = n - 1; i >= 0; i--) {
        for(j = i + 1; j < n; j++) {
            A[i][n] -= A[j][n] * A[i][j];
        }
        A[i][n] /= A[i][i];
    }
}
int main()
{
    int w,h,d;
    int n;
    int flag=0;
    while(scanf("%d%d%d",&w,&h,&d)==3,h)
    {
        swap(w,h);
        if(flag)
            puts("");
        flag=1;
        for(int i=0; i<MAX; i++)
            for(int j=0; j<MAX; j++)
                {
                        a[i][j]=0;
                        b[i][j]=0;
                }
        for(int i=0; i<w; i++)
            for(int j=0; j<h; j++)
                scanf("%lf",&b[i][j]);
        for(int i=0; i<w; i++)
            for(int j=0; j<h; j++)
            {
                for(int x=0; x<w; x++)
                    for(int y=0; y<h; y++)
                    {
                        if(abs(x-i)+abs(y-j)<=d)
                        {
                            int num1=i*h+j;
                            int num2=x*h+y;
                            a[num1][num2]=1;
                            a[num2][num1]=1;
                        }
                    }
            }
        n=w*h;
        for(int i=0; i<n; i++)
        {
            int num=0;
            for(int j=0; j<n; j++)
                if(fabs(a[i][j])>INF)
                    num++;
            a[i][n]=(double)num*b[i/h][i%h];
        }
       gauss(a,n);
        for(int i=0; i<n; i++)
        {
            printf("%8.2lf",a[i][n]);
            if((i+1)%h==0)
                puts("");
        }
    }
    return 0;
}

