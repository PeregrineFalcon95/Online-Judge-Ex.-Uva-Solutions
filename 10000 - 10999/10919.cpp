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
map < string , int > mp;
string s;
int ar [ 110 ];
int marker [ 110 ];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>n && n )
    {
        cin>>m;
        mp.clear();
        memset( ar , 0 , sizeof ar );
        for ( int i = 1; i <= n; i++ )
        {
            cin>>s;
            mp [ s ] = 1;
        }
        for ( int i = 1; i <= m; i++ )
        {
            cin>>c>>b;
            marker [ i ] = b;
            while ( c-- )
            {
                cin>>s;
                if ( mp.find( s ) != mp.end() )ar [ i ]++;
            }
        }
        ans = 0;
        for ( int i = 1; i <= m; i++ )if ( marker [ i ] > ar [ i ] )ans = -1;
        if ( ans != -1 )cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}

