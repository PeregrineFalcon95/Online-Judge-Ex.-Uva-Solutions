#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , g , i , j , k , q , ans;
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
int ar [ 2 ] [ mxs ] ;
bool marker [ 510 ] [ 510 ];
int row, col, row2,col2;
void brainfuck();
void finder();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>a>>b>>c && a )brainfuck();
    return 0;
}
void brainfuck( )
{
    //cout<<a<<" shit "<<b<<endl;
    memset( marker , 0, sizeof marker );
    while( c-- )
    {
        cin>>col>>row>>col2>>row2;
        finder();
    }
    d = 0;
    for ( i = 1; i <= b; i++ )
        for ( j = 1; j <= a; j++ )if ( !marker [ i ] [ j ] )d++;
    //cout<<a<<"  lol\n";
    if ( !d )cout<<"There is no empty spots.\n";
    else if ( d == 1 )cout<<"There is one empty spot.\n";
    else cout<<"There are "<<d<<" empty spots.\n";
}
void finder()
{
    for ( i = min(row, row2 ); i <= max(row2,row); i++ )
        for ( j = min(col,col2); j <= max(col2,col); j++ )marker [ i ] [ j ] = 1;
}
