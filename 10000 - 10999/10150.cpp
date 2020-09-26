///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#define inf ( int )( 1e9 )
#define mxs (int)( 1e6 + 10 )
#define ll long long int
#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, i, j, ans, k, a, b, c, d, e, row, col,sz,f ;
string s, s2, s3, s4;
int ar [ mxs ], ar2 [ mxs ];
int cost [ 26000 ];
int parent [ mxs ];
vector < int > graph [ 26000 ];
map < string , int > mp;
map < int , string > mp2;
vector < string > v;
vector < int > vv;
priority_queue < pair < int , int > > pq;
void brainfuck();
void dij( int source , int target );
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
    while( getline( cin , s ) )
    {
        if ( !s.size() )break;
        v.push_back( s );
    }
    n = v.size();
    //cout<<n<<endl;
    for ( i = 0; i < n; i++ )
    {
        mp [ v [ i ] ] = ++a;
        mp2 [ a ] = v [ i ];
        //cout<<v [ i ]<<"  "<<a<<endl;
    }
    ///Making all possible combination
    for ( i = 0 ; i < n; i++ )
    {
        c = v [ i ].size();
        s = v [ i ];
        for ( j = 0 ; j < c; j++ )
        {
            for ( k = 0 ; k < 26; k++ )
            {
                s [ j ] = k + 'a';
                if ( k + 'a' == v [ i ] [ j ] )continue;
                if ( mp.find( s ) != mp.end() )
                {
                    a = mp [ s ];
                    b = mp [ v [ i ] ];
                    graph [ a ].push_back( b );
                    graph [ b ].push_back( a );
                }
            }
            s [ j ] = v [ i ] [ j ];
        }
    }
    while( cin>>s>>s2 )
        dij( mp [ s ] , mp [ s2 ] );
}
void dij( int source , int target )
{
    if ( f )cout<<"\n";
    f++;
    for ( i = 1 ; i <= 25500; i++ )cost [ i ] = inf;
    cost [ source ] = 0;
    while( !pq.empty() )pq.pop();
    pq.push( { 0 , source } );
    e = 0;
    parent [ source ] = -1;
    while( !pq.empty() )
    {
        a = pq.top().second;
        pq.pop();
        if ( a == target )
        {
            e = 1;
            break;
        }
        sz = graph [ a ].size();
        for ( i = 0 ; i < sz; i++ )
        {
            b = graph [ a ] [ i ];
            if ( cost [ a ] + 1 < cost [ b ] )
            {
                pq.push( { -(cost [ a ] + 1) , b } );
                cost [ b ] = cost [ a ] + 1;
                parent [ b ] = a;
            }
        }
    }
    if ( !e )cout<<"No solution.\n";
    else
    {
        vv.clear();
        while( parent [ target ] != -1 )
        {
            vv.push_back( target );
            target = parent [ target ];
        }
        vv.push_back( source );
        a = vv.size();
        for ( i = a-1 ; i >= 0; i-- )
        {
            cout<<mp2 [ vv [ i ] ]<<"\n";
        }
    }
}

