#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , g , i , j , k , l , q , ans;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
//bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
void fastscan(int &number)
{
    register int cc;
    number = 0;
    cc = getchar();
    for (; (cc>47 && cc<58); cc=getchar())
        number = number *10 + cc - 48;
}
string s, s2 , s3;
deque < int > dq;
char grid [ 12 ] [ 12 ] , temp [ 12 ] [ 12 ] , in [ 12 ] [ 12 ] , ver [ 12 ] [ 12 ] , ma [ 12 ] [ 12 ];
int row, col, row2,col2;
void brainfuck();
void finder();
int _270();
int _180();
int _90();
int vertical();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while(cin>>n && n )brainfuck();
    return 0;
}
void brainfuck( )
{
    a = 0;
    for ( i = 1; i <= n; i++ )
    {
        cin>>s>>s2;
        for ( j = 0; j != n; j++ )
        {
            grid [ i ] [ j + 1 ] = ma [ i ] [ j + 1 ] = s [ j ];
            in [ i ] [ j + 1 ] = s2 [ j ];
            if ( grid [ i ] [ j + 1 ] != in [ i ] [ j + 1 ] )a = 1;
        }
    }
    if ( !a )cout<<"Pattern "<<++cases<<" was preserved.\n";
    else if ( _90() )cout<<"Pattern "<<++cases<<" was rotated 90 degrees.\n";
    else if ( _180() )cout<<"Pattern "<<++cases<<" was rotated 180 degrees.\n";
    else if ( _270() )cout<<"Pattern "<<++cases<<" was rotated 270 degrees.\n";
    else if ( vertical() )cout<<"Pattern "<<++cases<<" was reflected vertically.\n";
    else if ( _90() )cout<<"Pattern "<<++cases<<" was reflected vertically and rotated 90 degrees.\n";
    else if ( _180() )cout<<"Pattern "<<++cases<<" was reflected vertically and rotated 180 degrees.\n";
    else if ( _270() )cout<<"Pattern "<<++cases<<" was reflected vertically and rotated 270 degrees.\n";
    else cout<<"Pattern "<<++cases<<" was improperly transformed.\n";
}
void finder()
{
    //
}
int _90()
{
    for ( i = 1 ; i <= n; i++ )
        for ( j = 1 , k = n; j <= n; j++ , k-- )temp [ i ] [ j ] = grid [ k ] [ i ];
    for ( i = 1; i <= n; i++ )
        for ( j = 1 ; j <= n; j++ )if ( in [ i ] [ j ] != temp [ i ] [ j ] )return 0;
    return 1;
}
int _180()
{
    for ( i = 1 , k = n ; i <= n; i++ , k-- )
        for ( j = 1 , l = n; j <= n; j++ , l-- )temp [ i ] [ j ] = grid [ k ] [ l ];
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )if ( in [ i ] [ j ] != temp [ i ] [ j ] )return 0;
    return 1;
}
int _270()
{
    for ( i = 1 , k = n; i <= n; i++ , k-- )
        for (  j = 1; j <= n; j++ )temp [ i ] [ j ] = grid [ j ] [ k ];
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )if ( in [ i ] [ j ] != temp [ i ] [ j ] )return 0;
    return 1;
}
int vertical()
{
    a = _180();
    for ( i = 1 ; i <= n; i++ )
        for ( j = 1; j <= n; j++ )grid [ i ] [ j ] = temp [ i ] [ j ];
    if ( n&1 )
        for ( i = 1 ; i <= n; i++ )ver [ i ] [ n / 2 + 1 ] = grid [ i ] [ n / 2 + 1 ];
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1 , k = n; j <= n / 2; j++ , k-- )ver [ i ] [ j ] = grid [ i ] [ k ];
        if ( n&1 ) k = n / 2 , j = n / 2 + 2;
        else k = n / 2 , n / 2 + 1;
        for ( ; j <= n; j++ , k-- )ver [ i ] [ j ] = grid [ i ] [ k ];
    }
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )grid [ i ] [ j ] = ver [ i ] [ j ];
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )if( ver [ i ] [ j ] != in [ i ] [ j ] )return 0;
    return 1;
}
