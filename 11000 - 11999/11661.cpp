#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e4+7)
#define ll long long int
int n , m , t , a , b , c , d , ans , cases;
//ll ar [ mxs ] ;
string s ;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>n && n )
    {
        cin>>s;
        ans = a = INT_MAX;
        b = -999999999;
        for ( int i = 0; i != n; i++ )
        {
            if ( s [ i ] == 'Z' )ans = 0;
            else if ( s [ i ] == 'D' )a = i;
            else if ( s [ i ] == 'R' )b = i;
            ans = min( ans , abs( a - b ) );
        }
        cout<<ans<<"\n";
    }
    return 0;
}

