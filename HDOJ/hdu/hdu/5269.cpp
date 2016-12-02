#include "stdio.h"
#include "stdlib.h"
#include "algorithm"
#define MAX 50010
#define MOD 998244353
using namespace std;
int a[MAX];
struct node
{
    int temp;
    struct node *next[2];
};
struct node *root;
void init()
{
    int i;
    root=(struct node *)malloc(sizeof(struct node));
    root->temp=0;
    for(i=0; i<2; i++)
        root->next[i]=NULL;
}
int mul(int a,int b)
{
    int ans=1;
    int a1=a,b1=b;
    while(b)
    {
        if(b&1)
            ans=ans*a%MOD;
        a=a*a;
        b/=2;
    }
    return ans;
}
int insert(int n)
{
    struct node *now,*newnode;
    now=root;
    int num=0;
    int ans=0,k=0,i,j;
    while(n||k<=29)
    {
        int temp=n%2;
        k++;
        if(now->next[!temp]!=NULL)
            num=now->next[!temp]->temp;
        else
            num=0;
        ans=ans%MOD+(num%MOD*mul(2,k))%MOD;
        if(now->next[temp]==NULL)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->next[0]=NULL;
            newnode->next[1]=NULL;
            newnode->temp=1;
            now->next[temp]=newnode;
            now=now->next[temp];
        }
        else
        {
            now=now->next[temp];
            now->temp+=1;
        }
        n/=2;
    }
    return ans;
}
int main()
{
    int t,n,i,j;
    long long ans;
    int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        scanf("%d",&n);
        init();
        ans=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n; i++)
            ans=(ans%MOD+insert(a[i])%MOD)%MOD;
        printf("Case #%d: %lld\n",cas,ans);
    };
    return 0;
}

