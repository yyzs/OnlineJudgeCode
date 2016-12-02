#include <iostream>  
#include <sstream>  
#include <algorithm>  
#include <vector>  
#include <queue>  
#include <stack>  
#include <map>  
#include <set>  
#include <bitset>  
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <cmath>  
#include <climits>  
#define maxn 100005  
#define eps 1e-6  
#define mod 10007  
#define INF 99999999  
#define lowbit(x) (x&(-x))  
//#define lson o<<1, L, mid  
//#define rson o<<1 | 1, mid+1, R  
typedef long long LL;  
using namespace std;  
  
char p[maxn];  
int next[maxn];  
int len;  
void get(void)  
{  
    next[0] = next[1] = 0;  
    int i, j;  
    len=strlen(p);  
    for(i = 1; i <= len; i++) {  
        j = next[i];  
        while(j && p[i] != p[j]) j = next[j];  
        next[i+1] = p[i] == p[j] ? j+1 : 0;  
    }  
}  
void work(void)  
{  
    int tmp1 = len - next[len];  
    int tmp2 = len % tmp1;  
    if(tmp2) printf("%d\n", tmp1 - tmp2);  
    else{  
        if(len == tmp1) printf("%d\n", len);  
        else printf("0\n");  
    }  
}  
int main(void)  
{  
    int _;  
    while(scanf("%d", &_)!=EOF) {  
        while(_--){  
            scanf("%s", p);  
            get();  
            work();  
        }  
    }  
    return 0;  
}  

