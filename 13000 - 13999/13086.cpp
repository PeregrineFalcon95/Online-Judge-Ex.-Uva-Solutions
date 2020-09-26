#include<bits/stdc++.h>
using namespace std;
#define MOD 1000007LL //2117566807LL//(1e9+7)
#define P  102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll unsigned long long int
ll n , m , a , b , c , t , ans , cases , p , q , r , x , y , z , i , j ;
ll ar [ mxs ];
set < ll > st;
set < ll >::iterator it;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while ( t-- )
    {
        st.clear();
        cin>>n>>m;
        cin>>p>>q>>r>>x>>y>>z;
        for ( i = 1; i <= n; i++ )ar [ i ] = ( ( p * ( i*i ) ) + ( q * i ) + r ) % MOD;
        for ( i = 1; i <= m; i++ )
        {
            a = ( ( ( x * ( i * i ) ) + ( y * i ) + z ) % n ) + 1;
            st.insert( a );
        }
        ans = 0;
        b = inf;
        for ( i = 1 ; i <= n; i++ )
        {
            if ( st.count( i ) == 0 && ar [ i ] < b )
            {
                b = ar [ i ];
                a = i;
            }
        }
        for ( i = 1; i <= n; i++ )
        {
            if ( i == a )continue;
            ans += ( ar [ a ] * ar [ i ] );
        }
        cout<<"Case "<<++cases<<": "<<ans<<"\n";
    }
    return 0;
}
