#include<bits/stdc++.h>
using namespace std;
int row, col,source_row,source_col;
char language;
char grid [ 1002 ] [ 1002 ];
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
bool check(int i, int j ){ return !(i < 0 || j < 0 || i >= row || j >= col || grid [ i ] [ j ] != language ); }
void flood_bfs();
int main()
{
    int n,cases = 0;
    scanf("%d",&n);
    while ( n-- )
    {
        map < char, int > mapping;
        scanf("%d%d",&row,&col);
        getchar();
        for ( int i = 0; i != row; i++ )
        {
            scanf("%s",&grid [ i ] );
            for ( int j = 0; j != col; j++ )
            {
                mapping [ grid [ i ] [ j ] ] = 0;
            }
        }
        for ( int i = 0; i != row; i++ )
        {
            for ( int j = 0; j != col; j++ )
            {
                if ( grid [ i ] [ j ] != '*' )
                {
                    source_row = i;
                    source_col = j;
                    language = grid [ i ] [ j ];
                    mapping [ language ]++;
                    flood_bfs();
                }
            }
        }
        map < char , int > ::iterator it;
        multimap < int , char > multi;
        for ( it = mapping.begin(); it != mapping.end(); it++ )
        {
            multi.insert( pair < int, char > ( it->second, it->first ) );
        }
        printf("World #%d\n",++cases);
        multimap < int, char > ::iterator tt = multi.end();
        tt--;
        deque < pair < char, int > > dq;
        vector < pair < char, int > > v;
        int jjj = 0;
        for ( ; ; )
        {
            int ccc = tt->first;
            v.clear();
            while ( tt->first == ccc )
            {
                v.push_back( pair < char, int > (tt->second, tt->first ) );
                if (tt == multi.begin() ){jjj=1;break;}
                tt--;
            }
            while ( !v.empty() )
            {
                dq.push_back( pair < char , int > ( v.back().first,v.back().second));
                v.pop_back();
            }
            if ( jjj )break;
        }
        int sz = dq.size();
        for ( int i = 0; i != sz; i++ )printf("%c: %d\n",dq[i].first,dq[i].second);
    }
    return 0;
}
void flood_bfs()
{
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > ( source_row,source_col ) );
    grid [ source_row ] [ source_col ] ='*';
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 4; i++ )
        {
            int rr = dx [ i ] + front_row;
            int cc = dy [ i ] + front_col;
            if ( check ( rr, cc ) )
            {
                grid [ rr ] [ cc ] ='*';
                qu.push( pair < int , int > (rr,cc) );
            }
        }
    }
}
