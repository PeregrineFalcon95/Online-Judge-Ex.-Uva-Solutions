#include<bits/stdc++.h>
using namespace std;
pair < int, pair < int, char > > ans;
int cases, row, col,i, x, y,a, b, c,e;
char dir;
char grid [ 100 ] [ 100 ];
deque < char > dq;
string s ;
pair < int, pair < int, char > > bfs();
bool check( int ll, int kk )
{
    return !( ll < 0 || kk < 0 || ll == row || kk == col || grid [ ll ] [ kk ] == '*' );
}
int main()
{
    scanf("%d",&cases);
    e = cases - 1 ;
    getchar();
    while ( cases-- )
    {
        if ( e != cases )
        {
            putchar( 10 );
            getchar();
        }
        dir = 'N';
        scanf("%d%d",&row,&col);
        for ( i = 0; i != row; i++ )
            scanf(" %[^\n]",&grid [ i ] );
        scanf("%d%d",&x,&y);
        getchar();
        dq.clear();
        while ( getline(cin,s) )
        {
            a = s.size();
            for ( i = 0; i != a; i++ )
            {
                if(s [ i ] != ' ' )
                    dq.push_back( s [ i ] );
            }
            if ( s [ i - 1 ] == 'Q' )break;
        }
        ans = bfs();
        printf("%d %d %c\n",ans.first,ans.second.first,ans.second.second);
    }
    return 0;
}
pair < int, pair < int, char > > bfs()
{
    x--;
    y--;
    char v;
    while ( !dq.empty() )
    {
        v = dq.front();
        if ( v  == 'R' )
        {
            if ( dir == 'N' )dir = 'E';
            else if ( dir == 'E' )dir = 'S';
            else if ( dir == 'S' )dir = 'W';
            else if ( dir == 'W' )dir = 'N';
        }
        else if ( v == 'L' )
        {
            if ( dir == 'N' )dir = 'W';
            else if ( dir == 'W' )dir = 'S';
            else if ( dir == 'S' )dir = 'E';
            else if ( dir == 'E' )dir = 'N';
        }
        else if ( v == 'F' )
        {
            if ( dir == 'N' )
            {
                a = x - 1;
                b = y;
                if ( check( a , b ) )x = a;
            }
            else if ( dir == 'E' )
            {
                a = x;
                b = y + 1;
                if ( check( a , b ) )y = b;
            }
            else if ( dir == 'S' )
            {
                a = x + 1 ;
                b = y;
                if ( check( a , b ) )x = a;
            }
            else if ( dir == 'W' )
            {
                a = x;
                b = y - 1;
                if ( check( a , b ) )y = b;
            }
        }
        else
        {
            ans.first = x + 1;
            ans.second.first = y + 1;
            ans.second.second = dir;
            return ans;
        }
        dq.pop_front();
    }
}
