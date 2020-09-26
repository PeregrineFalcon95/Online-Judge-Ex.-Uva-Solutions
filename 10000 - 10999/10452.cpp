#include<bits/stdc++.h>
using namespace std;
int col,row,source_row,source_col,target_row,target_col;
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
bool visited [ 10 ] [ 10 ];
char graph[ 10 ] [ 10 ];
bool check(int i, int j){return !( visited [ i ] [ j ] || i < 0 || j < 0 || i >= row || j >= col || ( graph [ i ] [ j ] != '#' && graph [ i ] [ j ] !='I' && graph [ i ] [ j ] != 'E' && graph [ i ] [ j ] != 'H' && graph [ i ] [ j ] !='O' && graph [ i ] [ j ] != 'V' && graph [ i ] [ j ] != 'A'));}
void bfs();
int main()
{
    int t;
    scanf("%d",&t);
    while ( t-- )
    {
        source_row = source_col = target_col = target_row = -1;
        scanf("%d%d",&row,&col);
        getchar();
        for ( int i = 0; i != row ; i++ )
        {
            scanf("%s",&graph [ i ]);
            if ( source_row == -1 )
            {
                int sz = strlen( graph[ i ] );
                for ( int j = 0; j != sz; j++ )
                {
                    if( graph [ i ] [ j ] == '@' )
                    {
                        source_row = i;
                        source_col = j;
                    }
                }
            }
            if ( target_row == -1 )
            {
                int sz = strlen( graph[ i ] );
                for ( int j = 0; j != sz; j++ )
                {
                    if ( graph [ i ] [ j ] == '#' )
                    {
                        target_row = i;
                        target_col = j;
                    }
                }
            }
            getchar();
        }
        bfs();
    }
    return 0;
}
void bfs()
{
    queue < pair < int , int > > qu;
    memset ( visited, 0, sizeof visited );
    qu.push( pair < int, int > (source_row, source_col) );
    visited[ source_row ] [ source_col ] = 1;
    map < int , pair < int, int > > trace;
    while ( !qu.empty() )
    {
        int o_o = 0;
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 4; i++ )
        {
            int a = dx [ i ] + front_row;
            int b = dy [ i ] + front_col;
            if ( check ( a,b ) && !visited [ a ] [ b ] )
            {
                int aa=0;
                visited [ a ] [ b ] =1;
                if ( a != front_row ) aa = 1;
                else if ( b < front_col ) aa = 2;
                else if ( b > front_col ) aa = 3;
                int wz = (a*10)+b;
                int ss = (front_row*10)+front_col;
                trace [ wz ] = pair < int, int > ( ss, aa );
                if ( target_row == a && target_col == b ){o_o = 1;break;}
                qu.push( pair < int, int > (a , b) );
            }
        }
        if ( o_o ){break;}
    }
    int i_i = (target_row*10)+target_col;
    int o_o = (source_row*10)+source_col;
    vector < string > ans;
    while ( 1 )
    {
        if ( trace [ i_i ].second == 1 )
        {
            ans.push_back( "forth" );
            if (trace [ i_i ].first == o_o )break;
        }
        else if ( trace [ i_i ].second == 2 )
        {
            ans.push_back( "left" );
            if (trace [ i_i ].first == o_o )break;
        }
        else if ( trace [ i_i ].second == 3 )
        {
            ans.push_back( "right" );
            if (trace [ i_i ].first == o_o )break;
        }
        i_i = trace [ i_i ].first;
    }
    reverse ( ans.begin(), ans.end());
    for ( int i = 0; i != ans.size(); i++ )
    {
        if ( i )printf(" ");
        cout<<ans[i];
    }
    printf("\n");
}
