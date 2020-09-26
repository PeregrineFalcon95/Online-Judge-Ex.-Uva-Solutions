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
char grid [ 101 ] [ 101 ] , temp [ 101 ] [ 101 ] , ma [ 101 ] [ 101 ];
int row, col, row2,col2;
void brainfuck();
int finder();
void _90();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m && n )brainfuck();
    return 0;
}
void brainfuck( )
{
    for ( i = 1; i <= n; i++ )
    {
        cin>>s;
        for ( j = 0; j != n; j++ )ma [ i ] [ j + 1 ] = s [ j ];
    }
    for ( i = 1 ; i <= m; i++ )
    {
        cin>>s;
        for ( j = 0; j != n; j++ )grid [ i ] [ j + 1 ] = s [ j ];
    }
    a = finder();
    _90();
    b = finder();
    _90();
    c = finder();
    _90();
    d = finder();
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
}
int finder()
{
    e = 0;
    for ( k = 1; k <= n - m + 1; k++ )
        for ( l = 1; l <= n - m + 1 ; l++ )
        {
            f = 0;
            for ( i = 1; i <= m; i++ )
                for ( j = 1; j <= m; j++ )if ( grid [ i ] [ j ] != ma [ l + i - 1 ] [ k + j - 1 ] )f = 1;
            if ( !f )e++;
        }
    return e;
}
void _90()
{
    for ( i = 1 ; i <= m; i++ )
        for ( j = 1 , k = m; j <= m; j++ , k-- )temp [ i ] [ j ] = grid [ k ] [ i ];
    for ( i = 1; i <= n; i++ )
        for ( j = 1 ; j <= m; j++ )grid [ i ] [ j ] = temp [ i ] [ j ];
}
