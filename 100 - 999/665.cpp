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
int ar [ 110 ] , ri [ 110 ] , le [ 110 ];
void brainfuck();
int finder( );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t -- )brainfuck();
    return 0;
}
void brainfuck( )
{
    cin>>n>>m;
    memset( ar , 0 , sizeof ar );
    while ( m-- )
    {
        cin>>a;
        for ( i = 1 ; i <= a; i++ )cin>>ri [ i ];
        for ( i = 1 ; i <= a; i++ )cin>>le [ i ];
        cin>>s;
        if ( s == "=" )
            for ( i = 1; i <= a; i++ )
                ar [ ri [ i ] ] = ar [ le [ i ] ] = 1;
    }
    a = finder();
    cout<<a<<"\n";
    if ( t )cout<<"\n";
}
int finder( )
{
    b = 0;
    for ( i = 1; i <= n; i++ )
        if ( !ar [ i ] )a = i , b++;
    if ( b == 1 )return a;
    return 0;
}
