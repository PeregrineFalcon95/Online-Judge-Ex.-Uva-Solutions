///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#define inf ( int )( 1e8 )
#define mxs (int)( 1e6 + 10 )
#define ll long long int
#define md  int mid = ( l + r )>>1;
int dx[]={+1,-1,+0,+0};///Four Directions
int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, i, j, ans, k, a, b, c, d, e, row, col,sz,f ;
string s, s2, s3, s4;
//int ar [ mxs ], ar2 [ mxs ];
double dir [ 2 ] [ 550 ];
bool visited [ 550 ];
int parent [ 550 ];
double dis [ 550 ];
vector < pair < int , double > > graph [ 550 ];
priority_queue < pair < double , int > > pq;
priority_queue < pair < double , pair < int , int > > > pq2;
void brainfuck();
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    double x , y , z;
    cin>>t;
    while( t-- )
    {
        cin>>m>>n;
        for ( i = 1 ; i <= n; i++ )
        {
            graph [ i ].clear();
            visited [ i ] = 0;
            dis [ i ] = 99999999999999999.00;
        }
        for ( i = 1 ; i <= n ; i++ )
            cin>>dir [ 0 ] [ i ]>>dir [ 1 ] [ i ];
        for ( i = 1 ; i <= n ; i++ )
        {
            for ( j = i + 1 ; j <= n; j++ )
            {
                x = ( dir [ 0 ] [ i ] - dir [ 0 ] [ j ] ) * ( dir [ 0 ] [ i ] - dir [ 0 ] [ j ] );
                y = ( dir [ 1 ] [ i ] - dir [ 1 ] [ j ] ) * ( dir [ 1 ] [ i ] - dir [ 1 ] [ j ] );
                x = sqrt( x + y );
                graph [ i ].push_back ( { j , x } );
                graph [ j ].push_back ( { i , x } );
            }
        }
        pq.push( { 0.00 , 1 } );
        dis [ 1 ] = 0.00;
        parent [ 1 ] = -1;
        while( !pq.empty() )
        {
            a = pq.top().second;
            pq.pop();
            if ( visited [ a ] )continue;
            visited [ a ] = 1;
            sz = graph [ a ].size();
            for ( i = 0 ; i < sz; i++ )
            {
                b = graph [ a ] [ i ].first;
                x = graph [ a ] [ i ].second;
                if ( !visited [ b ] && x < dis [ b ] )
                {
                    dis [ b ] =  x;
                    pq.push( { -x , b } );
                    parent [ b ] = a;
                }
            }
        }
        vector < double > lol;
        for ( i = 2 ; i <= n ;i++ )
        {
            lol.push_back( dis [ i ] );
        }
        double xxx = 0.00;
        sort( lol.begin() , lol.end() );
        reverse( lol.begin() , lol.end() );
        xxx = lol [ m - 1 ];
        cout<<fixed<<setprecision(2)<<xxx<<"\n";
    }
}


