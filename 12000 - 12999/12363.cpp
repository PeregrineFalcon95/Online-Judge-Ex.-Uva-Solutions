#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//#pragma comment(linker, "/stack:200000000")
#define fast ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
#define mod ( ll  ) ( 1e9 + 7 )  //( 1e9 + 7 )
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)(1e6+10)//( 1e6 + 10 )
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves
int n, m, t , ans , cases;
string s , s2 , s3;

vector < int > graph [ 10010 ] , graph2 [ 10010 ];

int visited [ 10010 ] , parent [ 10010 ] , dis [ 10010 ] , lo [ 10010 ] , com [ 10010 ];
int time_ , xx;
queue < int > qu;
void art( int source )
{
    visited [ source ] = 1;
    time_++;
    lo [ source ] = dis [ source ] = time_;
    int b , sz = graph [ source ].size();
    for ( int i = 0 ; i < sz; i++ )
    {
        b = graph [ source ] [ i ];
        if ( parent [ source ] == b )continue;
        if ( !visited [ b ] )
        {
            parent [ b ] = source;
            art( b );
            lo [ source ] = min( lo [ source ] , lo [ b ] );
        }
        else lo [ source ] = min( lo [ source ] , dis [ b ] );

        if ( dis [ source ] < lo [ b ] )
        {
            graph2 [ source ].push_back( b );
            graph2 [ b ].push_back( source );
        }
    }
}
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //fast
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    while( scanf("%d%d%d",&n,&m,&ans) == 3 && n )
    {
        time_ = xx = 0;
        for ( int i = 0 ; i <= n; i++ )
        {
            graph [ i ].clear();
            graph2 [ i ].clear();
            visited [ i ] = 0;
            parent [ i ] = i;
        }
        int a , b , sz ;
        while( m-- )
        {
            scanf("%d%d",&a,&b);
            graph [ a ].push_back( b );
            graph [ b ].push_back( a );
        }
        for ( int i = 1 ; i <= n; i++ )
            if ( !visited [ i ] )art( i );

        for ( int i = 1 ; i <= n; i++ )
        {
            visited [ i ] = 0;
        }

        for ( int i = 1 ; i <= n; i++ )
        {
            if ( !visited [ i ] )
            {
                xx++;
                com [ i ] = xx;
                visited [ i ] = 1;
                qu.push( i );
                while( !qu.empty() )
                {
                    a = qu.front();
                    qu.pop();
                    sz = graph2 [ a ].size();
                    for ( int j = 0 ; j < sz; j++ )
                    {
                        b = graph2 [ a ] [ j ];
                        if ( !visited [ b ] )
                        {
                            qu.push( b );
                            visited [ b ] = 1;
                            com [ b ] = xx;
                        }
                    }
                }
            }
        }
        while( ans-- )
        {
            scanf("%d%d",&a,&b);
            if ( com [ a ] == com [ b ] )printf("Y\n");
            else printf("N\n");
        }
        printf("-\n");
    }
}
