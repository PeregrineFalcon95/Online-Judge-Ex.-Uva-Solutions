#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int ans=0,a=n,b=m,ar[10];
        while(n<=m)
        {
            memset(ar, 0, sizeof ar);
            a=n;
            while(a)
            {
                b=a%10;
                ar[b]++;
                a/=10;
            }
            n++;
            b=0;
            for(int i=0; i<10; i++){if(ar[i]>1)b++;}
            if(b==0)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
