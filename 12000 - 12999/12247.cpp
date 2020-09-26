#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(2e5+7)
#define ll long long int
int val , n , m , cases , t , a , b , c , d , e , i , j ;
deque < int > boy , girl;
bool marker [ 60 ];
int ans();
void track( int idx );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>a>>b>>c>>d>>e && a )
    {
        memset( marker , 0 , sizeof marker );
        marker [ a ] = marker [ b ] = marker [ c ] = marker [ d ] = marker [ e ] = 1;
        boy.clear();
        girl.clear();
        girl.push_back( a );
        girl.push_back( b );
        girl.push_back( c );
        boy.push_back( d );
        boy.push_back( e );
        t = ans();
        cout<<t<<"\n";
    }
    return 0;
}
int ans()
{
    a = b = 0;
    track( 0 );
    if ( a == 2 )return -1;
    if ( a == 1 )
    {
        for ( i = b + 1; i <= 52; i++ )
            if ( !marker [ i ] )return i;
        return -1;
    }
    for ( i = 1; i <= 52; i++ )
        if ( !marker [ i ] )return i;
}
void track( int idx )
{
    if ( idx == 3 )return;
    for ( int l = 0; l != 3; l++ )
    {
        if ( l == idx )continue;
        d = 0;
        if ( girl [ idx ] > boy [ 0 ] )d++;
        if ( girl [ l ] > boy [ 1 ] )d++;
        for ( int k = 0; k != 3; k++ )
            if ( k != l && k != idx )c = girl [ k ];
        if ( d > a || ( a == d && b < c ) )a = d , b = c;
    }
    track( idx + 1 );
}

