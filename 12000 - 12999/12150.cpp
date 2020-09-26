#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e4+7)
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
int ar [ mxs ] , temp [ mxs ] , start [ mxs ];
void brainfuck();
bool finder();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n && n)brainfuck();
    return 0;
}
void brainfuck( )
{
    memset( start , 0 , sizeof start );
    memset( ar , -1, sizeof ar );
    for ( i = 1; i <= n; i++ )
    {
        cin>>a>>b;
        ar [ a ] = i;
        temp [ a ] = b;
    }
    if ( finder() ){cout<<"-1\n";return;}
    for ( i = 1; i <= n; i++ )
    {
        if ( i != 1 )cout<<" ";
        cout<<start [ i ];
    }
    cout<<"\n";
}
bool finder()
{
    for ( i = 1; i <= 10000; i++ )
    {
        if ( ar [ i ] == -1 )continue;
        a = ar [ i ] + temp [ i ];
        if ( a < 1 || a > n || start [ a ]  )return 1;
        start [ a ] = i;
    }
    return 0;
}
