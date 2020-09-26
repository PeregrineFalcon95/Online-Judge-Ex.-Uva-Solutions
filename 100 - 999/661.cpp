#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e3+7)
#define ll long long int
int n , m , t , a , b , c , d , ans , cases;
//ll ar [ mxs ] ;
int ar [ 22 ];
bool visited [ 22 ];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>n>>c>>m && ( n || m || c ) )
    {
        for ( int i = 1; i <= n; i++ )
        {
            cin>>ar [ i ];
            visited [ i ] = 0;
        }
        ans = 0;
        d = 0;
        while ( c-- )
        {
            cin>>a;
            if ( ans != -1 )
            {
                if ( !visited [ a ] )
                {
                    ans += ar [ a ];
                    d = max( ans , d );
                    if ( ans > m )ans = -1;
                    visited [ a ] = 1;
                }
                else
                {
                    visited [ a ] = 0;
                    ans -= ar [ a ];
                }
            }
        }
        if ( ans == -1 )cout<<"Sequence "<<++cases<<"\nFuse was blown.\n\n";
        else cout<<"Sequence "<<++cases<<"\nFuse was not blown.\nMaximal power consumption was "<<d<<" amperes.\n\n";
    }
    return 0;
}

