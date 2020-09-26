#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , g , i , j , k , l , q , ans , r;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
bool check( int xx , int yy ){return !( xx == 0 || yy == 0 || xx > r || yy > c );}
void fastscan(int &number)
{
    register int cc;
    number = 0;
    cc = getchar();
    for (; (cc>47 && cc<58); cc=getchar())
        number = number *10 + cc - 48;
}
string s, s2 , s3;
int grid [ 102 ] [ 102 ] , temp [ 102 ] [ 102 ];
void brainfuck();
void finder();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while( cin>>n>>r>>c>>k && n )brainfuck();
    return 0;
}
void brainfuck( )
{
    for ( i = 1; i <= r; i++ )
        for ( j = 1; j <= c; j++ )cin>>grid [ i ] [ j ];
    while( k-- )finder();
    for ( i = 1; i <= r; i++ )
    {
        for ( j = 1; j <= c; j++ )
            if ( j != 1 )cout<<" "<<grid [ i ] [ j ];
            else cout<<grid [ i ] [ j ];
        cout<<"\n";
    }
}
void finder()
{
    memset( temp , -1 , sizeof temp );
    for ( i = 1; i <= r; i++ )
        for ( j = 1; j <= c; j++ )
            for ( l = 0 ; l != 4; l++ )
            {
                a = i + fx [ l ];
                b = j + fy [ l ];
                if ( check( a , b ) )
                {
                    e = grid [ i ] [ j ];
                    if ( e != n-1 && grid [ a ] [ b ] == e + 1 )temp [ a ] [ b ] = e;
                    else if ( e == n - 1 && grid [ a ] [ b ] == 0 )temp [ a ] [ b ] = e;
                    //else if( temp [ a ] [ b ] == -1 )temp [ a ] [ b ] = grid [ a ] [ b ];
                }
            }
    for ( i = 1 ; i <= r; i++ )
        for ( j = 1; j <= c; j++ )
            if( temp [ i ] [ j ] != - 1 )grid [ i ] [ j ] = temp [ i ] [ j ];
}

