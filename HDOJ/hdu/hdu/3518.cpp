#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 10000000
using namespace std;
const int Max = 200001;

int  num[Max];
int sa[Max], rank1[Max], height[Max];
int wa[Max], wb[Max], wv[Max], wd[Max];

int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int *r, int n, int m)           //  倍增算法 r为待匹配数组  n为总长度 m为字符范围
{
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i ++) wd[i] = 0;
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[wv[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++)
        {
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
        }
    }
}

void calHeight(int *r, int n)            //  求height数组。
{
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) rank1[sa[i]] = i;
    for(i = 0; i < n; height[rank1[i ++]] = k)
    {
        for(k ? k -- : 0, j = sa[rank1[i]-1]; r[i+k] == r[j+k]; k ++);
    }
}
int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int slove(int k,int len)
{
    int i,j;
    int big=0,small=INF;
    int ans=0;
    for(i=1; i<=len; i++)
    {
        if(height[i]>=k)
        {
            big=max(sa[i],big);
            big=max(sa[i-1],big);
            small=min(sa[i],small);
            small=min(sa[i-1],small);
        }
        else
        {
            if(big-small>=k)
                ans++;
            big=0;
            small=INF;
        }
    }
    if(big-small>=k)
        ans++;
    return ans;
}
int main()
{
    char str1[Max];
    int i, m=101,len;
    long long ans;
    while(scanf("%s",str1)!=EOF)
    {
        if(str1[0]=='#')
            break;
        len=strlen(str1);
        for(i=0; i<=len; i++)
            num[i]=str1[i]-'a'+1;
        num[len]=0;
        da(num, len+1 , m);
        calHeight(num, len);
        ans=0;
        for(i=1; i<=len/2; i++)
        {
            ans+=slove(i,len);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

