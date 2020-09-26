///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#define ll long long int
#define inf ( int )( 1e9 + 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod (ll)(1e9)+7
//int dx[]={+1,0,+0,-1};///Four Directions
//int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, j, ans, k,a, b, c, d, e,f ,sum , i,sz,cases,mx , source , target;
string s, s2, s3, s4;
bool visited [ 75 ];
int parent [ 2 ] [ 75 ] , cost [ 75 ] [ 75 ] , rev_cost [ 75 ] [ 75 ] , mi [ 75 ];
vector < string > v;
vector < int > name [ 100 ];
map < string , int > mp;
map < int , string > mp2;
queue < pair < int , int > > qu;
vector < int > graph [ 75 ] , rev [ 75 ];
int ar [ mxs ] , ar2 [ mxs ] , ar3 [ mxs ] ;
void brainfuck();
void clear_();
void max_flow();
bool augmenting_path();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    source = 0;
    target = 70;
    cin>>t;
    while( t-- )
    {
        clear_();
        cin>>n;
        f = 0;
        for ( i = 1 ; i <= n; i++ )
        {
            cin>>a;
            for ( j = 0 ; j < a; j++ )
            {
                cin>>s;
                if ( s [ 0 ] >= 'a' && s [ 0 ] <= 'z' )s [ 0 ] -= 32;
                for ( k = 1; k < s.size(); k++ )
                    if ( s [ k ] >= 'A' && s [ k ] <= 'Z' )s [ k ] += 32;
                mp [ s ] = ++f;
                mp2 [ f ] = s;
                name [ i ].push_back( f );
                b = s [ 0 ] - 'A' + n + 1;
                graph [ i ].push_back( b );
                rev [ b ].push_back( i );
                cost [ i ] [ b ] = 1;
            }
        }
        b = n + 1;
        for ( i = b; i <= b + 25; i++ )
        {
            graph [ i ].push_back( target );
            rev [ target ].push_back( i );
            cost [ i ] [ target ] = 1;
        }
        for ( i = 1 ; i <= n; i++ )
        {
            graph [ 0 ].push_back( i );
            rev [ i ].push_back( 0 );
            cost [ 0 ] [ i ] = 1;
        }
        max_flow();
        cout<<"Case #"<<++cases<<":\n";
        for ( i = 0 ; i < n; i++ )cout<<v [ i ]<<"\n";
    }
}
void clear_()
{
    v.clear();
    mp.clear();
    mp2.clear();
    memset( cost , 0 , sizeof cost );
    memset( rev_cost , 0 , sizeof rev_cost );
    for ( i = 0 ; i <= 72; i++ )
    {
        name [ i ].clear();
        graph [ i ].clear();
        rev [ i ].clear();
    }
}
void max_flow()
{
    while( augmenting_path() )
    {
        c = mi [ target ];
        for ( i = target ; ; i = parent [ 1 ] [ i ] )
        {
            a = parent [ 1 ] [ i ];
            if ( parent [ 0 ] [ i ] == 1 )
            {
                cost [ a ] [ i ] -= c;
                rev_cost [ i ] [ a ] += c;
            }
            else
            {
                rev_cost [ a ] [ i ] -= c;
                cost [ i ] [ a ] += c;
            }
            if ( parent [ 1 ] [ i ] == source )break;
        }
    }
    b = n + 1;
    for ( i = b; i <= b + n - 1; i++ )
    {
        for ( j = 1 ; j <= n; j++ )
        {
            if ( rev_cost [ i ] [ j ] )
            {
                sz = name [ j ].size();
                for ( k = 0; k < sz; k++ )
                {
                    s2 = mp2 [ name [ j ] [ k ] ];
                    if ( s2 [ 0 ] == 'A' + i - n - 1 )
                    {
                        //cout<<j<<"   "<<s2<<endl;
                        v.push_back( s2 );
                        break;
                    }
                }
                break;
            }
        }
    }
}
bool augmenting_path()
{
    while( !qu.empty() )qu.pop();
    memset( visited , 0 , sizeof visited );
    qu.push( { source , inf } );
    visited [ source ] = 1;
    while( !qu.empty() )
    {
        a = qu.front().first;
        c = qu.front().second;
        qu.pop();
        sz = graph [ a ].size();
        for ( i = 0 ; i < sz; i++ )
        {
            b = graph [ a ] [ i ];
            if ( !visited [ b ] && cost [ a ] [ b ] )
            {
                qu.push( { b , min( c , cost [ a ] [ b ] ) } );
                visited [ b ] = 1;
                mi [ b ] = min( c , cost [ a ] [ b ] );
                parent [ 0 ] [ b ] = 1;
                parent [ 1 ] [ b ] = a;
                if ( b == target )return 1;
            }
        }
        sz = rev [ a ].size();
        for ( i = 0 ; i < sz; i++ )
        {
            b = rev [ a ] [ i ];
            if ( !visited [ b ] && rev_cost [ a ] [ b ] )
            {
                qu.push( { b , min( c , rev_cost [ a ] [ b ] ) } );
                visited [ b ] = 1;
                mi [ b ] = min( c , rev_cost [ a ] [ b ] );
                parent [ 0 ] [ b ] = 2;
                parent [ 1 ] [ b ] = a;
                if ( b == target )return 1;
            }
        }
    }
    return 0;
}
