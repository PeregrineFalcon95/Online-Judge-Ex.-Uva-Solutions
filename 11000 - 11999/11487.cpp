#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//#pragma comment(linker, "/stack:200000000")
#define mod ( ll  ) ( 1e9 + 7 )  //( 1e9 + 7 )
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
int dx[]={+1,-1,+0,+0};///Four Directions
int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves
int n, m, t , ans , cases;
string s , s2 , s3;
char grid [ 15 ] [ 15 ];
int path [ 15 ] [ 15 ] , dis [ 15 ] [ 15 ];
queue < pair < int , int > > qu;
bool checker( int x , int y )
{
    return !( x < 0 || y < 0 || x >= n || y >= n || grid [ x ] [ y ] == '#' );
}
void bfs( int row , int col , char ch )
{

    memset( dis , -1 , sizeof dis );
    memset( path , 0 , sizeof path );

    dis [ row ] [ col ] = 0;
    path [ row ] [ col ] = 1;
    qu.push( { row , col } );

    int a , b , c , d;
    while( !qu.empty() )
    {
        a = qu.front().first;
        b = qu.front().second;
        qu.pop();

        for ( int i = 0 ; i < 4; i++ )
        {
            c = dx [ i ] + a;
            d = dy [ i ] + b;
            if ( checker( c , d ) )
            {
                if ( grid [ c ] [ d ] >= 'A' && grid [ c ] [ d ] <= 'Z' && grid [ c ] [ d ] > ch + 1 )continue;

                if ( dis [ c ] [ d ] == -1 )
                {
                    dis [ c ] [ d ] = dis [ a ] [ b ] + 1;
                    path [ c ] [ d ] = path [ a ] [ b ];
                    qu.push( { c , d  } );
                }
                else if ( dis [ c ] [ d ] == dis [ a ] [ b ] + 1 )
                {
                    path [ c ] [ d ] += path [ a ] [ b ];
                }
            }
        }
    }
}
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    while( cin>>n && n )
    {
        for ( int i = 0 ; i < n; i++ )cin>>grid [ i ];

        map < char , pair < int , int > > mp;
        map < char , pair < int , int > >::iterator it , it2;

        for ( int i = 0 ; i < n; i++ )
            for ( int j = 0 ; j < n; j++ )
                if ( grid [ i ] [ j ] >= 'A' && grid [ i ] [ j ] <= 'Z' )
                    mp [ grid [ i ] [ j ] ] = { i , j };


        int mo = 20437;
        ans = 0;
        int paths = 1;
        int a , b , c;

        for ( it = mp.begin(); it != mp.end(); it++ )
        {
            it2 = it;
            it2++;
            if ( it2 == mp.end() )break;

            a = it->second.first;
            b = it->second.second;

            bfs( a , b , it->first );

            a = it2->second.first;
            b = it2->second.second;

            if ( dis [ a ] [ b ] == -1 )
            {
                ans = -1;
                break;
            }
            ans += dis [ a ] [ b ];
            paths *= path [ a ] [ b ];
            paths %= mo;
        }

        cout<<"Case "<<++cases<<": ";
        if ( ans == -1 )cout<<"Impossible\n";
        else cout<<ans<<" "<<paths<<"\n";
    }
}
