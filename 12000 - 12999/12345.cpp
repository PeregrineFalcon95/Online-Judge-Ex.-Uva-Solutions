///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#define ll long long int
#define inf ( int )( 1e9 + 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod (ll)(1e9)+7
//int dx[]={+1,0,+0,-1};///Four Directions
//int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int ans,t, n, m, j, k,a, b, c, d, e,f , i,sz,cases ,q,le,re,hi,lo,mid;
string s, s2, s3, s4;
vector < int > v;
set < int > st , tree [ mxs ];
map < int , int > mp [ mxs ];
map < int , int > mpp;
int temp [ 3 ] [ mxs ];
set < int >::iterator it;
int ar [ mxs ];
void brainfuck();
void build( int node , int le , int re );
void query( int node , int le , int re , int left_r , int right_r );
int update( int node , int le , int re , int left_r , int right_r );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>n>>m;
    for ( i = 1 ; i <= n; i++ )
    {
        cin>>ar [ i ];
        v.push_back( ar [ i ] );
    }

    for ( i = 1 ; i <= m; i++ )
    {
        cin>>s>>temp [ 1 ] [ i ]>>temp [ 2 ] [ i ];

        if ( s == "Q" )temp [ 0 ] [ i ] = 1;
        else v.push_back( temp [ 2 ] [ i ] );
    }
    sort( v.begin() , v.end() );
    a = 0;
    b = v.size();
    for ( i = 0 ; i < b; i++ )
    {
        if ( mpp.find( v [ i ] ) == mpp.end() )mpp [ v [ i ] ] = ++a;
    }
    for ( i = 1 ; i <= n; i++ )ar [ i ] = mpp [ ar [ i ] ];
    for ( i = 1 ; i <= m; i++ )
    {
        if ( temp [ 0 ] [ i ] == 0 )
        {
             temp [ 2 ] [ i ] = mpp [ temp [ 2 ] [ i ] ];
        }
    }
    q = a;
    int counter [ q + 100 ];
    build( 1 , 1 , n );
    for ( k = 1 ; k <= m; k++ )
    {
        a = temp [ 1 ] [ k ];
        b = temp [ 2 ] [ k ];
        if ( temp [ 0 ] [ k ] == 1 )
        {
            v.clear();
            ///Query
            a++;
            memset( counter , 0 , sizeof counter );
            query( 1 , 1 , n , a , b );
            a = v.size();
            ans = 0;
            for ( i = 0; i < a; i++ )
            {
                for ( it = tree [ v [ i ] ].begin() ; it !=  tree [ v [ i ] ].end(); it++ )
                {
                    counter [ *it ]++;
                    if ( counter [ *it ] == 1 )ans++;
                }
            }
            cout<<ans<<"\n";
        }
        else
        {
            ///Update
            a++;
            a = update( 1 ,1 , n, a , a);
        }
    }
}
void build( int node , int le , int re )
{
    if ( le == re )
    {
        tree [ node ].insert( ar [ le ] );
        mp [ node ] [ ar [ le ] ] ++;
        return;
    }
    int mid = ( le + re )>>1;
    build ( node + node , le  , mid );
    build ( node + node + 1 , mid + 1 , re );

    for ( it = tree [ node + node ].begin(); it != tree [ node + node ].end(); it++ )
    {
        tree [ node ].insert( *it );
    }

    for ( it = tree [ node + node + 1 ].begin(); it != tree [ node + node + 1 ].end(); it++ )
    {
        tree [ node ].insert( *it );
    }

    for ( map < int , int >::iterator ii = mp [ node + node ].begin() ; ii != mp [ node + node ].end(); ii++ )
    {
        mp [ node ] [ ii->first ] = ii->second;
    }
    for ( map < int , int >::iterator ii = mp [ node + node + 1 ].begin() ; ii != mp [ node + node + 1 ].end(); ii++ )
    {
        mp [ node ] [ ii->first ] += ii->second;
    }
}
void query( int node , int le , int re , int left_r , int right_r )
{
    if ( left_r > right_r )
    {
        return;
    }
    if ( le == left_r && right_r == re )
    {
        ///In range
        v.push_back( node );
        return;
    }
    int mid = ( le + re )>>1;
    query( node + node , le , mid , left_r , min( right_r , mid ));
    query( node + node + 1 , mid + 1 , re , max( left_r , mid + 1 ) , right_r );
}
int update( int node , int le , int re , int left_r , int right_r )
{
    if ( left_r > right_r )return inf;
    if ( left_r == le && right_r == re )
    {
        ///In range
        it = tree [ node ].begin();
        it = tree [ node ].lower_bound( *it );
        int lol = *it;
        mp [ node ].clear();
        tree [ node ].clear();
        tree [ node ].insert( b );
        mp [ node ] [ b ] = 1 ;
        return lol;
    }
    int mid = ( le + re )>>1;
    int xx;
    xx = update( node + node , le , mid , left_r , min( right_r , mid ) );
    if ( xx != inf )
    {
        mp [ node ] [ xx ]--;
        if( mp [ node ] [ xx ] == 0 )tree [ node ].erase(xx);
        tree [ node ].insert( b );
        mp [ node ] [ b ]++;
        return xx ;
    }
    xx = update( node + node + 1 , mid + 1 , re , max( left_r , mid + 1 ) , right_r );
    if ( xx != inf )
    {
        mp [ node ] [ xx ]--;
        if( mp [ node ] [ xx ] == 0 )tree [ node ].erase(xx);
        tree [ node ].insert( b );
        mp [ node ] [ b ]++;
        return xx ;
    }
}
