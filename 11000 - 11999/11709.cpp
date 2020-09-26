#include<bits/stdc++.h>
using namespace std;
int p,t;
string name,name2;
map < string , vector < string > > graph , graph_reverse;
map < string , char > color;
stack < string > stk;
void dfs( string source );
void dfs2 ( string source );
int main()
{
    while ( scanf("%d%d",&p,&t) == 2 && ( p || t ) )
    {
        getchar();
        while ( !stk.empty() )stk.pop();
        color.clear();
        graph.clear();
        graph_reverse.clear();
        for ( int i = 0; i != p; i++ )
        {
            getline(cin,name);
            color [ name ] = 'w';
        }
        for ( int i = 0; i != t; i++ )
        {
            getline(cin,name);
            getline(cin,name2);
            graph [ name ].push_back ( name2 );
            graph_reverse [ name2 ].push_back ( name );
        }
        map < string , char > ::iterator it;
        for ( it = color.begin(); it != color.end(); it++ )
        {
            if ( it->second == 'w' )
            {
                dfs( it->first );
            }
        }
        for ( it = color.begin() ; it != color.end(); it++ )
        {
            it->second = 'w';
        }
        int ans = 0;
        while ( !stk.empty() )
        {
            name = stk.top();
            stk.pop();
            if ( color [ name ] == 'w' )
            {
                ans++;
                dfs2( name );
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
void dfs( string source )
{
    color [ source ] = 'g';
    int sz = graph [ source ].size();
    for ( int i = 0; i != sz; i++ )
    {
        string o_o = graph [ source ] [ i ];
        if ( color [ o_o ] == 'w' )dfs( o_o );
    }
    stk.push( source );
}
void dfs2 ( string source )
{
    color [ source ] = 'g';
    int sz = graph_reverse [ source ].size();
    for ( int i = 0; i != sz; i++ )
    {
        string o_o = graph_reverse[ source ] [ i ] ;
        if ( color [ o_o ] == 'w' )
        {
            dfs2( o_o );
        }
    }
}
