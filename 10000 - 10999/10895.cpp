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
int n, m, t, ans, cases;
string s , s2;
vector < pair < int , int > > v [ 10100 ];
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
        vector < int > temp;
        int a , b , x;
        a = max( n , m );
        for ( int i = 0 ; i <= a; i++ )
        {
            v [ i ].clear();
        }
        for ( int i = 1 ; i <= n; i++ )
        {
            cin>>x;
            for ( int j = 1 ; j <= x; j++ )
            {
                cin>>a;
                temp.push_back( a );
            }
            for ( int j = 1 ; j <= x; j++ )
            {
                cin>>a;
                v [ temp [ j -1 ] ].push_back( { i , a } );
            }
            temp.clear();
        }
        cout<<m<<" "<<n<<"\n";
        for ( int i = 1 ; i <= m; i++ )
        {
            cout<<v [ i ].size();
            for ( int j = 0; j < v [ i ].size(); j++ )
            {
                cout<<" "<<v [ i ] [ j ].first;
            }
            cout<<"\n";
            for ( int j = 0; j < v [ i ].size(); j++ )
            {
                if ( j )cout<<" ";
                cout<<v [ i ] [ j ].second;
            }
            cout<<"\n";
        }
    }
}
