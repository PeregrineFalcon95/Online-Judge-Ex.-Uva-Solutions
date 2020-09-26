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
char  grid [ 12 ] [ 12 ] , temp [ 12 ] [ 12 ];
int row, col, row2,col2;
void brainfuck();
void finder();
void row_();
void col_();
void inc_();
void dec_();
void tra_();
int main()
{
    //cout<<(-1 + 10)%10;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck( )
{
    cin>>n;
    for ( i = 1; i <= n; i++ )
    {
        cin>>s;
        for ( j = 0; j != n; j++ )grid [ i ] [ j + 1 ] = s [ j ];
    }
    cin>>m;
    while( m-- )finder();
    cout<<"Case #"<<++cases<<"\n";
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1 ; j <= n; j++ )cout<<grid [ i ] [ j ];
        cout<<"\n";
    }
    cout<<"\n";
}
void finder()
{
    cin>>s;
    if ( s == "row" )
    {
        cin>>a>>b;
        row_();
    }
    else if ( s == "col" )
    {
        cin>>a>>b;
        col_();
    }
    else if ( s == "inc" )inc_();
    else if ( s == "dec" )dec_();
    else if ( s == "transpose" )tra_();
}
void row_()
{
    for ( i = 1; i <= n; i++ )swap( grid [ a ] [ i ] , grid [ b ] [ i ] );
}
void col_()
{
    for ( i = 1; i <= n; i++ )swap( grid [ i ] [ b ] , grid [ i ] [ a ] );
}
void inc_()
{
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )
        {
            grid [ i ] [ j ]++;
            if( grid [ i ] [ j ] > '9' )grid [ i ] [ j ] = '0';
        }
}
void dec_()
{
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )
        {
            grid [ i ] [ j ]--;
            if ( grid [ i ] [ j ] < '0' )grid [ i ] [ j ] = '9';
        }
}
void tra_()
{
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )
            temp [ i ] [ j ] = grid [ j ] [ i ];
    for ( i = 1;  i <= n; i++ )
        for ( j = 1; j <= n; j++ )grid [ i ] [ j ] = temp [ i ] [ j ];
}
