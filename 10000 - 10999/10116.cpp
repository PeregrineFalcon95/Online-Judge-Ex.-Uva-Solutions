#include<bits/stdc++.h>
using namespace std;
int row,col,source;
bool check( int i, int j ){ return !( i < 0 || j < 0 || i >= row || j >= col ); }
int main()
{
    while ( scanf("%d%d%d",&row,&col,&source)==3 && ( row || col || source ) )
    {
        source--;
        char grid [ row+2 ] [ col+2 ];
        for ( int i = 0; i != row; i++ )scanf("%s",&grid[ i ]);
        queue < pair < int, int > > qu;
        bool visited [ row+2 ] [ col+2 ];
        memset(visited, 0, sizeof visited);
        visited [ 0 ] [ source ] = 1;
        qu.push ( pair < int, int > ( 0, source ) );
        int level [ row +2 ] [ col+2 ];
        memset(level, 0, sizeof level );
        while ( !qu.empty() )
        {
            int front_row = qu.front().first;
            int front_col = qu.front().second;
            qu.pop();
            char ch = grid [ front_row ] [ front_col ];
            int r,c;
            r = c = 0;
            if ( ch == 'W' )
            {
                r = front_row;
                c = front_col -1;
            }
            else if ( ch == 'E' )
            {
                r = front_row;
                c = front_col + 1;
            }
            else if ( ch == 'N' )
            {
                r = front_row - 1;
                c = front_col;
            }
            else if ( ch == 'S' )
            {
                r = front_row + 1;
                c = front_col;
            }
            ///Lets check the fucking direction
            if ( check ( r , c ) )
            {
                if ( visited [ r ] [ c ] )
                {
                    int o_o = level [ r ] [ c ]  - level [ 0 ] [ source ];
                    int w_w = level [ front_row  ] [ front_col ] - level [ r ] [ c ]+1;
                    printf("%d step(s) before a loop of %d step(s)\n",o_o,w_w);
                }
                else
                {
                    visited [ r ] [ c ] = 1;
                    level [ r ] [ c ] = level [ front_row ] [ front_col ] + 1;
                    qu.push( pair < int, int > ( r , c ) );
                }
            }
            else
            {
                int o_o = ( level [ front_row ] [ front_col ]  - level [ 0 ] [ source ] ) + 1;
                printf("%d step(s) to exit\n",o_o);
                break;
            }
        }
    }
    return 0;
}

