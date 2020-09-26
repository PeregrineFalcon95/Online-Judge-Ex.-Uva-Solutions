#include<bits/stdc++.h>
using namespace std;
int n,m,marker,cases;
string s,s2;
map < string , vector < string > > graph ,graph_reverse ;
map < string , char > color;
vector < string > ans [ 30 ];
stack < string > stk;
void dfs(string source );
void dfs2( string source );
int main()
{
    while( scanf("%d%d",&n,&m)==2 && ( n || m) )
    {
        for ( int i = 0; i != 30 ; i++ )ans[i].clear();
        graph.clear();
        graph_reverse.clear();
        color.clear();
        while ( !stk.empty() )stk.pop();
        for ( int i = 0 ; i != m; i++ )
        {
            cin>>s>>s2;
            graph [ s ].push_back( s2 );
            graph_reverse [ s2 ].push_back( s );
            color [ s ] = 'w';
            color [ s2 ] = 'w';
        }
        for ( map< string , char > ::iterator it = color.begin(); it != color.end(); it++ )
        {
            if ( it->second == 'w' )
            {
                dfs( it->first );
            }
        }
        for ( map< string , char > ::iterator it = color.begin(); it != color.end(); it++ )it->second = 'w';
        marker = -1;
        while ( !stk.empty() )
        {
            string ss = stk.top();
            stk.pop();
            if ( color [ ss ] == 'w' ){marker++; dfs2( ss );}
        }
        printf("Calling circles for data set %d:\n",++cases);
        for ( int i = 0; i <= marker; i++ )
        {
            int sz = ans [ i ].size();
            for ( int j = 0; j != sz; j++ )
            {
                if( j )printf(", ");
                cout<<ans [ i ] [ j ];
            }
            printf("\n");
        }
    }
    return 0;
}

void dfs(string source )
{
    color [ source ] ='g';
    int sz = graph [ source ].size();
    for ( int i = 0; i != sz ;i++ )
    {
        string o_o = graph [ source ] [ i ];
        if ( color [ o_o ] == 'w' )
        {
            dfs( o_o );
        }
    }
    stk.push( source );
}
void dfs2( string source )
{
    ans [ marker ].push_back( source );
    color [ source ] = 'g';
    int sz = graph_reverse [ source ].size();
    for ( int i = 0; i != sz ;i++ )
    {
        string o_o = graph_reverse [ source ] [ i ];
        if ( color [ o_o ] == 'w' )
        {
            dfs2( o_o );
        }
    }
}
