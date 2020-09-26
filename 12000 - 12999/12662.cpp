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
#define mod ( ll  ) ( 1e9 + 7 )  //( 1e9 + 7 )
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)(1e6+10)//( 1e6 + 10 )
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves
int n, m, t, ans , k;
int ar [ mxs ] ;
string s , s2;
void brainfuck();
int main()
{
    //freopen("tour.in","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>n;
    vector < int > graph [ n + 2 ];
    bool visited [ n + 2 ];
    int level [ n + 2 ];
    vector < string > v;
    queue < pair < int , int > > qu;
    map < int , vector < pair < int , int > > > mp;
    v.push_back("!");

    for ( int i = 2 ; i <= n; i++ )
    {
        graph [ i ].push_back( i - 1 );
        graph [ i - 1 ].push_back( i );
    }
    memset( visited , 0 , sizeof visited );

    for ( int i = 1 ; i <= n; i++ )
    {
        cin>>s;
        v.push_back( s );
        if ( s != "?" )
        {
            qu.push( { i , i } );
            visited [ i ] = 1;
            level [ i ] = 0;
        }
    }

    int a , b , sz , ss;
    while( !qu.empty() )
    {
        a = qu.front().first;
        ss = qu.front().second;
        qu.pop();
        int sz = graph [ a ].size();
        for ( int i = 0 ; i < sz; i++ )
        {
            b = graph [ a ] [ i ];
            if ( !visited [ b ] )
            {
                visited [ b ] = 1;
                level [ b ] = level [ a ] + 1;
                qu.push( { b , ss } );
                mp [ b ].push_back( { ss , level [ b ] } );
            }
            else if ( level [ b ] == level [ a ] + 1 )
            {
                mp [ b ].push_back( { ss , level [ b ] } );
            }
        }
    }

    cin>>m;

    while( m-- )
    {
        cin>>a;
        if ( v [ a ] != "?" )
        {
            cout<<v [ a ]<<"\n";
        }
        else
        {
            sort( mp [ a ].begin() , mp [ a ].end() );
            if ( mp [ a ].size() == 2 )
            {
                cout<<"middle of "<<v [ mp [ a ] [ 0 ].first ] <<" and "<<v [ mp [ a ] [ 1 ].first ]<<"\n";
            }
            else
            {
                b = mp [ a ] [ 0 ].first;

                sz = mp [ a ] [ 0 ].second;
                while( sz-- )
                {
                    if ( b > a )cout<<"left of ";
                    else cout<<"right of ";
                }
                cout<<v [ b ]<<"\n";
            }
        }
    }
}

