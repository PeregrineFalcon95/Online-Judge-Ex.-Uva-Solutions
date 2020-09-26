#include<bits/stdc++.h>
using namespace std;
int source_row,source_col,row,col;
char line,marker;
string grid [ 40 ];
int dx[]= {+1,-1,+0,+0};
int dy[]= {+0,+0,+1,-1};
bool  visited [ 35 ] [ 95 ];
bool check_2(int i, int j )
{
    return !( i < 0 || j < 0 || i >= row || visited [ i ] [ j ] ||  grid [ i ] [ j ] == marker );
}
void flood_2();
int main()
{
    row = -1;
    while( getline( cin, grid[ ++row ])  )
    {
        if ( grid[ row ] [ 0 ] == '_' )
        {
            memset(visited, 0, sizeof visited );
            int o_o = 0;
            for ( int i = 0; i !=  row; i++ )
            {
                int sz = grid [ i ].size();
                for ( int j = 0; j != sz; j++ )
                {
                    if ( !o_o && (grid [ i ] [ j ] != ' ' && grid [ i ] [ j ] != '_') )
                    {
                        o_o = 1;
                        marker = grid [ i ] [ j ];
                        break;
                    }
                }
                if ( o_o )break;
            }
            for ( int i = 0; i != row; i++ )
            {
                int sz = grid[ i ].size();
                for ( int j = 0; j != sz; j++ )
                {
                    if ( !visited [ i ] [ j ] && grid [ i ] [ j ] != ' ' &&grid [ i ] [ j ] != marker && grid [ i ] [ j ] != '_')
                    {
                        source_row = i;
                        source_col = j;
                        line = grid [ i ] [ j ];
                        flood_2();
                    }
                }
            }
            for ( int i = 0; i <= row; i++ )cout<<grid [ i ]<<endl;
            row = -1;
            continue;
        }
    }
    return 0;
}
void flood_2()
{
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > ( source_row, source_col ) );
    visited [ source_row ] [ source_col ] = 1;
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 4; i++ )
        {
            int rr = dx [ i ] + front_row;
            int cc = dy [ i ] + front_col;
            if ( check_2( rr, cc ) )
            {
                grid [ rr ] [ cc ] = line;
                qu.push( pair < int, int > ( rr, cc ) );
                visited [ rr ] [ cc ] = 1;
            }
        }
    }
}
