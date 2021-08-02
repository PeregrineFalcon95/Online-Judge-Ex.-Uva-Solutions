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
int ar [ 210 ] , cum [ 210 ] , dp [ 210 ] [ 210 ] [ 32 ];
pair < int , int > path [ 210 ] [ 210 ] [ 32 ];
map < pair < int , int > , int > pathCollection;
pair < int , int > findAns( int le , int re ) ///For given range, return { total cost and where to put }
{
    pair < int , int > x;
    int temp;
    x.first = inf;
    for ( int i = le ; i <= re; i++ )
    {
        temp = ( ( ar [ i ] * ( i - le ) ) - ( cum [ i - 1 ] - cum[ le - 1 ] ) ) + ( ( cum [ re ] - cum [ i ] ) - ( ar [ i ] * ( re - i ) ) );
        if ( temp < x.first )
        {
            x.first = temp;
            x.second = i;
        }
    }
    return x;
}
int rec ( int le , int re , int k ) ///Find the optimal answer ans save path
{
    if ( re == n )
    {
        if ( !k )return findAns( le , re ).first;
        return inf;
    }
    if ( !k )return inf;
    int &p = dp [ le ] [ re ] [ k ];
    if ( p != -1 )return p;
    pair < int , int > x = findAns( le , re );
    p = inf;
    for ( int i = re + 1; i <= n; i++ )
    {
        if ( p > rec( re + 1 , i , k - 1 ) + x.first )
        {
            p = rec( re + 1 , i , k - 1 ) + x.first;
            path [ le ] [ re ] [ k ].first = re + 1;
            path [ le ] [ re ] [ k ].second = i;
        }
    }
    return p;
}
void finder( int le , int re , int k ) ///Find range and , where to put
{
    pathCollection [ { le , re } ] = findAns( le , re ).second;
    if ( re == n )return;
    finder( path [ le ] [ re ] [ k ].first , path [ le ] [ re ] [ k ].second , k - 1 );
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
    while( cin>>n>>m && n )
    {
        memset( dp , -1, sizeof dp );
        for ( int i = 1 ; i <= n; i++ )
        {
            cin>>ar [ i ];
            cum [ i ] = ar [ i ] + cum [ i - 1 ];
        }

        ans = inf;
        int idx = 0;
        for ( int i = 1; i <= n; i++ )
        {
            if ( rec( 1 , i , m - 1 ) < ans )
            {
                ans = rec( 1 , i , m - 1 );
                idx = i;
            }
        }
        pathCollection.clear();
        finder( 1 , idx , m - 1 );
        cout<<"Chain "<<++cases<<"\n";
        idx = 0;
        for ( map < pair < int , int > , int > ::iterator it = pathCollection.begin(); it != pathCollection.end(); it++ )
        {
            cout<<"Depot "<<++idx<<" at restaurant "<<it->second<<" serves restaurant";
            if ( it->first.first == it->first.second )cout<<" "<<it->first.first<<"\n";
            else cout<<"s "<<it->first.first<<" to "<<it->first.second<<"\n";
        }
        cout<<"Total distance sum = "<<ans<<"\n\n";
    }
}
