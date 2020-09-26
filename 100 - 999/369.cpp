#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P  257LL//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
ll n , m , a , b , c , d , e , sz , i , modd;
ll ar [ mxs ];
ll dp [ 101 ] [ 101 ];
ll ncr( ll x , ll y );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>n>>m && n )
    {
        memset( dp , -1, sizeof dp );
        cout<<n<<" things taken "<<m<<" at a time is "<<ncr( n , m )<<" exactly.\n";
    }
    return 0;
}
ll ncr( ll x , ll y )
{
    if ( x == y )return 1;
    if ( y == 1 )return x;
    if ( dp [ x ] [ y ] != -1 )return dp [ x ] [ y ];
    ll xx = ncr( x - 1 , y );
    xx += ncr( x - 1 , y - 1 );
    return ( dp [ x ] [ y ] = xx );
}
