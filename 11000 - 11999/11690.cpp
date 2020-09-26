#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define md int mid = ( l + r )>>1;
#define mxs ( int )( ( 1e5 + 7 ) )
vector < int > graph [ mxs ];
int ar [ mxs ];
bool visited [ mxs ];
//int dx[]={-2,-2,-1,1,-1,1,2,2};
//int dy[]={1,-1,-2,-2,2,2,-1,1};
//bool check( int x , int y ){ return !( 0 >= x || 0 >= y || x > 8 || y > 8 || visited [ x ] [ y ] ); }
int t, n, m, a, b, c, i, marker, ans, pos , sz , j;
void brain();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while( t-- )
    {
        c = 0;
        for ( i = 0; i <= 100000; i++ )graph [ i ].clear();
        cin>>n>>m;
        for ( i = 0; i < n ; i++ )
            cin>>ar [ i ];
        for ( i = 1 ; i <= m ; i++ )
        {
            cin>>a>>b;
            graph [ a ].push_back ( b );
            graph [ b ].push_back ( a );
        }
        memset( visited , 0 , sizeof visited );
        for ( i = 0; i < n; i++ )
            if ( !visited [ i ] )brain();
        if ( !c )cout<<"POSSIBLE\n";
        else cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
void brain()
{
    ans = ar [ i ];
    queue < int > qu;
    qu.push( i );
    visited [ i ] = 1;
    while( !qu.empty() )
    {
            a = qu.front();
            qu.pop();
            sz = graph [ a ].size();
            for ( j = 0; j != sz; j++ )
            {
                    b = graph [ a ] [ j ];
                    if ( !visited [ b ] )
                    {
                            qu.push( b );
                            ans += ar [ b ];
                            visited [ b ] = 1;
                    }
            }
    }
    //cout<<ans<<" kk "<<endl;
    if ( ans )c = 1;
}

