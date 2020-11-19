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
int com [ mxs ] , parent [ mxs ] ;
ll sum [ mxs ];
set < int > component [ mxs ];
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
        for ( int i = 1 ; i <= n; i++ )
        {
            component [ i ].clear();
            component [ i ].insert( i );
            parent [ i ] = i;
            com [ i ] = i;
            sum [ i ] = i;
        }
        int a, b, c, d, e;
        while( m-- )
        {
            cin>>c;
            if ( c == 1 )
            {
                ///Merge two sets
                cin>>a>>b;
                if ( component [ com [ a ] ].count( b ) == false  )
                {
                    d = component [ com [ a ] ].size();
                    e = component [ com [ b ] ].size();
                    if ( d < e )swap( a, b );
                    sum [ com [ a ] ] += sum [ com [ b ] ];
                    int x = com [ b ];
                    for ( set < int >::iterator it = component [ x ].begin(); it != component [ x ].end(); it++ )
                    {
                        component [ com [ a ] ].insert( *it );
                        com [ *it ] = com [ a ];
                    }
                    component [ x ].clear();
                }
            }
            else if ( c == 2 )
            {
                ///Insert a into b's set
                cin>>a>>b;
                if ( component [ com [ a ] ].count( b ) == false )
                {
                    sum [ com [ a ] ] -= a;
                    sum [ com [ b ] ] += a;
                    component [ com [ a ] ].erase( a );
                    component [ com [ b ] ].insert( a );
                    com [ a ] = com [ b ];
                }
            }
            else
            {
                ///Print the number of element and the sum
                cin>>a;
                //cout<<c<<" check "<<a<<endl;
                ll cc = sum [ com [ a ] ];
                b = component [ com [ a ] ].size();
                cout<<b<<" "<<cc<<"\n";
            }
        }
    }
}
