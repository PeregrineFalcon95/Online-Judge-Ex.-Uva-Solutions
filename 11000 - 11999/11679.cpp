#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e3+7)
#define ll long long int
int n , m , a , b , c , d , ans;
//ll ar [ mxs ] ;
int ar [ 22 ];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>b>>n && (b && n ) )
    {
        for ( int i = 1; i <= b; i++ )cin>>ar [ i ];
        while ( n-- )
        {
            cin>>a>>c>>d;
            ar [ a ] -= d;
            ar [ c ] += d;
        }
        a = 0;
        for ( int i = 1; i <= b; i++ )if ( ar [ i ] < 0 )a = -1;
        if ( a == -1 )cout<<"N\n";
        else cout<<"S\n";
    }
    return 0;
}

