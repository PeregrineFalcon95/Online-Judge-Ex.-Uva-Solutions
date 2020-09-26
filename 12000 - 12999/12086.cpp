#include<bits/stdc++.h>
using namespace std;
#define mx 200100
int ar [ mx ], tree [ mx * 4 ];
int cases,n,t,a,b,c,x,ans;
char str [ 10 ];
void make_tree ( int node, int e, int f );
void update( int node, int e, int f  );
int query( int node, int e, int f );
void fastscan(int &number)
{
    register int c;

    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
int main()
{
    while( scanf("%d",&n) == 1 && n )
    {
        if ( t )putchar( 10 );
        printf("Case %d:\n",++cases);
        t++;
        memset(tree, 0, sizeof tree );
        for ( int i = 1; i <= n; i++ )scanf("%d",&ar [ i ] );
        make_tree( 1, 1, n );
        while( scanf("%s",&str ) )
        {
            //getchar();
            if ( str [ 0 ] == 'M' )
            {
                getchar();
                //scanf("%d%d",&a,&b);
                fastscan( a );
                fastscan( b );
                ans = query( 1, 1, n );
                printf("%d\n",ans);
            }
            else if ( str [ 0 ] == 'S' )
            {
                //scanf("%d%d",&a,&x);
                getchar();
                fastscan( a );
                fastscan( x );
                update( 1, 1, n );
            }
            else if ( str [ 0 ] == 'E' )break;
        }
    }
    return 0;
}
void make_tree ( int node, int e, int f )
{
    if ( e == f )
    {
        tree [ node ] = ar [ e ];
        return;
    }
    int left = node * 2;
    int right = ( node * 2 ) + 1;
    int mid = ( e + f ) / 2;
    make_tree ( left, e, mid );
    make_tree ( right, mid + 1, f );
    tree [ node ] = tree [ left ] + tree [ right ];
}
void update( int node, int e, int f )
{
    if ( a > f || a < e )return;
    if ( e == a && f == a )
    {
        tree [ node ] = x;
        return ;
    }
    int left = node * 2;
    int right = ( node * 2 ) + 1;
    int mid = ( e + f ) / 2;
    update( left, e, mid  );
    update( right, mid + 1, f );
    tree [ node ] = tree [ left ] + tree [ right ];
}
int query( int node, int e, int f )
{
    if ( e >= a && f <= b )
    {
        return tree [ node ];
    }
    int mid = ( e + f ) / 2;
    int left = node * 2;
    int right = ( node * 2 ) + 1;
    int q1 = 0, q2 = 0;
    if ( e > b || mid < a ) q1 = 0;
    else q1 = query( left, e, mid );
    if ( mid+1 > b || f < a ) q2 = 0;
    else q2 = query( right, mid + 1, f );
    return q1 + q2 ;
}
