#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
const int MAXN=51;
int a[MAXN][MAXN];//增广矩阵
int x[MAXN];//解集
int s[MAXN],e[MAXN],res[MAXN][MAXN];
bool free_x[MAXN];//标记是否是不确定的变元
// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，
//-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
//有equ个方程，var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.
int Gauss(int equ,int var)
{
    int max_r,col,k;
    int free_num=0;
    for(int i=0; i<=var; i++)
    {
        x[i]=0;
        free_x[i]=true;
    }
   col=0;
    for(k = 0; k < equ && col < var; k++,col++)
    {
        max_r=k;
        for(int i=k+1; i<equ; i++)
        {
            if(abs(a[i][col])>abs(a[max_r][col])) max_r=i;
        }
         if(a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col;//这个是自由变元
            continue;
        }
        if(max_r!=k)
        {
            for(int j=col; j<var+1; j++) swap(a[k][j],a[max_r][j]);
        }
        for(int i=k+1; i<equ; i++)
        {
            // 枚举要删去的行.
            if(a[i][col]!=0)
            {
                for(int j=col; j<var+1; j++)
                {
                    a[i][j] ^=a[k][j];
                }
            }
        }
    }
    // 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0).
    for (int i = k; i < equ; i++)
    {
        // 对于无穷解来说，如果要判断哪些是自由变元，那么初等行变换中的交换就会影响，则要记录交换.
        if (a[i][col] != 0) return -1;
    }
    // 2. 无穷解的情况: 在var * (var + 1)的增广阵中出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵.
    // 且出现的行数即为自由变元的个数.
    if (k < var)
        return var - k; // 自由变元有var - k个.
    return 0;
}
int main()
{
    int n,m;
    int t,q;
    int cas=0;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        memset(res,0,sizeof(res));
        for(int i=0;i<m;i++)
        {
                int k,x;
                scanf("%d",&k);
                for(int j=0;j<k;j++)
                        {
                                scanf("%d",&x);
                                a[x-1][i]=1;
                                res[x-1][i]=1;
                        }
        }
        scanf("%d",&q);
        cas++;
        printf("Case %d:\n",cas);
        while(q--)
        {
                for(int i=0;i<n;i++)
                        for(int j=0;j<m;j++)
                                a[i][j]=res[i][j];
                for(int i=0;i<n;i++)
                        scanf("%d",&a[i][m]);
                int ans=Gauss(n,m);
                if(ans==-1)
                        puts("0");
                else
                        printf("%.0lf\n",pow(2.0,ans));
        }
    }
    return 0;
}

