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
int dp [ 30010 ];
vector < pair < int , pair < int , int > > > v;
int rec( int idx )
{
    if ( idx >= n )return 0;
    int &p = dp [ idx ];
    if ( p != -1 )return p;
    p = rec( idx + 1 );
    int lo = idx , hi = n - 1, mid, next_ = -1;
    while( lo <= hi )
    {
        mid = ( lo + hi )>>1;
        if ( v [ mid ].first > v [ idx ].second.first)
        {
            hi = mid - 1;
            next_ = mid;
        }
        else lo = mid + 1;
    }
    if ( next_ == -1 )next_ = n;
    p = max( p , rec( next_ ) + v [ idx ].second.second );
    return p;
}
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    cin>>t;
    //t = 1;
    //scanf("%d",&t);
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    v.clear();
    cin>>n;
    int a , b , c;
    for ( int i = 0 ; i < n; i++ )
    {
        dp [ i ] = -1;
        cin>>a>>b>>c;
        b = a + b - 1;
        v.push_back( make_pair ( a , make_pair ( b ,c ) ) );
    }
    sort( v.begin() , v.end() );
    cout<<"Case "<<++cases<<": "<<rec( 0 )<<"\n";
}
