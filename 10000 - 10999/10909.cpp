///** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define inf ( int )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
#define ll long long int
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, i, j , k, a, b, c, d, e,f, sz, q,mx,le,re,cases,pos;
string s, s2, s3, s4, s5, s6;
int ar [ mxs + mxs ] , tree [ 4 * (mxs + mxs) ];
bool marker [ mxs + mxs ];
vector < int > v;
vector < int >::iterator it;
void build ( int node , int le , int re );
int finder( int node , int le , int re , int val );
void query( int node , int le , int re , int val );
void checker( int node , int le , int re );
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(NULL);
    //cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    n = 2000000;
    build( 1 , 1 , n );
    for ( i = 2 ; i <= 136412; i++ )
    {
        v.clear();
        a = finder( 1 , 1 , n , i ) ;
        for ( j = a; j <= tree [ 1 ]; j += a )v.push_back( j );
        b = v.size();
        for ( j = 0 ; j < b; j++ )query( 1 , 1 , n , v [ j ] - j );
    }
    v.clear();
    checker( 1 , 1 , n );
    ///We have all the lucky numbers in the vector
    while( scanf("%d",&n) == 1 )
    {
        if( n&1 )printf("%d is not the sum of two luckies!\n",n);
        else
        {
            a = n / 2;
            it = lower_bound( v.begin() , v.end() , a  );
            if(*it > a )it--;
            while( 1 )
            {
                a = n - *it;
                if ( marker [ a ] )
                {
                    printf("%d is the sum of %d and %d.\n",n,*it,a);
                    break;
                }
                if ( it == v.begin() )
                {
                    printf("%d is not the sum of two luckies!\n",n);
                    break;
                }
                it--;
            }
        }
    }
}
void build ( int node , int le , int re )
{
    if ( le == re )
    {
        if ( le&1 )tree [ node ] = 1;
        else tree [ node ] = 0;
        return;
    }
    int mid = ( le + re )>>1;
    build( node + node , le , mid );
    build( node + node + 1 , mid + 1 , re );
    tree [ node ] = tree [ node + node ] + tree [ node + node + 1 ];
}
int finder( int node , int le , int re , int val )
{
    if ( le == re )return le;
    int mid = ( le + re )>>1;
    if ( tree [ node + node ] >= val )return ( finder( node + node , le , mid , val ) );
    return ( finder( node + node + 1 , mid + 1 , re , val - tree [ node + node ] ) );
}
void query( int node , int le , int re , int val )
{
    if ( le == re )
    {
        tree [ node ] = 0;
        return;
    }
    int mid = ( le + re )>>1;
    if ( tree [ node + node ] >= val )query( node + node , le , mid , val ) ;
    else query( node + node + 1 , mid + 1 , re , val - tree [ node + node ] );

    tree [ node ] = tree [ node + node ] + tree [ node + node + 1 ];
}
void checker( int node , int le , int re )
{
    if ( le == re )
    {
        if( tree [ node ] ){v.push_back( le ); marker [ le ] = 1;}
        return;
    }
    int mid = ( le + re )>>1;
    checker( node + node , le , mid );
    checker( node + node + 1 , mid + 1 , re );
}
