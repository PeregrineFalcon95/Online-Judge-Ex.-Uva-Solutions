#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(2e5+7)
#define ll long long int
int  n , m , t , a , b , c , d , e , f , i , j , k , q , row , col ;
char grid [ 15 ] [ 15 ] , grid2 [ 15 ] [ 15 ];
int kx[] = {-2,-2,-1,1,-1,1,2,2};
int ky[] = {1,-1,-2,-2,2,2,-1,1};
int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
bool check( int xx , int yy )
{
    return !( xx < 0 || yy < 0 || xx == n || yy == n || grid [ xx ] [ yy ] != '*' );
}
string s;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while ( t-- )
    {
        cin>>n;
        for ( i = 0; i < n; i++ )cin>>grid [ i ];
        q = 0;
        for ( i = 0; i < n; i++ )
        {
            cin>>s;
            for ( j = 0; j != n; j++ )
                if ( s [ j ] == 'x' && grid [ i ] [ j ] == '*' )q = 1;
                else if ( s [ j ] == 'x' )grid [ i ] [ j ] = '0';
        }
        for ( i = 0; i != n; i++ )
            for ( j = 0; j != n; j++ )
            {
                if ( grid [ i ] [ j ] != '0' )continue;
                c = 0;
                for ( k = 0; k != 8; k++ )
                {
                    a = dx [ k ] + i;
                    b = dy [ k ] + j;
                    if ( check( a , b ) )c++;
                }
                grid [ i ] [ j ] = c + '0';
            }

        for ( i = 0; i != n; i++ )
            for ( j = 0; j != n; j++ )if ( grid [ i ] [ j ] == '*' )grid [ i ] [ j ] = '.';
        for ( i = 0; i != n; i++ )cout<<grid [ i ]<<"\n";
        if ( t )cout<<"\n";
    }
    return 0;
}
