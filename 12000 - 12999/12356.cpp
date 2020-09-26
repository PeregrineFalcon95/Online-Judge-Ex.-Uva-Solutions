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
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
string s, s2 , s3;
deque < int > dq;
int ar [ 2 ] [ mxs ] ;
void brainfuck();
bool finder();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m && n)brainfuck();
    return 0;
}
void brainfuck( )
{
    ar [ 0 ] [ 0 ] = -1;
    ar [ 1 ] [ 0 ] = -1;
    ar [ 0 ] [ 1 ] = -1;
    ar [ 1 ] [ 1 ] = 2;
    if( n != 1  )ar [ 0 ] [ n ] = n - 1;
    else ar [ 0 ] [ n ] = -1;
    ar [ 1 ] [ n ] = -1;
    for ( i = 2; i < n; i++ )
    {
        ar [ 0 ] [ i ] = i - 1;
        ar [ 1 ] [ i ]  = i + 1;
    }
    while ( m-- )
    {
        cin>>c>>d;
        ar [ 1 ] [ ar [ 0 ] [ c ] ] = ar [ 1 ] [ d ];
        a = ar [ 0 ] [ c ];
        ar [ 0 ] [ ar [ 1 ] [ d ] ] = a;
        b = ar [ 1 ] [ d ];
        if ( a == -1 )cout<<"* ";
        else cout<<a<<" ";
        if ( b == -1 )cout<<"*\n";
        else cout<<b<<"\n";
    }
    cout<<"-\n";
}
bool finder()
{
    return 0;
}
