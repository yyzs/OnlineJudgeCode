#include<cstdio>
#include<cstring>
#include<algorithm>

const int K = 101;
const int H = 10001;


int k,l,h,m,s[K],sg[H],mex[101];

void init_sg(){
    int i,j;
    sg[0] = 0;
    for(i = 1;i < H;i ++){
        memset(mex,0,sizeof(mex));

        j = 1;
        while(j <= k && i >= s[j]){
            mex[sg[i - s[j]]] = 1;
            j ++;
        }
        j = 0;
        while(mex[j]) j ++;
        sg[i] = j;
    }
}

int main(){
    int tmp,i,j;

    scanf("%d",&k);
    while(k != 0){
        for(i = 1;i <= k;i ++)
            scanf("%d",&s[i]);
        std::sort(s+1,s+k+1);
        init_sg();
        scanf("%d\n",&m);
        for(i = 0;i < m;i ++){
            scanf("%d",&l);
            tmp = 0;
            for(j = 0;j < l;j ++){
                scanf("%d",&h);
                tmp = tmp ^ sg[h];
            }
            if(tmp) putchar('W');
            else putchar('L');
        }
        putchar('\n');
        scanf("%d",&k);
    }
    return 0;
}

