#include<bits/stdc++.h>
using namespace std;
#define pii pair < int , int >
int counter [ 110 ] [ 110 ] , grid [ 110 ] [ 110 ] , marker [ 110 ] [ 110 ];
bool visited [ 110 ] [ 110 ];
int n , m , a , b , c , d , e , f , t , cases , row , col , w , x , y ;
vector < pair < int , int > > v;
queue < pair < int , int > > qu;
bool checker( int i , int j )
{
    return !( i < 0 || j < 0 || i >= row || j >= col || grid [ i ] [ j ] == -1 || marker [ i ] [ j ] == 1 );
}
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        memset ( visited, 0, sizeof visited );
        memset ( counter, 0, sizeof counter );
        memset ( grid, 0, sizeof grid );
        scanf("%d%d%d%d",&row,&col,&n,&m);
        int dx [] = {+m,+m,-m,-m,-n,+n,-n,+n};
        int dy [] = {-n,+n,-n,+n,+m,+m,-m,-m};
        scanf("%d",&w);
        for ( int i = 0; i != w; i++ )
        {
            scanf("%d%d",&a,&b);
            grid [ a ] [ b ] = -1;
        }
        qu.push( pii  ( 0 , 0 ) );
        visited [ 0 ] [ 0 ] = 1;
        while ( !qu.empty() )
        {
            a = qu.front().first;
            b = qu.front().second;
            qu.pop();
            for ( int i = 0; i != 8; i++ )
            {
                x = dx [ i ] + a ;
                y = dy [ i ] + b ;
                if ( checker ( x , y ) )
                {
                    if ( !visited [ x ] [ y ] )
                    {
                        marker [ x ] [ y ] = 1;
                        v.push_back( pii ( x , y ) );
                        qu.push( pii ( x , y ) );
                        visited [ x ] [ y ] = 1;
                    }
                    else
                    {
                        marker [ x ] [ y ] = 1;
                        v.push_back( pii ( x , y ) );
                    }
                }
            }
            e = v.size();
            while ( !v.empty() )
            {
                x = v.back().first;
                y = v.back().second;
                marker [ x ] [ y ] = 0;
                v.pop_back();
            }
            if ( e&1 )counter [ a ] [ b ] = 1;
            else if ( !(e&1) )counter [ a ] [ b ] = 2;
        }
        a = b = 0;
        for ( int i = 0; i != row; i++ )
        {
            for ( int j = 0; j != col; j++ )
            {
                c = counter [ i ] [ j ];
                if ( c == 1 )a++;
                else if ( c == 2 )b++;
            }
        }
        printf("Case %d: %d %d\n",++cases,b,a);
    }
    return 0;
}

