#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(2e5+7)
#define ll long long int
int  n , m , t , a , b , c , d , e , f , i , j , k , q , row , col ;
char grid [ 10 ] [ 10 ];
int dx[] = {-2,-2,-1,1,-1,1,2,2};
int dy[] = {1,-1,-2,-2,2,2,-1,1};
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
string s;
void pp();
void PP();
void rr();
void bb();
void qq();
void kk();
void nn();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>s )
    {
        a = b = 1;
        memset( grid , '.' , sizeof grid );
        for ( i = 0; i != s.size(); i++ )
        {
            if ( s [ i ] == '/' )
            {
                a = 1;
                b++;
                continue;
            }
            if ( s [ i ] >= '0' && s [ i ] <= '8' )
            {
                c = s [ i ] - '0';
                a += c;
            }
            else grid [ b ] [ a++ ] = s [ i ];
        }
        char ch;
        for ( i = 1; i <= 8; i++ )
            for ( j = 1; j <= 8; j++ )
            {
                ch = grid [ i ] [ j ];
                if ( ch == 'p' )pp();
                else if ( ch == 'P' )PP();
                else if ( ch == 'K' || ch == 'k' )kk();
                else if ( ch == 'r' || ch == 'R' )rr();
                else if ( ch == 'q' || ch == 'Q' )qq();
                else if ( ch == 'b' || ch == 'B' )bb();
                else if ( ch == 'n' || ch == 'N' )nn();
            }
        a = 0;
        for ( i = 1; i <= 8; i++ )
            for ( j = 1; j <= 8; j++ )if ( grid [ i ] [ j ] == '.' )a++;
        //for ( i = 1; i <= 8; i++ )
        //{
        //    for ( j = 1; j <= 8; j++ )cout<<grid [ i ] [ j ]<<" ";
        //    cout<<endl;
        //}
        cout<<a<<"\n";
    }
    return 0;
}
void pp()
{
    a = i;
    b = j;
    if ( a + 1 <= 8 && b + 1 <= 8 && grid [ a + 1 ] [ b + 1 ] == '.' )grid [ a + 1 ] [ b + 1 ] = '!';
    if ( a + 1 <= 8 && b - 1 > 0 && grid [ a + 1 ] [ b - 1 ] == '.' )grid [ a + 1 ] [ b - 1 ] = '!';
}
void PP()
{
    a = i;
    b = j;
    if ( a - 1 > 0 && b + 1 <= 8 && grid [ a - 1 ] [ b + 1 ] == '.' )grid [ a - 1 ] [ b + 1 ] = '!';
    if ( a - 1 > 0 && b - 1 > 0 && grid [ a - 1 ] [ b - 1 ] == '.' )grid [ a - 1 ] [ b - 1 ] = '!';
}
void rr()
{
    a = i;
    b = j;
    while ( a < 8 )
    {
        a++;
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    a = i;
    while ( --a )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    a = i;
    while ( b < 8 )
    {
        b++;
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    b = j;
    while ( --b )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
}
void bb()
{
    a = i;
    b = j;
    while ( --a && --b )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    a = i;
    b = j;
    while ( --a && ++b <= 8 )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    a = i;
    b = j;
    while ( ++a <= 8 && ++b <= 8 )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    a = i;
    b = j;
    while ( ++a <= 8 && --b > 0 )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
}
void qq()
{
    a = i;
    b = j;
    while ( a < 8 )
    {
        a++;
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    a = i;
    while ( --a )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    a = i;
    while ( b < 8 )
    {
        b++;
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    b = j;
    while ( --b )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    //Diagonally
    a = i;
    b = j;
    while ( --a && --b )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    a = i;
    b = j;
    while ( --a && ++b <= 8 )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    a = i;
    b = j;
    while ( ++a <= 8 && ++b <= 8 )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
    a = i;
    b = j;
    while ( ++a <= 8 && --b > 0 )
    {
        if ( ( grid [ a ] [ b ] >= 'a' && grid [ a ] [ b ] <= 'z' ) || ( grid [ a ] [ b ] >= 'A' && grid [ a ] [ b ] <= 'Z' ) )break;
        grid [ a ] [ b ] = '!';
    }
}
void kk()
{
    for ( k = 0; k != 8; k++ )
    {
        a = fx [ k ] + i;
        b = fy [ k ] + j;
        if ( a > 0 && b > 0 && a < 9 && b < 9 && grid [ a ] [ b ] == '.' )grid [ a ] [ b ] = '!';
    }
}
void nn()
{
    for ( k = 0; k != 8; k++ )
    {
        a = dx [ k ] + i;
        b = dy [ k ] + j;
        if ( a > 0 && b > 0 && a < 9 && b < 9 && grid [ a ] [ b ] == '.' )grid [ a ] [ b ] = '!';
    }
}
