#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "vector"
#define MAX 1010
using namespace std;
struct node
{
        char a[110];
        int age;
}node[MAX];
int cmp(struct node a,struct node b)
{
        return a.age>b.age;
}
int main()
{
        int t;
        int n;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                getchar();
                for(int i=0;i<n;i++)
                        gets(node[i].a);
                for(int i=0;i<n;i++)
                        {
                                int e,f,g,h;
                                int len=strlen(node[i].a);
                                e=node[i].a[len-4]-'0';
                                f=node[i].a[len-3]-'0';
                                g=node[i].a[len-2]-'0';
                                h=node[i].a[len-1]-'0';
                                node[i].age=e*1000+f*100+g*10+h;
                        }
                sort(node,node+n,cmp);
                for(int i=0;i<n;i++)
                {
                         int len=strlen(node[i].a);
                         for(int j=0;j<len-5;j++)
                                {
                           //     if((node[i].a[j]>='0'&&node[i].a[j]<='9')||(node[i].a[j]>='a'&&node[i].a[j]<='z')||(node[i].a[j]>='A'&&node[i].a[j]<='Z')||(node[i].a[j]==' '))
                                       printf("%c",node[i].a[j]);
                                }
                        puts("");
                }
        }
        return 0;
}

