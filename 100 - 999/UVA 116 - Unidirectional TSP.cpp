#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//#pragma comment(linker, "/stack:200000000")
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define mod ( ll  ) ( 1e9 + 7 )  //( 1e9 + 7 )
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)(1e6+100)
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves
int n , m, t, ans, cases , k;
int grid [ 15 ] [ 110 ] , dp [ 15 ] [ 110 ] , path [ 15 ] [ 110 ];
string s , s2;
int rec( int row , int col )
{
    if ( col == m )return dp [ row ] [ col ] = grid [ row ] [ col ];
    if ( dp [ row ] [ col ] != -1 )return dp [ row ] [ col ];
    int mi = INT_MAX;
    int id = mi;
    if ( row == n )
    {
        id = 1;
        mi = rec( 1 , col + 1 );
    }
    if ( row - 1 >= 1 && rec( row - 1 , col + 1 ) < mi )
    {
        mi = rec( row - 1 , col + 1 );
        id = row - 1;
    }
    if ( rec( row , col + 1 ) < mi )
    {
        mi = rec( row , col + 1 );
        id = row;
    }
    if ( row + 1 <= n && rec( row + 1 , col + 1 ) < mi )
    {
        mi = rec( row + 1 , col + 1 );
        id = row + 1;
    }

    if ( row == 1 && rec( n , col + 1 ) < mi )
    {
        mi = rec( n , col + 1 );
        id = n;
    }

    path [ row ] [ col ] = id;
    return dp [ row ] [ col ] = mi + grid [ row ] [ col ];
}
void printer( int row , int col )
{
    if ( col > m )return;
    if ( col != 1 )cout<<" ";
    cout<<row;
    printer( path [ row ] [ col ] , col + 1 );
}
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    //cin>>t;
    t = 1;
    //scanf("%d",&t);
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    while( cin>>n>>m )
    {
        memset( dp , -1, sizeof dp );
        for ( int i = 1 ; i <= n; i++ )
            for ( int j = 1 ; j <= m; j++ )
                cin>>grid [ i ] [ j ];
        ans = INT_MAX;
        int id;
        for ( int i = 1 ; i <= n; i++ )
        {
            if ( ans > rec( i , 1 ) )
            {
                ans = rec( i , 1 );
                id = i;
            }
        }
        //cout<<id;
        printer( id , 1 );
        cout<<"\n"<<ans<<'\n';
    }
}
