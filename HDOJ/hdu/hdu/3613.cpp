#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define INF 100000000
#define  MAX   500000+10
using namespace std;
char s1[MAX],s2[MAX];
int next[MAX],sum[MAX],val[27];
int per[MAX],pos[MAX];

void get_next(char *a,int len){
    int i=-1,j=0;
    next[0]=-1;
    while(j<len){
        if(i == -1 || a[i] == a[j])next[++j]=++i;
        else i=next[i];
    }
}

int KMP(char *a,char *b,int len){
    int i=0,j=0;
    while(i<len && j<len){
        if(i == -1 || a[i] == b[j])++i,++j;
        else i=next[i];
    }
    return i;
}

int main(){
    int n,k;
    int ans,num;
    int len;
    scanf("%d",&n);
    while(n--){
        for(int i=0;i<27;++i)
                 scanf("%d",&val[i]);
        scanf("%s",s1);
        len=strlen(s1);
        for(int i=0;i<len;++i)
                  {s2[i]=s1[len-1-i];
                   sum[i+1]=sum[i]+val[s1[i]-'a'];
                  }
        get_next(s1,len);
        k=KMP(s1,s2,len);
        while(k)
                {per[k]=n+1;
                 k=next[k];
                }
        get_next(s2,len);
        k=KMP(s2,s1,len);
        while(k)
                {pos[k]=n+1;
                 k=next[k];
                }
        ans=-INF;
        num=0;
        for(int i=1;i<len;++i)
        {
            if(per[i] == n+1)num+=sum[i];
            if(pos[len-i] == n+1)num+=sum[len]-sum[i];
            if(num>ans)ans=num;
            num=0;
        }
        printf("%d\n",ans);
    }
}

