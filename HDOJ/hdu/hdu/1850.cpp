#include<iostream>
#include<cstdio>

using namespace std;

int n;
int val[110];

int deal(){
    int one,two;
    int count = 0;
    bool flag = true;
    for(int i = 0;i < n;i ++){
        one = val[i];
        flag = true;
        for(int j = 0;j < n;j ++){
            if(j == i)    continue;
            if(flag){
                flag = false;
                two = val[j];
                continue;
            }
            two ^= val[j];
        }
        if(two < one) count ++;
    }
    return count;
}

bool win(){
    int ans = val[0];
    for(int i = 1;i < n;i ++)
        ans ^= val[i];
    return ans;
}

int main(){
//    freopen("a.in","r",stdin);
    while(~scanf("%d\n",&n) && n){
        for(int i = 0;i < n;i ++)
            scanf("%d",&val[i]);
        if(win())    printf("%d\n",deal());
        else printf("0\n");
    }
    return 0;
}
 

