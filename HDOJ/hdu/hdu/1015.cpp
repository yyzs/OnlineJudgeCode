#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
const int MAXN=1000000;
char a[MAXN];
int b[MAXN];
//v - w^2 + x^3 - y^4 + z^5
int target;
int main()
{
    int i,j;
    int v,w,x,y,z;
    char c;
    int len;
    int ok;
    while(scanf("%d%s",&target,a)!=EOF)
    {
        if(target==0&&strcmp(a,"END")==0)
            break;
        len=strlen(a);
        for(j=0; j<len-1; j++)
            for(i=0; i<len-1-j; i++)
            {
                if(a[i]<a[i+1])//数组元素大小按升序排列
                {
                    c=a[i];
                    a[i]=a[i+1];
                    a[i+1]=c;
                }
            }
        for(i=0; i<len; i++)
            b[i]=a[i]-'A'+1;
        ok=0;
        for(v=0; v<len; v++)
        {
            for(w=0; w<len; w++)
            {
                if(v==w)
                    continue;
                for(x=0; x<len; x++)
                {
                    if(x==v||x==w)
                        continue;
                    for(y=0; y<len; y++)
                    {
                        if(y==x||y==v||y==w)
                            continue;
                        for(z=0; z<len; z++)
                        {
                            if(z==v||z==w||z==x||z==y)
                                continue;
                             //printf("%c%c%c%c%c",a[v],a[w],a[x],a[y],a[z]);
                             //printf("\n");
                            if(b[v]-b[w]*b[w]+b[x]*b[x]*b[x]-b[y]*b[y]*b[y]*b[y]+b[z]*b[z]*b[z]*b[z]*b[z]==target)
                            {
                                ok=1;
                                break;
                            }
                        }
                        if(ok)
                            break;
                    }
                    if(ok)
                        break;
                }
                if(ok)
                    break;
            }
            if(ok)
                break;
        }
        if(ok)
        {
            printf("%c%c%c%c%c",a[v],a[w],a[x],a[y],a[z]);
            printf("\n");
        }
        else
            puts("no solution");
    }
    return 0;
}

