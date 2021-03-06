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
#define mxs (int)(1e5+100)
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves

//void fastscan(int &number)
//{
//    register int c;
//    number = 0;
//    c = getchar();
//    for (; (c>47 && c<58); c=getchar())
//        number = number *10 + c - 48;
//}
bool vis [ 10 ] [ 10 ];
int sourceRow, sourceCol, trgetRow, targetCol, blockedRow, blockedCOl;
bool checker( int x , int y )
{
    return !( x < 0 || y < 0 || x >= 8 || y >= 8 || vis [ x ] [ y ] );
}
int bfs()
{
    memset( vis , 0 , sizeof vis );
    queue < pair < int , pair < int , int > > > qu;
    qu.push( make_pair( 0 , make_pair( sourceRow , sourceCol ) ) );
    vis [ sourceRow ] [ sourceCol ] = 1;
    vis [ blockedRow ] [ blockedCOl ] = 1;

    while( !qu.empty() )
    {
        int a = qu.front().second.first;
        int b = qu.front().second.second;
        int c = qu.front().first;
        qu.pop();
        for ( int i = 0 ; i < 8; i++ )
        {
            int x = dx [ i ] + a;
            int y = dy [ i ] + b;
            if ( checker( x , y ) )
            {
                if ( x == trgetRow && y == targetCol )return c + 1;
                vis [ x ] [ y ] = 1;
                qu.push( make_pair( c + 1, make_pair( x , y ) ) );
            }
        }
    }
}
int n , m, x, t, ans, cases ;
string s , s2;
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
    while( cin>>sourceRow>>sourceCol>>trgetRow>>targetCol>>blockedRow>>blockedCOl )
    {
        sourceRow--;
        sourceCol--;
        trgetRow--;
        targetCol--;
        blockedCOl--;
        blockedRow--;
        cout<<"Case "<<++cases<<": "<<bfs()<<"\n";
    }
}
