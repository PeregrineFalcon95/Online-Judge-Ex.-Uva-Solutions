#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(2e5+7)
#define ll long long int
int  n , m , cases , t , a , b , c , d , e , i , j ;
int dx[]= {-2,-2,-1,1,-1,1,2,2};
int dy[]= {1,-1,-2,-2,2,2,-1,1};
char ch;
char grid [ 10 ] [ 10 ];
int checker();
bool pp();
bool PP();
bool RR();
bool rr();
bool bb();
bool BB();
bool qq();
bool QQ();
bool kk();
bool KK();
bool nn();
bool NN();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int xxx = 0;
    while( 1 )
    {
        if ( xxx )getchar();
        xxx++;
        for ( i = 0; i != 8; i++ )scanf("%s",&grid [ i ] );
        a = checker();
        if ( a == -1 )return 0;
        if ( a == 1 )printf("Game #%d: black king is in check.\n",++cases );
        else if ( a == 2 )printf("Game #%d: white king is in check.\n",++cases );
        else printf("Game #%d: no king is in check.\n",++cases);
        //getchar();
    }
    return 0;
}
int checker()
{
    a = 0;
    int lol = 0;
    for ( i = 0; i != 8; i++ )
        for ( j = 0; j != 8; j++ )
        {
            ch = grid [ i ] [ j ] ;
            if ( ch >= 'a' && ch <= 'z' )
            {
                lol = 1;
                if ( ch == 'p' && pp() )return 2;
                else if ( ch == 'r' && rr() )return 2;
                else if ( ch == 'b' && bb() )return 2;
                else if ( ch == 'q' && qq() )return 2;
                else if ( ch == 'k' && kk() )return 2;
                else if ( ch == 'n' && nn() )return 2;
            }
            else if ( ch >= 'A' && ch <= 'Z' )
            {
                lol = 1;
                if ( ch == 'P' && PP() )return 1;
                else if ( ch == 'R' && RR() )return 1;
                else if ( ch == 'B' && BB() )return 1;
                else if ( ch == 'Q' && QQ() )return 1;
                else if ( ch == 'K' && KK() )return 1;
                else if ( ch == 'N' && NN() )return 1;
            }
        }
    if( lol )return 3;
    return -1;
}
bool pp()
{
    if ( ( i + 1 ) < 8 && ( j + 1 ) < 8 && grid [ i + 1 ] [ j + 1 ] == 'K' )return 1;
    else if ( ( i + 1 ) < 8 && ( j - 1 ) >= 0 && grid [ i + 1 ] [ j - 1 ] == 'K' )return 1;
    return 0;
}
bool PP()
{
    if ( ( i - 1 ) >= 0 && ( j + 1 ) < 8 && grid [ i - 1  ] [ j + 1 ] == 'k' )return 1;
    else if ( ( i - 1 ) >= 0 && ( j - 1 ) >= 0 && grid [ i - 1 ] [ j - 1 ] == 'k' )return 1;
    //cout<<"xxx\n";
    return 0;
}
bool RR()
{
    a = i;
    while ( a )
    {
        a--;
        if ( grid [ a ] [ j ] == 'k' )return 1;
        if ( grid [ a ] [ j ] != '.')break;
    }
    a = i;
    while ( ++a )
    {
        if ( a == 8 )break;
        if ( grid [ a ] [ j ] == 'k' )return 1;
        if ( grid [ a ] [ j ] != '.')break;
    }
    a = j;
    //cout<<j<<endl;
    while ( ++a )
    {
        if ( a == 8 )break;
        //cout<<a<<endl;
        if ( grid [ i ] [ a ] == 'k' )return 1;
        if ( grid [ i ] [ a ] != '.')break;
    }
    //cout<<"xxx\n";
    a = j;
    while ( a )
    {
        a--;
        if ( grid [ i ] [ a ] == 'k' )return 1;
        if ( grid [ i ] [ a ] != '.')break;
    }
    //cout<<"xxx\n";
    return 0;
}
bool rr()
{
    a = i;
    while ( a )
    {
        a--;
        if ( grid [ a ] [ j ] == 'K' )return 1;
        if ( grid [ a ] [ j ] != '.')break;
    }
    a = i;
    while ( ++a )
    {
        if ( a == 8 )break;
        if ( grid [ a ] [ j ] == 'K' )return 1;
        if ( grid [ a ] [ j ] != '.')break;
    }
    a = j;
    while ( ++a )
    {
        if ( a == 8 )break;
        if ( grid [ i ] [ a ] == 'K' )return 1;
        if ( grid [ i ] [ a ] != '.')break;
    }
    a = j;
    while ( a )
    {
        a--;
        if ( grid [ i ] [ a ] == 'K' )return 1;
        if ( grid [ i ] [ a ] != '.')break;
    }
    return 0;
}
bool bb()
{
    a = i;
    b = j;
    a--;
    b--;
    while( a >= 0 && b >= 0 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a--;
        b--;
    }
    a = i;
    b = j;
    a--;
    b++;
    while( a >= 0 && b < 8 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a--;
        b++;
    }
    a = i;
    b = j;
    a++;
    b++;
    while( a < 8 && b < 8 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a++;
        b++;
    }
    //cout<<"xxx\n";
    a = i;
    b = j;
    a++;
    b--;
    while( a < 8 && b >= 0 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a++;
        b--;
    }
    return 0;
}
bool BB()
{
    a = i;
    b = j;
    a--;
    b--;
    while( a >= 0 && b >= 0 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a--;
        b--;
    }
    a = i;
    b = j;
    a--;
    b++;
    while( a >= 0 && b < 8 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a--;
        b++;
    }
    a = i;
    b = j;
    a++;
    b++;
    while( a < 8 && b < 8 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a++;
        b++;
    }
    a = i;
    b = j;
    a++;
    b--;
    while( a < 8 && b >= 0 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a++;
        b--;
    }
    return 0;
}
bool qq()
{
    a = i;
    b = j;
    a--;
    b--;
    while( a >= 0 && b >= 0 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a--;
        b--;
    }
    a = i;
    b = j;
    a--;
    b++;
    while( a >= 0 && b < 8 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a--;
        b++;
    }
    a = i;
    b = j;
    a++;
    b++;
    while( a < 8 && b < 8 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a++;
        b++;
    }
    a = i;
    b = j;
    a++;
    b--;
    while( a < 8 && b >= 0 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a++;
        b--;
    }
    a = i;
    b = j;
    b++;
    while( b < 8 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        b++;
    }
    b = j;
    b--;
    while( b >= 0 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        b--;
    }
    b = j;
    a = i;
    a++;
    while( a < 8 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a++;
    }
    a = i;
    a--;
    while( a >= 0 )
    {
        if ( grid [ a ] [ b ] == 'K' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a--;
    }
    return 0;
}
bool QQ()
{
    a = i;
    b = j;
    a--;
    b--;
    while( a >= 0 && b >= 0 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a--;
        b--;
    }
    a = i;
    b = j;
    a--;
    b++;
    while( a >= 0 && b < 8 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a--;
        b++;
    }
    a = i;
    b = j;
    a++;
    b++;
    while( a < 8 && b < 8 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a++;
        b++;
    }
    a = i;
    b = j;
    a++;
    b--;
    while( a < 8 && b >= 0 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a++;
        b--;
    }
    a = i;
    b = j;
    b++;
    while( b < 8 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        b++;
    }
    b = j;
    b--;
    while( b >= 0 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        b--;
    }
    b = j;
    a = i;
    a++;
    while( a < 8 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a++;
    }
    a = i;
    a--;
    while( a >= 0 )
    {
        if ( grid [ a ] [ b ] == 'k' )return 1;
        if ( grid [ a ] [ b ] != '.')break;
        a--;
    }
    return 0;
}
bool kk()
{
    if ( i - 1 >= 0 && grid [ i - 1 ] [ j ] == 'K' )return 1;
    if ( i + 1 < 8 && grid [ i + 1 ] [ j ] == 'K')return 1;
    if ( i - 1 >= 0 && j - 1 >= 0 && grid [ i - 1 ] [ j - 1 ] == 'K')return 1;
    if ( i - 1 >= 0 && j + 1 < 8 && grid [ i - 1 ] [ j + 1 ] == 'K' )return 1;
    if ( i + 1 < 8 && j - 1 >= 0 && grid [ i + 1 ] [ j - 1 ] == 'K' )return 1;
    if ( i + 1 < 8 && j + 1 < 8 && grid [ i + 1 ] [ j + 1 ] == 'K' )return 1;
    if ( j - 1 >= 0 && grid [ i ] [ j - 1 ] == 'K' )return 1;
    if ( j + 1 < 8 && grid [ i ] [ j + 1 ] == 'K' )return 1;
    return 0;
}
bool KK()
{
    //cout<<"xxx\n";
    if ( i - 1 >= 0 && grid [ i - 1 ] [ j ] == 'k' )return 1;
    if ( i + 1 < 8 && grid [ i + 1 ] [ j ] == 'k')return 1;
    if ( i - 1 >= 0 && j - 1 >= 0 && grid [ i - 1 ] [ j - 1 ] == 'k')return 1;
    if ( i - 1 >= 0 && j + 1 < 8 && grid [ i - 1 ] [ j + 1 ] == 'k' )return 1;
    if ( i + 1 < 8 && j - 1 >= 0 && grid [ i + 1 ] [ j - 1 ] == 'k' )return 1;
    if ( i + 1 < 8 && j + 1 < 8 && grid [ i + 1 ] [ j + 1 ] == 'k' )return 1;
    if ( j - 1 >= 0 && grid [ i ] [ j - 1 ] == 'k' )return 1;
    if ( j + 1 < 8 && grid [ i ] [ j + 1 ] == 'k' )return 1;
    return 0;
}
bool nn()
{
    for ( int k = 0; k != 8; k++ )
    {
        a = i + dx [ k ];
        b = j + dy [ k ];
        if ( grid [ a ] [ b ] == 'K' )return 1;
    }
    return 0;
}
bool NN()
{
    for ( int k = 0; k != 8; k++ )
    {
        a = i + dx [ k ];
        b = j + dy [ k ];
        if ( grid [ a ] [ b ] == 'k' )return 1;
    }
    return 0;
}
