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
int n , m, t, ans, cases ;
string s , s2;
deque < int > pathCollection;
int rods [ 32 ] , shop1 [ 32 ] [ 35 ] , shop2 [ 32 ] [ 35 ] , dp [ 32 ] [ 305 ] , path [ 32 ] [ 305 ];
int rec( int idx , int rem1 , int completed )
{
    if ( idx > n )return 0;
    if ( dp [ idx ] [ rem1 ] != -1 )return dp [ idx ] [ rem1 ];

    int rem2 = ( m - completed ) - rem1;
    dp [ idx ] [ rem1 ] = inf;
    for ( int i = 0 ; i <= rods [ idx ]; i++ )
    {
        if ( i <= rem1 && rem2 >= rods [ idx ] - i )
        {
            int temp = rec( idx + 1 , rem1 - i , completed + rods [ idx ] ) + shop1 [ idx ] [ i ] + shop2 [ idx ] [ rods [ idx ] - i ];
            if ( temp < dp [ idx ] [ rem1 ] )
            {
                dp [ idx ] [ rem1 ] = temp;
                path [ idx ] [ rem1 ] = i;
            }
        }
    }
    return dp [ idx ] [ rem1 ];
}
void pathFinder( int idx , int rem1 )
{
    if ( idx > n )return;
    pathCollection.push_back( path [ idx ] [ rem1 ] );
    pathFinder( idx + 1 , rem1 - path [ idx ] [ rem1 ] );
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
    int t1, t2;
    while( cin>>t1>>t2 && (t1 || t2) )
    {
        memset( dp , -1, sizeof dp );
        cin>>n;
        m = t1 + t2;
        for ( int i = 1 ; i <= n; i++ )
        {
            cin>>rods [ i ];

            for ( int j = 1 ; j <= rods [ i ]; j++ )cin>>shop1 [ i ] [ j ];

            for ( int j = 1 ; j <= rods [ i ]; j++ )cin>>shop2 [ i ] [ j ];
        }
        int x = rec( 1 , t1 , 0 );
        cout<<x<<"\n";
        pathFinder( 1 , t1 );
        while( !pathCollection.empty() )
        {
            m = pathCollection.front();
            pathCollection.pop_front();
            cout<<m;
            if ( !pathCollection.empty() )cout<<" ";
        }
        cout<<"\n\n";
    }
}
