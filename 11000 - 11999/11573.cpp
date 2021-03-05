/*One Last Drive*/
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
#define mod ( ll  ) 1000000000000//( 1e9 + 7 )  //( 1e9 + 7 )
#define inf ( int  )( 1e9 + 10 )
#define mxs (int)(1e6+100)
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves
int n , m, x, t, ans, cases ;
string s , s2;
char grid [ 1005 ] [ 1005 ];
int level [ 1005 ] [ 1005 ];
bool visited [ 1005 ] [ 1005 ];
int dx [] = {-1, -1, 0, 1, 1, +1,  0, -1};
int dy [] = { 0, +1, 1, 1, 0, -1, -1, -1};
bool checker( int x , int y )
{
    return !( x < 0 || y < 0 || x == n || y == m );
}
int shortestPath( int sourceR, int sourceC, int targetR, int targetC )
{
    //Clearing for 0-1 BFS
    deque < pair < int , int > > dq;
    for ( int i = 0 ; i <= n; i++ )
        for ( int j = 0 ; j <= m; j++ )level [ i ] [ j ] = inf , visited [ i ] [ j ] = 0;

    //Pushing Source
    dq.push_back( { sourceR , sourceC } );
    level [ sourceR ] [ sourceC ] = 0;
    visited [ sourceR ] [ sourceC ] = 1;

    //0-1 BFS
    int a , b , c , d , e ,i;
    while( !dq.empty() )
    {
        a = dq.front().first;
        b = dq.front().second;
        if ( a == targetR && b == targetC )return level [ a ] [ b ];
        dq.pop_front();
        e = grid [ a ] [ b ] - '0';

        //Adjacent 8 cells
        for ( i = 0 ; i < 8; i++ )
        {
            c = a + dx [ i ];
            d = b + dy [ i ];
            if ( !checker( c , d ) )continue;

            //Check for free move
            if ( i == e )
            {
                if ( level [ c ] [ d ] > level [ a ] [ b ] )
                {
                    visited [ c ] [ d ] = 1;
                    level [ c ] [ d ] = level [ a ] [ b ];
                    dq.push_front( { c , d } );
                }
            }
            else if ( !visited [ c ] [ d ] || level [ c ] [ d ] > level [ a ] [ b ] + 1 )
            {
                visited [ c ] [ d ] = 1;
                level [ c ] [ d ] = level [ a ] [ b ] + 1;
                dq.push_back( { c , d } );
            }

        }
    }
    return level [ targetR ] [ targetC ];
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
    cin>>n>>m;
    for ( int i = 0 ; i < n; i++ )cin>>grid [ i ];
    int q;
    cin>>q;
    int a , b , c , d , e;
    while( q-- )
    {
        cin>>a>>b>>c>>d;
        cout<<shortestPath( a-1, b-1, c-1, d-1 )<<"\n";
    }
}


/// https://codeforces.com/gym/101628/problem/f
/// https://codeforces.com/contest/144/problem/D
/// https://codeforces.com/gym/102006/problem/K
/// https://codeforces.com/contest/1397/problem/D
/// https://codeforces.com/contest/59/problem/D
/// https://codeforces.com/contests/page/13
