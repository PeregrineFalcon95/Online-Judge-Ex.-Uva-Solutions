#include<bits/stdc++.h>
using namespace std;
int row,col,n,m,source_row,source_col,cases,w_w,xxx;
int size_count [ 3000 ];
int  visited [ 52 ] [ 52 ];
char grid [ 100 ] [ 100 ];
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
bool check( int i, int j){ return !(i < 0 || j < 0 || i >= row || j >= col || grid [ i ] [ j ] == '.' );}
void flood();
int flood_2();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while ( scanf("%d%d",&col,&row) == 2 && ( row || col ) )
    {
        memset(size_count, 0 , sizeof size_count);
        memset(visited, 0 , sizeof visited );
        for ( int i = 0; i != row ; i++ )scanf("%s",&grid [ i ]);
        vector < int > ans;
        xxx = 0;
        for ( int i = 0; i != row; i++ )
        {
            for ( int j = 0; j != col; j++ )
            {
                if ( grid [ i ] [ j ] == '*' )
                {
                    xxx++;
                    source_row = i;
                    source_col = j;
                    flood();
                }
            }
        }
        xxx = 2501;
        for ( int i = 0; i != row; i++ )
        {
            for ( int j = 0; j != col; j++ )
            {
                if (grid [ i ] [ j ] == 'X' )
                {
                    int o_o = 0;
                    source_row = i;
                    source_col = j;
                    o_o = flood_2();
                    size_count [ o_o ] ++;
                }
            }
        }
        for ( int i = 0; i != 3000; i++ )
        {
            if ( size_count [ i ] )ans.push_back(size_count [ i ] );
        }
        sort(ans.begin(),ans.end());
        printf("Throw %d\n",++cases);
        int sz = ans.size();
        for ( int i = 0; i != sz; i++ )
        {
            if ( i )printf(" ");
            printf("%d",ans[ i ]);
        }
        printf("\n");
        printf("\n");
        w_w++;
    }
    return 0;
}
void flood()
{
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > ( source_row, source_col ) );
    if ( grid [ source_row ] [ source_col ] == '*' )
    {
        grid [ source_row ][source_col ] = '.';
        visited[ source_row ] [ source_col ] = -1;
    }
    else visited[ source_row ] [ source_col ] = xxx;
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 4; i++ )
        {
            int rr = dx [ i ] + front_row;
            int cc = dy [ i ] + front_col;
            if ( check( rr, cc ) )
            {
                if ( grid [ rr ] [ cc ] == 'X' && !visited [ rr ] [ cc ] )
                {
                    qu.push( pair < int, int > ( rr, cc ) );
                    visited [ rr ] [ cc ] = xxx;
                }
                else if ( grid [ rr ] [ cc ] == '*'  && visited [ rr ] [ cc ] != -1)
                {
                    qu.push( pair < int, int > (rr,cc) );
                    visited[ rr ] [ cc ] = -1;
                    grid [ rr ] [ cc ] = '.';
                }
            }
        }
    }
}
int flood_2()
{
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > ( source_row, source_col ) );
    grid[ source_row ] [ source_col ] = '.';
    int ttt = visited [ source_row ] [ source_col ];
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 4; i++)
        {
            int rr = dx [ i ] + front_row;
            int cc = dy [ i ] + front_col;
            if ( check( rr, cc ) )
            {
                grid[ rr ] [ cc ] ='.';
                qu.push(pair < int, int > ( rr,cc ) );
            }
        }
    }
    if ( !visited [ source_row ] [ source_col ] )
    {
        xxx++;
        return xxx;
    }
    return ttt;
}
