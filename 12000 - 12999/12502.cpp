#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    double n,m,z,t,a,b,c;
    while(sc("%lf",&t)==1)
    {
        while(t--)
        {
            sc("%lf%lf%lf",&n,&m,&z);
            c=(n+m)/3;
            b=(z/((n-c)+(m-c)))*(n-c);
            pi("%.0lf\n",b);
        }
    }
    return 0;
}
