#include<bits/stdc++.h>
using namespace std;
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    getchar();
    while ( n-- )
    {
        string grid [ 35 ];
        int source_row, source_col ;
        int num = 0;
        while ( getline( cin,grid[num] ) )
        {
            int sz = grid [ num ].size();
            int o_o = 0;
            for ( int i = 0; i < sz ; i++ )
            {
                if( grid [ num ] [ i ] == '_' )
                {
                    o_o = 1;
                    break;
                }
            }
            if ( o_o )break;
            for ( int i = 0; i != sz; i++ )
            {
                if ( grid [ num ] [ i ] == '*' )
                {
                    source_row  = num ;
                    source_col = i ;
                    break;
                }
            }
            num++;
        }
        queue < pair < int, int > > qu;
        qu.push( pair < int, int > ( source_row, source_col ) );
        grid [ source_row ] [ source_col ] ='#';
        while ( !qu.empty() )
        {
            int front_row = qu.front().first;
            int front_col = qu.front().second;
            qu.pop();
            for ( int i = 0 ; i != 4; i++ )
            {
                int row = front_row + dx [ i ];
                int col = front_col + dy [ i ];
                int ss=0,ll = row;
                if ( row != front_row && row >= 0 )
                {
                    ss = grid [ row ].size();
                }
                else if ( row == front_row )ss =grid [ row ].size();
                else if ( row < 0 )continue;
                else if ( row >= num )continue;
                if ( col >=0 && col < ss )
                {
                    if ( grid [ row ] [ col ] == ' ' )
                    {
                        grid [ row ] [ col ] = '#';
                        qu.push( pair < int ,  int > ( row, col ) );
                    }
                }
            }
        }
        for ( int i = 0; i <= num; i++ )cout<<grid [ i ]<<"\n";
    }
    return 0;
}
