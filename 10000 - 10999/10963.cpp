#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e3+7)
#define ll long long int
int n , m , t , a , b , c , d , ans;
//ll ar [ mxs ] ;
int ar [ 22 ];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    d = t - 1;
    while ( t-- )
    {
        if ( t != d )cout<<"\n";
        cin>>c;
        for ( int i = 1; i <= c; i++ )
        {
            cin>>a>>b;
            if ( i == 1 )ans = abs( a - b );
            else if ( ans != abs( a - b ) )ans = -1;
        }
        if ( ans == -1 )cout<<"no\n";
        else cout<<"yes\n";
    }
    return 0;
}

