#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int a,b,c,d,ma,mi,t,ar[102];
    while(sc("%d",&t)==1)
    {
        while(t--)
        {
            sc("%d",&a);
            ma=0;
            mi=100;
            while(a--)
            {
                sc("%d",&b);
                if(b>ma)ma=b;
                if(b<mi)mi=b;
            }
            c=2*(ma-mi);
            pi("%d\n",c);
        }
    }
    return 0;
}
