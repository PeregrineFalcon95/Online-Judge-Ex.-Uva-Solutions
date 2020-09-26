#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int ) (1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e6+7)
#define ll long long int
ll n , m , a , b , c , d , e , sz ,  r  , i , t;
//ll ar [ mxs ] ;
string s , ans , token , temp;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ans = "";
    while( getline( cin , s ) )
    {
        n = s.size();
        //cout<<s [ n - 1 ]<<endl;
        //cout<<s [ n - 5 ]<<s [ n - 4 ]<<s [ n - 3 ]<<s [ n - 2 ]<<s [ n - 1 ]<<endl;
        for ( i = 0; i != n; i++ )if ( s [ i ] >= 'A' && s [ i ] <= 'Z' )s [ i ] += 32;
        temp = "";
        stringstream ss ( s );
        while ( ss >> token )
        {
            m = token.size();
            if ( token == "e-n-d" )break;
            temp = "";
            //cout<<token<<endl;
            for ( i = 0; i != m; i++ )if ( ( token [ i ] >= 'a' && token [ i ] <= 'z' ) || token [ i ] == '-' )temp += token [ i ];
            if ( temp.size() > ans.size() )ans = temp;
        }
    }
    cout<<ans<<endl;
    return 0;
}
