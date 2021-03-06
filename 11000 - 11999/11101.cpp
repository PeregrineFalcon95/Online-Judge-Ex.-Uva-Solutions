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
int dx[]={+1,-1,+0,+0};///Four Directions
int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
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

int n , m, x, t, ans, cases ;
string s , s2;
struct dat
{
    int row;
    int col;
    int sourceR;
    int sourceC;
};
queue < dat > qu;
int grid [ 2005 ] [ 2005 ];
bool checker( int x , int y )
{
    return !( x < 0 || y < 0 || x > 2000 || y > 2000 );
}
int multiSourceBfs()
{
    ans = inf;
    while( !qu.empty() )
    {
        int a = qu.front().row;
        int b = qu.front().col;
        int aa = qu.front().sourceR;
        int bb = qu.front().sourceC;
        qu.pop();
        for ( int i = 0 ; i < 4 ; i++ )
        {
            int c = dx [ i ] + a;
            int d = dy [ i ] + b;
            if ( checker( c , d ) && ( grid [ c ] [ d ] == -1 || grid [ c ] [ d ] == inf ) )
            {
                if ( grid [ c ] [ d ] == inf )
                {
                    ans = min( ans , abs( aa - c ) + abs( bb - d ) );
                }
                else
                {
                    dat x;
                    x.row = c;
                    x.col = d;
                    x.sourceR = aa;
                    x.sourceC = bb;

                    qu.push( x );
                    grid [ c ] [ d ] = 1;
                }
            }
        }
    }
    return ans;
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
    while( cin>>n && n )
    {
        dat x;
        while( !qu.empty() )qu.pop();
        memset( grid , -1 , sizeof grid );
        int a , b ;

        for ( int i = 1 ; i <= n; i++ )
        {
            cin>>a>>b;
            x.row = a;
            x.col = b;
            x.sourceR = a;
            x.sourceC = b;
            grid [ a ] [ b ] = 0;
            qu.push( x );
        }
        cin>>n;
        for ( int i = 1 ; i <= n; i++ )
        {
            cin>>a>>b;
            grid [ a ] [ b ] = inf;
        }
        cout<<multiSourceBfs()<<"\n";
    }
}
