#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        int a,b,e,d,r[n],c[n];
        memset(r, 0, sizeof r);
        for(int i=0; i<n; i++)
        {
            c[i]=0;
            for(int j=0; j<n; j++)
            {
                scanf("%d",&a);
                c[i]+=a;
                r[j]+=a;
            }
        }
        a=b=0;
        for(int i=0; i<n ; i++)
        {
            if(r[i]&1)
            {
                a++;
                e=i;
            }
            if(c[i]&1)
            {
                b++;
                d=i;
            }
        }
        if(a==0&&b==0)printf("OK\n");
        else if(a==1&&b==1)printf("Change bit (%d,%d)\n",++d,++e);
        else printf("Corrupt\n");
    }
    return 0;
}

