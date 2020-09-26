#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m = 1,aa=0;
    vector < int > graph[22];
    while(scanf("%d",&n) == 1)
    {
        if ( m == 1)
        {
            for ( int i = 0 ; i != 21; i++ ) graph[i].clear();
        }
        for(int i = 0 ; i < n; i++)
        {
            int a;
            scanf("%d",&a);
            graph[ m ].push_back( a );
            graph[ a ].push_back( m );
        }
        m++;
        if( m == 20 )
        {
            printf("Test Set #%d\n",++aa);
            m = 1;
            int query;
            scanf("%d",&query);
            for( int i = 0; i != query; i++ )
            {
                int source,target;
                scanf("%d%d",&source,&target);
                queue < int > qu;
                qu.push( source );
                bool visited [ 22 ];
                memset(visited, 0 , sizeof visited);
                visited [ source ] = 1;
                int level [ 22 ];
                level [ source ] = 0;
                int c = 0;
                while(!qu.empty())
                {
                     int front_ = qu.front();
                     qu.pop();
                     int sz = graph[front_].size();
                     for ( int j = 0; j != sz; j++ )
                     {
                         int gg = graph [ front_ ][ j ];
                         if( !visited [ gg ] )
                         {
                             visited [ gg ] = 1 ;
                             level [ gg ] = level [ front_ ] +1 ;
                             qu.push( gg );
                             if ( gg == target ){c = 1 ; break;}
                         }
                     }
                     if ( c )break;
                }
                printf("%2d to %2d: %1d\n",source,target,level[ target]);
            }
            printf("\n");
        }
    }
    return 0;
}
