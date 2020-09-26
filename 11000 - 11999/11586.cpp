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
    cin>>n;
    cin.ignore();
    while ( n-- )
    {
        getline( cin ,s );
        c = s.size();
        a = b = 0;
        for ( int i = 0; i != c; i++ )
        {
            if ( s [ i ] == 'M' )a++;
            else if ( s [ i ] == 'F' )b++;
        }
        if ( a == b && a > 1 && b > 1 )cout<<"LOOP\n";
        else cout<<"NO LOOP\n";
    }
    return 0;
}

