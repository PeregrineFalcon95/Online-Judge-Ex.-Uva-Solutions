#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,r,a,sum;
    while(scanf("%d%d%d",&n,&d,&r)==3 && (n!=0 || d!=0 || r!=0))
    {
        int day[n],night[n];
        for( int i = 0; i < n; i++ )
        {
            scanf("%d",&a);
            day[ i ] = a;
        }
        for( int i = 0; i < n; i++ )
        {
            scanf("%d",&a);
            night [ i ] = a;
        }
        sort(day,day+n);
        sort(night,night+n);
        reverse(night,night+n);
        int ans = 0;
        for( int i = 0; i != n; i++)
        {
            sum = day[ i ] + night [ i ];
            if((( sum - d ) * r ) > 0) ans += (( sum - d ) * r );
        }
        printf("%d\n",ans);
    }
    return 0;
}
