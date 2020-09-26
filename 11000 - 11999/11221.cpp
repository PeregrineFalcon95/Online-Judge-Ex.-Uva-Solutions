#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , i , j , k , q ;
char grid [ 110 ] [ 110 ] ;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
int ar [ 60 ] [ 60 ] ;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
deque < int > dq;
string s , s2 , s3;
int brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    cin.ignore();
    while ( t-- )
    {
        getline( cin , s2 );
        s = "";
        n = s2.size();
        for ( i = 0; i != n; i++ )
            if ( s2 [ i ] >= 'a' && s2 [ i ] <= 'z' )s += s2 [ i ];
        n = s.size();
        a = brainfuck();
        if ( !a )cout<<"Case #"<<++cases<<":\nNo magic :(\n";
        else cout<<"Case #"<<++cases<<":\n"<<a<<"\n";
    }
    return 0;
}
int brainfuck()
{
    a = sqrt( n );
    if ( a * a != n )return 0;
    int row = 1;
    int col = 1;
    for ( i = 0; i != n; i++ )
    {
        grid [ row ] [ col ] = s [ i ];
        col++;
        if ( col > a )col = 1 , row++;
    }
    c = d = 0;
    for ( i = 1; i <= a; i++ )
        for ( j = 1; j <= a; j++ )
        {
            if ( grid [ i ] [ j ] != s [ c++ ] )return 0;
            if ( grid [ j ] [ i ] != s [ d++ ] )return 0;
        }
    c = d = 0;
    for ( i = a; i >= 1; i-- )
        for ( j = a; j >= 1; j-- )
        {
            if ( grid [ i ] [ j ] != s [ c++ ] )return 0;
            if ( grid [ j ] [ i ] != s [ d++ ] )return 0;
        }
    return a;
}
