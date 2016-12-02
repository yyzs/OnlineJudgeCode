#include "stdio.h"
#include "string.h"
#define MOD 6
#define MAX 1010
#include "vector"
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
mat mul(mat &A,mat &B)
{
    int i,j,k;
    mat C(A.size(),vec(B[0].size()));
    for(i=0;i<A.size();i++){
        for(k=0;k<B.size();k++){
           for(j=0;j<B[0].size();j++){
              C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
           }
        }
    }
    return C;
}
mat pow(mat A,int  n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<A.size();i++){
            B[i][i]=1;
    }
    while(n>0)
    {
        if(n&1)
                B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
int main()
{
    int n,K;
    int i,j;
    int x;
    long long sum=0;
    while(scanf("%d%d",&n,&K)==2,n+K)
    {
        mat A(n,vec(K));
        mat B(K,vec(n));
        mat c(K,vec(K));
        for(i=0;i<n;i++)
        {
            A[i].clear();
        }
        for(i=0;i<K;i++)
        {
            B[i].clear();
            c[i].clear();
        }
        for(i=0;i<n;i++){
            for(j=0;j<K;j++)
               {
                   scanf("%d",&x);
                   A[i].push_back(x);
               }
        }
        for(i=0;i<K;i++)
            for(j=0;j<n;j++)
            {
                 scanf("%d",&x);
                 B[i].push_back(x);
            }
        c=mul(B,A);
       // for(i=0;i<c.size();i++){
          //  for(j=0;j<c[i].size();j++)
             //      printf("%d ",c[i][j]);
            //printf("\n");
        //}
        c=pow(c,n*n-1);
        c=mul(A,c);
        c=mul(c,B);
        sum=0;
        for(i=0;i<c.size();i++)
            for(j=0;j<c[i].size();j++)
               sum+=c[i][j];
        printf("%I64d\n",sum);
    }
    return 0;
}

