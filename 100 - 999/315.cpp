#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d,kk,time_;
vector < int > graph [ 101 ];
bool visited [ 101 ];
int parent [ 101 ],dis[ 101 ],lo[ 105 ];
set< int > ans;
int F_A_P( int source );
int main()
{
    while ( scanf("%d",&n) == 1 && n )
    {
        ans.clear();
        kk = time_ = 0;
        for ( int i = 0; i <= n; i++ )
        {
            parent [ i ] = dis [ i ] = visited [ i ] = 0;
            lo [ i ] = 9999;
            graph [ i ].clear();
        }
        string s;
        while(getline(cin,s))
        {
            if ( s == "0" )break;
            stringstream ss( s );
            string token;
            c = 0;
            while(ss >> token )
            {
               if ( !c )
               {
                   int sz = token.size();
                   a = 0;
                   for ( int i = 0; i != sz; i++ )
                   {
                       a*= 10;
                       a+= token [ i ] - '0';
                   }
                   c++;
               }
               else
               {
                  b = 0;
                  int sz = token.size();
                  for ( int i = 0; i != sz; i++ )
                  {
                      b*= 10;
                      b+= token [ i ] - '0';
                  }
                  graph [ a ].push_back ( b );
                  graph [ b ].push_back ( a );
               }
            }
        }
        F_A_P( 1 );
        if ( kk >= 2 )ans.insert( 1 );
        printf("%d\n",ans.size());
    }
    return 0;
}
int F_A_P( int source )
{
    visited [ source ] = 1;
    time_++;
    dis [ source ] = lo [ source ] = time_;
    int sz = graph [ source ].size();
    for ( int i = 0; i != sz; i++ )
    {
        int o_o = graph [ source ] [ i ];
        if ( parent [ source ] == o_o )continue;
        if ( visited [ o_o ] )
        {
            lo [ source ] = min( dis[ o_o ], lo [ source ] );
            continue;
        }
        parent [ o_o ] = source;
        F_A_P( o_o );
        lo [ source ] = min( lo [ source ] , lo [ o_o ] );
        if ( dis [ source ] <= lo [ o_o ] && source != 1)
        {
            ans.insert( source );
        }
        if ( source == 1 )kk++;
    }
    return 0;
}
