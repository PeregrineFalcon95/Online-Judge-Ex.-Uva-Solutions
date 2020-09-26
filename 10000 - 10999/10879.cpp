#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int m=0;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int sq=sqrt(n);
        int ar[5],p=0;
        for(int i=2; i<=sq; i++)
        {
            if(n%i==0)
            {
                ar[p]=i;
                ar[++p]=n/i;
                ++p;
            }
            if(p==4)break;
        }
        printf("Case #%d: %d = %d * %d = %d * %d\n",++m,n,ar[0],ar[1],ar[2],ar[3]);
    }
    return 0;
}
