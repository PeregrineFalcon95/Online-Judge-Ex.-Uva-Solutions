/* Bell man ford, Check if there are any negative cycle */
#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
#pragma comment(linker, "/stack:200000000")
#define mod ( ll  ) ( 1e9 + 7 )  //( 1e9 + 7 )
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
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
int dis [ 1010 ];
vector < pair < int , pair < int , int > > > edges;
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(NULL);
    //cout.tie(NULL);
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    while( scanf("%d%d",&n,&m) == 2 && n )
    {
        edges.clear();
        for ( int i = 0 ; i <= n; i++ )
        {
            dis [ i ] = inf;
        }
        int a , b,  c,  marker = 0;

        for ( int i = 0 ; i < m; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            edges.push_back( make_pair( a , make_pair( b , c ) ) );
            edges.push_back( make_pair( b , make_pair( a , -c ) ) );
        }
        m += m;

        dis [ 1 ] = 0;
        for ( int i = 1 ; i < n; i++ )
        {
            for ( int j = 0 ; j < m; j++ )
            {
                a = edges [ j ].first;
                b = edges [ j ].second.first;
                c = edges [ j ].second.second;
                if ( dis [ a ] + c < dis [ b ] )
                {
                    dis [ b ] = dis [ a ] + c;
                }
            }
        }

        for ( int j = 0 ; j < m; j++ )
        {
            a = edges [ j ].first;
            b = edges [ j ].second.first;
            c = edges [ j ].second.second;
            if ( dis [ a ] + c < dis [ b ] )
            {
                marker = 1;
                break;
            }
        }


        if ( !marker )printf("N\n");
        else printf("Y\n");
    }
}
