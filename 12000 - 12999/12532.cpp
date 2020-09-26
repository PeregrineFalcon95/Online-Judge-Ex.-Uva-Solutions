#include<bits/stdc++.h>
using namespace std;
#define mx 100010
#define ll long long int
ll tree [ mx * 4 ], ar [ mx ];
ll n,q,t,p,x,y,z,ans;
char ch;
void make_tree( ll node, ll a, ll b );
void update( ll node, ll a, ll b );
ll query( ll node, ll a, ll b );
void fastscan(ll &number)
{
    bool negative = false;
    register ll c;

    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
int main()
{
    while( scanf("%lld%lld",&n,&q) == 2 )
    {
        getchar();
        memset(tree, 0, sizeof tree );
        for ( int i = 1; i <= n; i++ )
        {
            //scanf("%lld",&ar [ i ] );
            fastscan( ar [ i ] );
            if ( ar [ i ] > 0 )ar [ i ] = 1;
            else if ( ar [ i ] < 0 )ar [ i ] = -1;
        }
        //getchar();
        make_tree(1,1, n );
        for ( int i = 0; i != q; i++ )
        {
            //getchar();
            ch = getchar();
            getchar();
            //scanf(" %c %lld %lld",&ch,&x,&y);
            fastscan(x);
            fastscan(y);
            if ( ch == 'P' )
            {
                ans = query( 1, 1, n );
                if ( ans > 0 )putchar('+');
                else if ( ans < 0 )putchar('-');
                else putchar('0');
            }
            else if ( ch == 'C' )
            {
                if ( y > 0 ) y = 1;
                else if ( y < 0 ) y = -1;
                update( 1, 1, n );
            }
        }
        putchar(10);
    }
    return 0;
}
void make_tree( ll node, ll a, ll b )
{
    if ( a == b )
    {
        tree [ node ] = ar [ a ];
        return;
    }
    ll right = ( node * 2 ) + 1;
    ll left = node * 2;
    ll mid = ( a + b ) / 2;
    make_tree( left, a, mid );
    make_tree( right, mid + 1, b );
    tree [ node ] = tree [ left ] * tree [ right ];
}
void update( ll node, ll a, ll b )
{
    if ( a > x || x > b )return;
    if ( a == b )
    {
        tree [ node ] = y;
        return;
    }
    ll left = node * 2;
    ll right = ( node * 2 ) + 1;
    ll mid = ( a + b ) / 2;
    update( left, a, mid );
    update( right, mid + 1, b );
    tree [ node ] = tree [ left ] * tree [ right ];
}
ll query( ll node, ll a, ll b )
{
    if ( a >= x && b <= y )return tree [ node ];
    ll left = node * 2;
    ll right = ( node * 2 ) + 1;
    ll mid = ( a + b ) / 2;
    ll q1,q2 ;
    if ( a > y || mid < x )q1 = 1;
    else q1 = query( left, a, mid );
    if ( mid + 1 > y || b < x )q2 = 1;
    else q2 = query( right, mid + 1, b );
    return q1 * q2;
}
