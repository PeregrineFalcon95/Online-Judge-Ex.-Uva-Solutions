#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define inf ( int  )( 1e9 + 10 )
#define mxs (int)( 2e5 + 10 )
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
ll t, n, m,cases;
int timer = 0;
vector < pair < vector < int > , int > > v;
vector < int > graph [ mxs ];
bool visited [ mxs ];
int level [ mxs ], parent [ mxs ], finishTime [ mxs ];
stack < int > stk;
void topSort(int source );
void bfsAndFindAns();
void inputAndMakeGraphs();
void brainfuck();
int main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    while( cin>>n>>m )
    {
        //Clear Part
        for ( int i = 0; i <= n; i++ )
        {
            level [ i ] = 0;
            graph [ i ].clear();
            visited [ i ] = 0;
        }
        v.clear();
        inputAndMakeGraphs();
        bfsAndFindAns();
    }
}
void inputAndMakeGraphs()
{
    //Taking input and soring the input
    for ( int i = 1; i <= n; i++ )
    {
        pair < vector < int >, int > temp;
        temp.second = i;
        for ( int j = 0; j < m; j++ )
        {
            int a;
            cin>>a;
            temp.first.push_back( a );
        }
        sort( temp.first.begin(), temp.first.end() );
        v.push_back( temp );
    }
    sort( v.begin(), v.end() );

    //Based on dimension arrays, making directed graph
    for ( int i = 0 ; i < n; i++ )
    {
        for ( int j = i + 1; j < n; j++ )
        {
            bool isFitted = true;
            for ( int k = 0; k < m; k++ )
            {
                if ( v [ i ].first [ k ] >= v [ j ].first [ k ] )
                {
                    isFitted = false;
                    break;
                }
            }
            if ( isFitted == true )
            {
                graph [ v [ j ].second ].push_back( v [ i ].second );
            }
        }
    }
}

void bfsAndFindAns()
{
    for ( int i = 1; i <= n ; i++ )
        if ( !visited [ i ] )topSort( i );

    queue < int > qu;
    int id = 1;
    int mx = 1;

    for ( int i = 0; i <= n; i++ )visited [ i ] = 0;

    while( !stk.empty() )
    {
        if ( visited [ stk.top() ] ){stk.pop(); continue;}
        qu.push(stk.top());
        level [ stk.top() ] = 1;
        parent [ stk.top() ] = stk.top();
        stk.pop();

        while( !qu.empty() )
        {
            int a = qu.front();
            visited [ a ] = true;
            qu.pop();
            int sz = graph [ a ].size();
            for ( int i = 0 ; i < sz; i++ )
            {
                int b = graph [ a ] [ i ];
                if ( level [ b ] < level [ a ] + 1)
                {
                    level [ b ] = level [ a ] + 1;
                    if ( level [ b ] > mx )
                    {
                        mx = level [ b ];
                        id = b;
                    }
                    parent [ b ] = a;
                    qu.push(b);
                }
            }
        }

    }

    cout<<mx<<"\n";
    cout<<id;
    for ( int i = id; i != parent [ i ]; i = parent [ i ] )
    {
        cout<<" "<<parent [ i ];
    }
    cout<<"\n";
}
void topSort(int source )
{
    visited [ source ] = 1;
    int sz = graph [ source ].size();
    for ( int i = 0; i < sz; i++ )
    {
        int a = graph [ source ] [ i ];
        if ( !visited [ a ] )
        {
            topSort( a );
        }
    }
    stk.push( source );
}