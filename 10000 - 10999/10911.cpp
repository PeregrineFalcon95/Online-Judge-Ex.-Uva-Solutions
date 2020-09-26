#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e6+7)
#define ll long long int
int n , m , a , b , c , d , e , sz ,  r , i , j , cases ;
//ll ar [ mxs ];
string s;
double lol , o_o , mi , ans;
double ar [ 2 ] [ 20 ];
bool visited [ 20 ];
double backtrack( int idx , double sum );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>n && n )
    {
        memset( visited , 0 , sizeof visited );
        n += n;
        for ( i = 1; i <= n; i++ )cin>>s>>ar [ 0 ] [ i ]>>ar [ 1 ] [ i ];
        ans = 0.00;
        cout <<"Case "<<++cases<<": "<< fixed << setprecision(2) << backtrack( 1 , 0.00 )<<"\n";
    }
    return 0;
}
double backtrack( int idx , double sum )
{
    if ( idx > n )return sum;
    double an = 999999999.00 ;
    for ( int k = idx + 1; k <= n; k++ )
    {
        if ( !visited [ k ] )
        {
            lol = ar [ 0 ] [ idx ] - ar [ 0 ] [ k ];
            lol *= lol;
            o_o = ar [ 1 ] [ idx ] - ar [ 1 ] [ k ];
            o_o *= o_o;
            lol += o_o;
            lol = sqrt( lol );
            visited [ idx ] = visited [ k ] = 1;
            int lll = idx;
            while ( visited [ lll ] )lll++;
            an = min( an , backtrack( lll , sum + lol ) );
            visited [ idx ] = visited [ k ] = 0;
        }
    }
    return an;
}

