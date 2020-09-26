#include<bits/stdc++.h>
using namespace std;
int dx[]= {+1,-1,+0,+0};
int dy[]= {+0,+0,+1,-1};
int n,m,num,cases;
char grid [ 52 ] [ 52 ];
char ch;
bool check( int i, int j )
{
    return !( i < 0 || j < 0 || i >= n || j >= m || grid [ i ] [ j ] != ch );
}
void bfs( int source_row, int source_col );
int main()
{
    while ( scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        for ( int i = 0; i != n; i++ )
        {
            scanf("%s",&grid [ i ] );
        }
        map < int, vector < char > > mp;
        map < int,int > kk;
        for ( int i = 0; i != n; i++ )
        {
            for ( int j = 0; j != m; j++ )
            {
                if ( grid [ i ] [ j ] != '.' )
                {
                    num = 0;
                    ch = grid [ i ] [ j ];
                    bfs( i, j ) ;
                    mp [ num ].push_back ( ch );
                    kk [ num ]++;
                }
            }
        }
        map < int, vector < char > > ::iterator it = mp.end();
        printf("Problem %d:\n",++cases);
        if ( mp.size() )it--;
        for ( ; ; it-- )
        {
            vector < char > l;
            int sz = kk [ it->first ];
            int h = it->first;
            for ( int j = 0; j != sz; j++ )
            {
                l.push_back ( mp [ h ] [ j ] );
            }
            sort(l.begin(),l.end());
            for ( int k = 0; k != sz ; k++ )printf("%c %d\n",l [ k ], it->first);
            if(it == mp.begin() )break;
        }
    }
    return 0;
}
void bfs( int source_row, int source_col )
{
    grid [ source_row ] [ source_col ] = '.';
    queue < pair < int,int > > qu;
    qu.push( pair < int, int > ( source_row, source_col ) );
    while ( !qu.empty() )
    {
        num++;
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 4; i++ )
        {
            int rr = dx [ i ] + front_row;
            int cc = dy [ i ] + front_col;
            if ( check( rr, cc ) )
            {
                grid [ rr ] [ cc ] = '.';
                qu.push( pair < int, int > ( rr, cc ) );
            }
        }
    }
}
