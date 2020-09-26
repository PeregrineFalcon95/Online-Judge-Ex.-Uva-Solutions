#include<bits/stdc++.h>
using namespace std;
#define mx 100100
int n,m,t,x,y,q,i,j,ans,lll;
int  ar2 [ mx ], marker [ mx ];
int ar [ 3 ] [ mx ], tree [ 3 ] [ mx * 4 ];
void make_tree( int node, int a, int b );
int query( int node, int a, int b, int e, int f );
int main()
{
    while(scanf("%d",&m ) == 1 && m )
    {
        memset(tree, -1 , sizeof tree);
        scanf("%d",&q);
        for ( i = 1; i <= m; i++ )
        {
            scanf("%d",&ar2 [ i ] );
        }
        n = 0;
        j = x = 1;
        y = m + 1;
        ar2 [ y ] = 99999999;
        for ( i = 2; i <= y; i++ )
        {
            if ( ar2 [ i ] == ar2 [ i-1 ] )
            {
                j++;
            }
            else
            {
                ar [ 0 ] [ ++n ] = j;
                ar [ 1 ] [ n ] = x;
                ar [ 2 ] [ n ] = i-1;
                for ( int k = x; k != i; k++ )
                {
                    marker [ k ] = n;
                }
                x = i;
                j = 1;
            }
        }
        make_tree( 1, 1, n );

        for ( i = 0; i != q; i++ )
        {
            scanf("%d%d",&x, &y );
            ans = query( 1, 1, n, marker [ x ], marker [ y ] );
            printf("%d\n",ans);
        }
    }
    return 0;
}
void make_tree( int node, int a, int b )
{
    if ( a == b )
    {
        tree [ 0 ] [ node ] = ar [ 0 ] [ a ];
        tree [ 1 ] [ node ] = ar [ 1 ] [ a ];
        tree [ 2 ] [ node ] = ar [ 2 ] [ a ];
        return;
    }
    int left = node * 2;
    int right = ( node * 2 ) + 1;
    int mid = ( a + b ) / 2;
    make_tree ( left, a, mid );
    make_tree ( right, mid + 1, b );
    if ( tree [ 0 ] [ right ] > tree [ 0 ] [ left ] )
    {
        tree [ 0 ] [ node ] = tree [ 0 ] [ right ];
        tree [ 1 ] [ node ] = tree [ 1 ] [ right ];
        tree [ 2 ] [ node ] = tree [ 2 ] [ right ];
    }
    else
    {
        tree [ 0 ] [ node ] = tree [ 0 ] [ left ];
        tree [ 1 ] [ node ] = tree [ 1 ] [ left ];
        tree [ 2 ] [ node ] = tree [ 2 ] [ left ];
    }
}
int query( int node, int a, int b, int e, int f )
{
    if ( a > f || b < e )
    {
        return 0;
    }
    if ( e <= a && b <= f )
    {
        int lol = tree [ 0 ] [ node ];
        int g = tree [ 1 ] [ node ];
        int h = tree [ 2 ] [ node ];
        if( g >= h  )return 1;
        if ( x <= g && h <= y )
        {
            return lol;
        }
        else if ( x >= g  && y >= h )
        {
            int oo = 0;
            oo = query( ( node * 2 ) + 1 , ( ( a + b ) / 2 ) + 1 , b , e , f  );
            oo = max( query( node*2 , a , ( a + b )/2 , e , f ) , oo );
            return max ( ( h - x ) + 1 , oo );
        }
        else if ( x <= g && y <= h )
        {
            int oo = 0;
            oo = query( node*2 , a , ( a + b )/2 , e , f );
            oo = max( query( ( node * 2 ) + 1 , ( ( a + b ) / 2 ) + 1 , b , e , f  ) , oo );
            return max ( ( y - g ) + 1 , oo );
        }
        else if ( g <= x && y <= h  )
        {
            return ( y - x ) + 1;
        }
    }
    int left = node * 2;
    int right = ( node * 2 ) + 1;
    int mid = ( a + b ) / 2;
    int pp = query ( left, a, mid, e, f );
    int ll = query ( right, mid +1, b, e, f );
    return max( pp, ll );
}
