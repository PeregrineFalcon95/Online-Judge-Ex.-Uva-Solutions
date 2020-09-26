#include<bits/stdc++.h>
using namespace std;
int dx[]= {+1,-1,+0,+0};
int dy[]= {+0,+0,+1,-1};
int n,a,b,num;
int grid [ 110 ][ 110 ];
bool check( int i, int j )
{
    return !( i < 0 || j < 0 || i >= n || j >= n );
}
int bfs( int i, int j);
int bfs_( int i, int j );
int main()
{
    while(scanf("%d",&n)==1 && n )
    {
        for ( int i = 0; i <= n; i++ )
        {
            for ( int j = 0; j <= n; j++ )grid [ i ] [ j ] = -1;
        }
        getchar();
        for ( int i = 1;  i != n; i++ )
        {
            string s;
            getline(cin,s );
            stringstream ss ( s );
            string token;
            int vv=0, uu=0,yy=0;
            while ( ss >> token )
            {
                int sz = token.size();
                for ( int l = 0; l != sz ; l++ )
                {
                    if ( !yy )
                    {
                        vv*=10;
                        vv+=token [ l ] - '0';
                    }
                    if ( yy )
                    {
                        uu*=10;
                        uu+=token [ l ] - '0';
                    }
                }
                if ( yy == 1 )
                {
                    grid [ vv-1 ][ uu-1 ] = i;
                    yy = -1;
                    vv = uu = 0;
                }
                yy++;
            }
        }
        int ans = 0, ccc = 0;
        for ( int i = 0; i != n && !ccc ; i++ )
        {
            for ( int j = 0; j != n && !ccc; j++ )
            {
                if ( grid [ i ] [ j ] == -1 )
                {
                    if(bfs_( i, j ) != n )ccc = 1;
                }
            }
        }
        int ar [ n+1 ];
        memset(ar, 0, sizeof ar );
        for ( int i = 0; i != n && !ccc ; i++ )
        {
            for ( int j = 0; j != n && !ccc; j++ )
            {
                if ( grid [ i ] [ j ] != -1 && grid [ i ] [ j ] != -2)
                {
                    num = grid [ i ] [ j ];
                    ar [ num ]++;
                    if ( ar [ num ] > 1 )
                    {
                        ans = 0;
                        ccc = 1;
                        break;
                    }
                    a = bfs( i, j );
                    if ( a != n )
                    {
                        ccc = 1;
                        break;
                    }
                }
            }
        }
        if ( ccc ) printf("wrong\n");
        else printf("good\n");
    }
    return 0;
}
int bfs( int i, int j )
{
    int a = 1;
    grid [ i ] [ j ] = -1;
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > ( i, j ) );
    while ( !qu.empty() )
    {
        int front_r = qu.front().first;
        int front_c = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 4; i++ )
        {
            int rr = dx [ i ] + front_r;
            int cc = dy [ i ] + front_c;
            if ( check(rr, cc ) && grid [ rr ] [ cc ] == num )
            {
                a++;
                qu.push( pair < int, int > ( rr,cc ) );
                grid [ rr ] [ cc ] = -1;
            }
        }
    }
    return a ;
}
int bfs_( int i, int j )
{
    int a = 1;
    grid [ i ] [ j ] = -2;
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > ( i, j ) );
    while ( !qu.empty() )
    {
        int front_r = qu.front().first;
        int front_c = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 4; i++ )
        {
            int rr = dx [ i ] + front_r;
            int cc = dy [ i ] + front_c;
            if ( check(rr, cc ) && grid [ rr ] [ cc ] == -1)
            {
                a++;
                qu.push( pair < int, int > ( rr,cc ) );
                grid [ rr ] [ cc ] = -2;
            }
        }
    }
    return a ;
}
