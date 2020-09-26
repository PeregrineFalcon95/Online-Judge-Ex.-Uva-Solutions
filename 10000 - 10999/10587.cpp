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
int ar[ 2 ] [ mxs ];
int tree [ 300007 ];
set < int > st;
vector < int > v;
map < int , int > mp;
void brainfuck();
void update( int node , int le , int re , int left_r , int right_r );
void final_( int node , int le , int re );
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>t;
    while( t-- )
    {
        st.clear();
        ans = 0;
        memset(tree , 0 , sizeof tree );
        cin>>n;
        v.clear();
        mp.clear();
        for ( i = 1 ; i <= n; i++ )
        {
            cin>>a>>b;
            ar [ 0 ] [ i ] = a;
            ar [ 1 ] [ i ] = b;
            v.push_back( a );
            v.push_back( b );
        }
        a = 0;
        sort( v.begin() , v.end() );
        m = v.size();
        for ( i = 0 ; i < m; i++ )
        {
            if ( mp.find( v [ i ] ) == mp.end() )
            {
                mp [ v [ i ] ] = ++a;
            }
        }
        m = a;
        for ( i = 1 ; i <= n; i++ )
        {
            a = mp [ ar [ 0 ] [ i ] ];
            b = mp [ ar [ 1 ] [ i ] ];
            update( 1 , 1 , m , a , b );
        }
        final_( 1 , 1 , m );
        ans = st.size();
        cout<<ans<<"\n";
    }
}
void update( int node , int le , int re , int left_r , int right_r )
{
    if ( left_r > right_r )return;
    if ( le == left_r && re == right_r )
    {
        ///In range
        tree [ node ] = i;
        return;
    }
    int mid = ( le + re )>>1;
    if ( tree [ node ] && le != re )
    {
        tree [ node + node ] = tree [ node ];
        tree [ node + node + 1 ] = tree [ node ];
        tree [ node ] = 0;
    }
    update( node + node , le , mid , left_r , min( right_r , mid ) );
    update( node + node + 1 , mid + 1 , re , max( left_r , mid + 1 ) , right_r );
}
void final_( int node , int le , int re )
{
    if ( le == re )
    {
        if( tree [ node ] )st.insert( tree [ node ] );
        return;
    }
    if ( tree [ node ] )
    {
        tree [ node + node ] = tree [ node ];
        tree [ node + node + 1 ] = tree [ node ];
    }
    int mid = ( le + re )>>1;
    final_( node + node , le , mid  );
    final_( node + node + 1 , mid + 1 , re );
}
