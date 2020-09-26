#include<bits/stdc++.h>
using namespace std;
int matrix [ 510 ] [ 510 ] , mi [ 2010 ] [ 2010 ] , mx [ 2010 ] [ 2010 ];
int q , n , m , i , j , x11 , x22 , y11 , y22 , val;
string s;
void build_x( int v , int l , int r );
void build_y( int v , int l , int r , int v2 , int ll , int rr );
void update_x( int v , int l , int r , int row , int col  );
void update_y( int v , int xx, int yy, int v2 , int l , int r , int row , int col );
pair < int , int > ans;
pair < int , int > query_x( int v , int l , int r , int x , int y );
pair < int , int > query_y( int v , int v2 , int l , int r , int x , int y );
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )cin>>matrix [ i ] [ j ];
    build_x( 1 , 1 , n );
    cin>>q;
    while( q-- )
    {
        cin>>s;
        if ( s == "q" )
        {
            ///query
            cin>>x11>>y11>>x22>>y22;
            ans = query_x( 1 , 1 , n , x11 , x22 );
            cout<<ans.second<<" "<<ans.first<<"\n";
        }
        else
        {
            ///Update
            cin>>x11>>y11>>val;
            update_x( 1 , 1 , n , x11 , y11 );
        }
    }
    return 0;
}
void build_x( int v , int l , int r )
{
    if ( l != r )
    {
        int mid = ( l + r )>>1;
        build_x( v + v , l , mid );
        build_x( v + v + 1 , mid + 1 , r );
    }
    build_y( v , l , r , 1 , 1 , n );
}
void build_y( int v , int l , int r , int v2 , int ll , int rr )
{
    if ( ll == rr )
    {
        if ( l == r )mi [ v ] [ v2 ] = mx [ v ] [ v2 ] = matrix [ l ] [ rr ];
        else
        {
            mi [ v ] [ v2 ] = min( mi [ v + v ] [ v2 ] , mi [ v + v + 1 ] [ v2 ] );
            mx [ v ] [ v2 ] = max( mx [ v + v ] [ v2 ] , mx [ v + v + 1 ] [ v2 ] );
        }
    }
    else
    {
        int mid = ( ll + rr )>>1;
        build_y( v , l , r , v2 + v2 , ll , mid );
        build_y( v , l , r , v2 + v2 + 1 , mid + 1 , rr );
        mi [ v ] [ v2 ] = min( mi [ v ] [ v2 + v2 ] , mi [ v ] [ v2 + v2 + 1 ] );
        mx [ v ] [ v2 ] = max( mx [ v ] [ v2 + v2 ] , mx [ v ] [ v2 + v2 + 1 ] );
    }
}
pair < int , int > query_x( int v , int l , int r , int x , int y )
{
    if ( x > y )return ( make_pair( INT_MAX , INT_MIN ) );
    if ( l == x && r == y )return ( query_y( v , 1 , 1 , n , y11 , y22 ) );
    else
    {
        int mm , nn;
        pair < int , int > xox;
        int mid = ( l + r )>>1;
        xox = query_x( v + v , l , mid , x , min( y , mid ) );
        nn = xox.first;
        mm = xox.second;
        xox = query_x( v + v + 1 , mid + 1 , r , max( x , mid + 1 ) , y );
        nn = min( xox.first , nn );
        mm = max( xox.second , mm );
        return ( make_pair( nn , mm ) );
    }
}
pair < int , int > query_y( int v , int v2 , int l , int r , int x , int y )
{
    if ( x > y )return ( make_pair( INT_MAX , INT_MIN ) );
    if ( l == x && r == y )return ( make_pair( mi [ v ] [ v2 ] , mx [ v ] [ v2 ] ) );
    else
    {
        int mid = ( l + r )>>1;
        int mm , nn;
        pair < int , int > xox;
        xox = query_y( v , v2 + v2 , l , mid , x , min( y , mid ) );
        nn = xox.first;
        mm = xox.second;
        xox = query_y( v , v2 + v2 + 1 , mid + 1 , r , max( x , mid + 1 ) , y );
        nn = min( xox.first , nn );
        mm = max( xox.second , mm );
        return ( make_pair( nn , mm ) );
    }
}
void update_x( int v , int l , int r , int row , int col )
{
    if ( l != r )
    {
        int mid = ( l + r )>>1;
        if ( row <= mid )update_x( v + v , l , mid , row , col );
        else update_x( v + v + 1 , mid + 1 , r , row , col );
    }
    update_y( v , l , r , 1 , 1 , n , row , col );
}
void update_y( int v , int xx , int yy , int v2 , int l , int r , int row , int col )
{
    if ( l == r )
    {
        if( xx == yy  )mi [ v ] [ v2 ] = mx [ v ] [ v2 ] = val;
        else
        {
            mi [ v ] [ v2 ] = min( mi [ v + v ] [ v2 ], mi [ v + v + 1 ] [ v2 ] );
            mx [ v ] [ v2 ] = max( mx [ v + v ] [ v2 ], mx [ v + v + 1 ] [ v2 ] );
        }
        return;
    }
    int mid = ( l + r )>>1;
    if ( col <= mid )update_y( v , xx , yy , v2 + v2 , l , mid , row , col );
    else update_y( v , xx , yy , v2 + v2 + 1 , mid + 1 , r , row , col );
    mi [ v ] [ v2 ] = min( mi [ v ] [ v2 + v2 ] , mi [ v ] [ v2 + v2 + 1 ] );
    mx [ v ] [ v2 ] = max( mx [ v ] [ v2 + v2 ] , mx [ v ] [ v2 + v2 + 1 ] );
}

