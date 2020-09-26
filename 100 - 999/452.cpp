///** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define inf ( int  )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
//#define md  int mid = ( l + r )>>1;
int dx[]={+1,-1,+0,+0};///Four Directions
int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int ans, t, n, m, i, j , k, a, b, c, d, e,f, sz, q,cases , sum;
string s , s2 , s3 , s4;
int ar [ mxs ] ;
int dis [ mxs ];
int grid [ 110 ] [ 110 ];
vector < pair < int , int > > graph [ 110 ];
bool visited [ mxs ];
stack < int > stk;
void clear_();
void brainfuck();
void dfs( int source );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>t;
    cin.ignore();
    cin.ignore();
    while( t-- )
    {
        ans = 0;
        if ( f )cout<<"\n";
        f++;
        clear_();
        n = 0;
        while( getline( cin , s ) )
        {
            if ( !s.size() )break;
            stringstream ss ( s );
            e = 0;
            while( ss >> s2 )
            {
                if ( !e )
                {
                    a = s2 [ 0 ] - 'A' + 1;
                    n = max( a , n );
                }
                else if ( e == 1 )
                {
                    ///Cost
                    b = 0;
                    for ( i = 0 ; i < s2.size(); i++ )
                    {
                        b *= 10;
                        b += s2 [ i ] - '0';
                    }
                    dis [ a ] = b;
                    ans = max( ans , b );
                }
                else
                {
                    for ( i = 0 ; i < s2.size(); i++ )
                    {
                        b = s2 [ i ] - 'A' + 1;
                        graph [ b ].push_back( { a , 0 } );
                    }
                }
                e++;
            }
        }
        for ( i = 1 ; i <= n; i++ )
        {
            int sz = graph [ i ].size();
            for ( j = 0 ; j < sz; j++ )
            {
                graph [ i ] [ j ].second = dis [ graph [ i ] [ j ].first ];
            }
        }
        for ( i =1 ; i <= n; i++ )
        {
            if ( !visited [ i ] )dfs( i );
        }
        while( !stk.empty() )
        {
            a = stk.top();
            stk.pop();
            int sz = graph [ a ].size();
            if ( dis [ a ] )
            {
                for ( i = 0 ; i < sz; i++ )
                {
                    b = graph [ a ] [ i ].first;
                    c = graph [ a ] [ i ].second;
                    if ( dis [ b ] < dis [ a ] + c )
                    {
                        dis [ b ] = dis [ a ] + c;
                        ans = max( ans , dis [ b ]  );
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}
void dfs( int source )
{
    visited [ source ] = 1;
    int sz = graph [ source ].size();
    for ( int ii = 0 ; ii < sz; ii++ )
    {
        int bb = graph [ source ] [ ii ].first;
        if ( !visited [ bb ] )dfs( bb );
    }
    stk.push( source );
}
void clear_()
{
    for ( i = 0 ; i <= 26; i++ )
    {
        graph [ i ].clear();
        dis [ i ] = 0;
        visited [ i ] = 0;
    }
}
