#include<bits/stdc++.h>
using namespace std;
#define mxs 100100
#define inf 1999999999
int ar [ mxs ] , marker [ mxs ] , dp [ mxs ];
int n , m  , a , b , c , ans , t , i , mx ,lo, hi , mid;
string s;
vector < int > v;
void solve();
int main()
{
    cin>>t;
    c = t - 1;
    getchar();
    getchar();
    while ( t-- )
    {
        if ( c != t )putchar( 10 );
        n = 0;
        while ( getline( cin , s) )
        {
            if ( !s.size() )break;
            b = s.size();
            a = 0;
            for ( i= 0; i != b; i++ )
            {
                a *= 10;
                a += s [ i ] - '0';
            }
            ar [ ++n ] = a;
        }
        solve();
    }
    return 0;
}
void solve()
{
    marker [ 0 ] = -inf;
    for ( i = 1; i <= n; i++ )marker [ i ] = inf;
    mx = 0;
    for ( i = 1; i <= n; i++ )
    {
        lo = 0; hi = n;
        while ( lo <= hi )
        {
            mid = ( lo + hi ) / 2;
            if ( ar [ i ] <= marker [ mid ] )hi = mid - 1;
            else lo = mid + 1;
        }
        marker [ lo ] = ar [ i ];
        dp [ i ] = lo;
        mx = max( mx , lo );
    }
    printf("Max hits: %d\n",mx );
    for ( i = n; i >= 1; i-- )
    {
        if ( mx == dp [ i ] )
        {
            mx--;
            v.push_back( ar [ i ] );
        }
    }
    while (!v.empty() )
    {
        printf("%d\n",v.back());
        v.pop_back();
    }
}
