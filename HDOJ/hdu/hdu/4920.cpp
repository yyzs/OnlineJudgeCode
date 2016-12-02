#include<cstdio>
#include<cstring>
const int maxn = 805;
int a[maxn][maxn];
int b[maxn][maxn];
int buf[maxn][maxn];
int main(){
    int n,tmp,i,j,k;
    
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                scanf("%d",&tmp);
                a[i][j] = tmp % 3;
            }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                scanf("%d",&tmp);
                b[i][j] = tmp % 3;
            }
        memset(buf,0,sizeof(buf));
        for(i = 0; i < n; i ++)
            for(j = 0; j < n; j ++){
                if(!a[i][j])
                    continue;
                for(k = 0; k < n; k ++)
                    buf[i][k] += ((a[i][j] * b[j][k]) % 3);
            }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(j)
                    printf(" ");
                printf("%d",buf[i][j]%3);
            }
            printf("\n");
        }
    }
    return 0;
}
