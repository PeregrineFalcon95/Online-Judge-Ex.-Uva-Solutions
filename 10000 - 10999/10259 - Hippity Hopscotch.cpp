#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define inf ( int  )( 1e9 + 10 )
#define mxs (int)( 2e5 + 10 )
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
//#define md  int mid = ( l + r )>>1;
int dx[]={+1,-1,+0,+0};///Four Directions
int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
ll t, n, m,cases;
ll grid [ 110 ] [ 110 ], dis [ 110 ] [ 110 ];
bool checker( int x , int y )
{
    return !( x < 1 || y < 1 || x > n || y > n );
}
void brainfuck();
int main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>t;
    //t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>n>>m;
    for ( int i = 1 ; i <= n; i++ )
        for ( int j = 1; j <= n; j++ )cin>>grid [ i ] [ j ];
    memset( dis, 0, sizeof dis );

    priority_queue< pair < ll , pair < ll , ll > > > pq;

    pq.push( make_pair( grid [ 1 ] [ 1 ], make_pair( 1, 1 ) ) );
    dis [ 1 ] [ 1 ] = grid [ 1 ] [ 1 ];
    ll mx = dis [ 1 ] [ 1 ];
    while( !pq.empty() )
    {
        ll cost = pq.top().first;
        ll a = pq.top().second.first;
        ll b = pq.top().second.second;
        pq.pop();
        for ( int i = 0 ; i < 4; i++ )
        {
            for ( int j = 1; j <= m; j++ )
            {
                ll c = a + dx [ i ] * j;
                ll d = b + dy [ i ];
                if ( checker(c , d ) && grid [ a ] [ b ] < grid [ c ] [ d ] && dis [ c ] [ d ] < dis [ a ] [ b ] + grid [ c ] [ d ] )
                {
                    dis [ c ] [ d ] = dis [ a ] [ b ] + grid [ c ] [ d ];
                    mx = max( dis [ c ] [ d ] , mx );
                    pq.push( make_pair( dis [ c ] [ d ] , make_pair( c , d )  ) );
                }

                c = a + dx [ i ];
                d = b + dy [ i ] * j;
                if ( checker(c , d ) && grid [ a ] [ b ] < grid [ c ] [ d ] && dis [ c ] [ d ] < dis [ a ] [ b ] + grid [ c ] [ d ] )
                {
                    dis [ c ] [ d ] = dis [ a ] [ b ] + grid [ c ] [ d ];
                    mx = max( dis [ c ] [ d ] , mx );
                    pq.push( make_pair( dis [ c ] [ d ] , make_pair( c , d )  ) );
                }
            }
        }
    }
    cout<<mx<<"\n";
    if ( t )cout<<"\n";
}
