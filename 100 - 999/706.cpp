#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , i , j , k , q ;
char grid [ 100 ] [ 200 ] ;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
//bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
int ar [ mxs ] ;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
string s , s2 , s3;
deque < int > dq;
int row_s , row_e , col_s , col_e , row , col;
void brainfuck();
void zero();
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while ( cin>>a>>s && a )brainfuck();
    return 0;
}
void brainfuck( )
{
    c = b;
    for ( i = 0; i != s.size(); i++ )
    {
        dq.push_back( s [ i ] - '0' );
    }
    memset( grid , ' ' , sizeof grid );
    row = ( a + a + 3 );
    col = ( a + 2 ) * dq.size() + dq.size() - 1;
    e = 0;
    row_s = 1;
    row_e = a + a + 3;
    while ( !dq.empty() )
    {
        col_s = ( e + 1 ) + ( e * ( a + 2 ) );
        col_e = ( e + 1 ) * ( a + 2 ) + e ;
        e++;
        c = dq.front();
        dq.pop_front();
        if ( !c )zero();
        else if ( c == 1 )one();
        else if ( c == 2 )two();
        else if ( c == 3 )three();
        else if ( c == 4 )four();
        else if ( c == 5 )five();
        else if ( c == 6 )six();
        else if ( c == 7 )seven();
        else if ( c == 8 )eight();
        else if ( c == 9 )nine();
    }
    //cout<<row<<"   "<<col<<endl;
    for ( i = 1; i <= row; i++ )
    {
        for ( j = 1; j <= col; j++ )putchar(grid [ i ] [ j ] );
        putchar(10);
    }
    putchar(10);
}
void zero()
{
    for ( i = col_s + 1; i < col_e; i++ )grid [ row_s ] [ i ] = grid [ row_e ] [ i ] = '-';
    for ( i = row_s + 1; i <= row_s + a; i++ )grid [ i ] [ col_s ] = grid [ i ] [ col_e ] = '|';
    for ( i = row_e - 1; i >= row_e - a; i-- )grid [ i ] [ col_s ] = grid [ i ] [ col_e ] = '|';
}
void one()
{
    for ( i = row_s + 1; i <= row_s + a; i++ )grid [ i ] [ col_e ] = '|';
    for ( i = row_e - 1; i >= row_e - a; i-- )grid [ i ] [ col_e ] = '|';
}
void two()
{
    for ( i = col_s + 1; i < col_e; i++ ) grid [ row_s ] [ i ] = grid [ row_e ] [ i ] = '-';
    for ( i = row_s + 1; i <= row_s + a; i++ ) grid [ i ] [ col_e ] = '|';
    for ( i = row_e - 1; i >= row_e - a; i-- ) grid [ i ] [ col_s ] = '|';
    f = ( row_e + row_s ) / 2;
    for ( i = col_s + 1; i < col_e; i++ )grid [ f ] [ i ] = '-';
}
void three()
{
    for ( i = row_s + 1; i <= row_s + a; i++ )grid [ i ] [ col_e ] = '|';
    for ( i = row_e - 1; i >= row_e - a; i-- )grid [ i ] [ col_e ] = '|';
    for ( i = col_s + 1; i < col_e; i++ )grid [ row_s ] [ i ] = grid [ row_e ] [ i ] = '-';
    f = ( row_e + row_s ) / 2;
    for ( i = col_s + 1; i < col_e; i++ )grid [ f ] [ i ] = '-';
}
void four()
{
    for ( i = row_s + 1; i <= row_s + a; i++ )grid [ i ] [ col_s ] = grid [ i ] [ col_e ] = '|';
    f = ( row_e + row_s ) / 2;
    for ( i = col_s + 1; i < col_e; i++ )grid [ f ] [ i ] = '-';
    for ( i = row_e - 1; i >= row_e - a; i-- )grid [ i ] [ col_e ] = '|';
}
void five()
{
    for ( i = col_s + 1; i < col_e; i++ ) grid [ row_s ] [ i ] = grid [ row_e ] [ i ] = '-';
    f = ( row_e + row_s ) / 2;
    for ( i = col_s + 1; i < col_e; i++ ) grid [ f ] [ i ] = '-';
    for ( i = row_s + 1; i <= row_s + a; i++ ) grid [ i ] [ col_s ] = '|';
    for ( i = row_e - 1; i >= row_e - a; i-- ) grid [ i ] [ col_e ] = '|';
}
void six()
{
    for ( i = col_s + 1; i < col_e; i++ ) grid [ row_s ] [ i ] = grid [ row_e ] [ i ] = '-';
    f = ( row_e + row_s ) / 2;
    for ( i = col_s + 1; i < col_e; i++ ) grid [ f ] [ i ] = '-';
    for ( i = row_s + 1; i <= row_s + a; i++ ) grid [ i ] [ col_s ] = '|';
    for ( i = row_e - 1; i >= row_e - a; i-- ) grid [ i ] [ col_s ] = grid [ i ] [ col_e ] = '|';
}
void seven()
{
    for ( i = row_s + 1; i <= row_s + a; i++ ) grid [ i ] [ col_e ] = '|';
    for ( i = row_e - 1; i >= row_e - a; i-- ) grid [ i ] [ col_e ] = '|';
    for ( i = col_s + 1; i < col_e; i++ ) grid [ row_s ] [ i ] = '-';
}
void eight()
{
    for ( i = col_s + 1; i < col_e; i++ )grid [ row_s ] [ i ] = grid [ row_e ] [ i ] = '-';
    for ( i = row_s + 1; i <= row_s + a; i++ )grid [ i ] [ col_s ] = grid [ i ] [ col_e ] = '|';
    for ( i = row_e - 1; i >= row_e - a; i-- )grid [ i ] [ col_s ] = grid [ i ] [ col_e ] = '|';
    f = ( row_e + row_s ) / 2;
    for ( i = col_s + 1; i < col_e; i++ )grid [ f ] [ i ] = '-';
}
void nine()
{
    for ( i = col_s + 1; i < col_e; i++ )grid [ row_s ] [ i ] = grid [ row_e ] [ i ] = '-';
    for ( i = row_s + 1; i <= row_s + a; i++ )grid [ i ] [ col_s ] = grid [ i ] [ col_e ] = '|';
    for ( i = row_e - 1; i >= row_e - a; i-- )  grid [ i ] [ col_e ] = '|';
    f = ( row_e + row_s ) / 2;
    for ( i = col_s + 1; i < col_e; i++ )grid [ f ] [ i ] = '-';
}
