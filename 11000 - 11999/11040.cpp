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
int ar [ 11 ] [ 11 ];
int row, col, row2,col2;
void brainfuck();
int finder();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while( n-- )brainfuck();
    return 0;
}
void brainfuck( )
{
    for ( i = 1 ; i <= 9; i += 2 )
        for ( j = 1; j <= i; j += 2 )cin>>ar [ i ] [ j ];
    e = finder();
}
int finder()
{
    for ( i = 3; i <= 9; i += 2 )
    {
        for ( j = 2; j <= i ; j += 2 )ar [ i ] [ j ] = ( ar [ i - 2 ] [ j - 1 ] - ( ar [ i ] [ j - 1 ] + ar [ i ] [ j + 1 ] ) ) / 2;
        for ( j = 1; j <= i - 1 ; j++ )ar [ i - 1 ] [ j ] = ar [ i ] [ j ] + ar [ i ] [ j + 1 ];
    }
    for ( i = 1; i <= 9; i++ )
    {
        for ( j = 1; j <= i; j++ )
        {
            if ( j != 1 )cout<<" ";
            cout<<ar [ i ] [ j ];
        }
        cout<<"\n";
    }
    return 0;
}
void _90()
{
    //
}
