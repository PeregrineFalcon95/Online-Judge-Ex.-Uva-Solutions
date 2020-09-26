#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
#pragma comment(linker, "/stack:200000000")
#define mod 1000000007
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int ans, t, n, m, i, j, k, a, b, c, d, e, f, g , from , to;
string s , s2, s3, s4;
deque < string > black , white;
map < string , int > mp;
map < string , deque < int > > mpp;
map < string , deque < int > >::iterator it;
deque < int > work;
int ar [ mxs ] ;
void brainfuck();
int compare();
void clear_();
deque < int > Straight_flush( deque < string > v );
deque < int > Four_of_a_kind( deque < string > v );
deque < int > Full_House( deque < string > v );
deque < int > Flush( deque < string > v );
deque < int > Straight( deque < string > v );
deque < int > Three_of_a_Kind( deque < string > v );
deque < int > Two_Pairs( deque < string > v );
deque < int > Pair ( deque < string > v );
deque < int > High_Card ( deque < string > v );
void value_set( deque < string > v );
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
    mp[ "2" ] = 1;
    mp [ "3" ] = 2;
    mp [ "4" ] = 3;
    mp [ "5" ] = 4;
    mp [ "6" ] = 5;
    mp [ "7" ] = 6;
    mp [ "8" ] = 7;
    mp [ "9" ] = 8;
    mp [ "T" ] = 9;
    mp [ "J" ] = 10;
    mp [ "Q" ] = 11;
    mp [ "K" ] = 12;
    mp [ "A" ] = 13;

    mpp [ "C" ] = work;
    mpp [ "D" ] = work;
    mpp [ "H" ] = work;
    mpp [ "S" ] = work;

    while( cin>>s )
    {
        black.clear();
        white.clear();
        black.push_back( s );
        for ( i = 0 ; i < 4; i++ )
        {
            cin>>s;
            black.push_back( s );
        }
        for ( i = 0 ; i < 5; i++ )
        {
            cin>>s;
            white.push_back( s );
        }
        a = compare();
        if ( !a )cout<<"Tie.\n";
        else if ( a == 1 )cout<<"Black wins.\n";
        else cout<<"White wins.\n";
    }
}
int compare()
{
    deque < int > bb, ww;
    bb = Straight_flush ( black );
    ww = Straight_flush ( white );
    if ( bb [ 0 ] == 1 )
    {
        if ( ww [ 0 ] == 0 )return 1;
        else if ( ww [ 1 ] > bb [ 1 ] )return 2;
        else if ( ww [ 1 ] < bb [ 1 ] )return 1;
    }
    if ( ww [ 0 ] == 1 )
    {
        if ( bb [ 0 ] == 0 )return 2;
        else if ( ww [ 1 ] > bb [ 1 ] )return 2;
        else if ( ww [ 1 ] < bb [ 1 ] )return 1;
    }
    bb = Four_of_a_kind( black );
    ww = Four_of_a_kind( white );
    if ( bb [ 0 ] == 1 )
    {
        if ( ww [ 0 ] == 0 )return 1;
        else if ( ww [ 1 ] > bb [ 1 ] )return 2;
        else if ( ww [ 1 ] < bb [ 1 ] )return 1;
    }
    if ( ww [ 0 ] == 1 )
    {
        if ( bb [ 0 ] == 0 )return 2;
        else if ( ww [ 1 ] > bb [ 1 ] )return 2;
        else if ( ww [ 1 ] < bb [ 1 ] )return 1;
    }
    bb = Full_House ( black );
    ww = Full_House ( white );
    if ( bb [ 0 ] == 1 )
    {
        if ( ww [ 0 ] == 0 )return 1;
        else if ( ww [ 1 ] > bb [ 1 ] )return 2;
        else if ( ww [ 1 ] < bb [ 1 ] )return 1;
    }
    if ( ww [ 0 ] == 1 )
    {
        if ( bb [ 0 ] == 0 )return 2;
        else if ( ww [ 1 ] > bb [ 1 ] )return 2;
        else if ( ww [ 1 ] < bb [ 1 ] )return 1;
    }
    bb = Flush ( black );
    ww = Flush ( white );
    if ( bb [ 0 ] && !ww [ 0 ] )return 1;
    if ( !bb [ 0 ] && ww [ 0 ] )return 2;
    if ( bb [ 0 ] && ww [ 0 ] )
    {
        while( bb.size() != 1 )
        {
            a = bb.back();
            bb.pop_back();
            b = ww.back();
            ww.pop_back();
            if ( a > b )return 1;
            if ( b > a )return 2;
        }
    }
    bb = Straight ( black );
    ww = Straight ( white );
    if ( bb [ 0 ] && !ww [ 0 ] )return 1;
    if ( !bb [ 0 ] && ww [ 0 ] )return 2;
    if ( bb [ 0 ] && ww [ 0 ] )
    {
        if ( bb [ 1 ] > ww [ 1 ] )return 1;
        if ( bb [ 1 ] < ww [ 1 ] )return 2;
    }
    bb = Three_of_a_Kind( black );
    ww = Three_of_a_Kind( white );
    if ( bb [ 0 ] && !ww [ 0 ] )return 1;
    if ( !bb [ 0 ] && ww [ 0 ] )return 2;
    if ( bb [ 0 ] && ww [ 0 ] )
    {
        if ( bb [ 1 ] > ww [ 1 ] )return 1;
        if ( ww [ 1 ] > bb [ 1 ] )return 2;
    }
    bb = Two_Pairs( black );
    ww = Two_Pairs( white );
    if ( bb [ 0 ] && !ww [ 0 ] )return 1;
    if ( !bb [ 0 ] && ww [ 0 ] )return 2;
    if ( bb [ 0 ] && ww [ 0 ] )
    {
        if ( bb [ 1 ] > ww [ 1 ] )return 1;
        if ( bb [ 1 ] < ww [ 1 ] )return 2;
        if ( bb [ 2 ] > ww [ 2 ] )return 1;
        if ( bb [ 2 ] < ww [ 2 ] )return 2;
        if ( bb [ 3 ] > ww [ 3 ] )return 1;
        if ( bb [ 3 ] < ww [ 3 ] )return 2;
    }
    bb = Pair( black );
    ww = Pair( white );
    if ( bb [ 0 ] && !ww [ 0 ] )return 1;
    if ( !bb [ 0 ] && ww [ 0 ] )return 2;
    if ( bb [ 0 ] && ww [ 0 ] )
    {
        for ( i = 5 ; i > 1 ; i-- )
        {
            if ( bb [ i ] == bb [ i - 1 ] )
            {
                a = bb [ i ];
                break;
            }
        }
        for ( i = 5 ; i > 1 ; i-- )
        {
            if ( ww [ i ] == ww [ i - 1 ] )
            {
                b = ww [ i ];
                break;
            }
        }
        if ( a > b )return 1;
        if ( a < b )return 2;
        for ( i = 5; i >= 1; i-- )
        {
            if ( bb [ i ] > ww [ i ] )return 1;
            if ( bb [ i ] < ww [ i ] )return 2;
        }
    }
    bb = High_Card( black );
    ww = High_Card( white );
    sort( bb.begin() , bb.end() );
    sort( ww.begin() , ww.end() );
    for ( i = 4 ; i >= 0; i-- )
    {
        if ( bb [ i ] > ww [ i ] )return 1;
        if ( bb [ i ] < ww [ i ] )return 2;
    }
    return 0;
}
deque < int > Straight_flush( deque < string > v )
{
    ///5 cards of the same suit with consecutive values. Ranked by the highest card in the hand.
    value_set( v );
    for ( it = mpp.begin(); it != mpp.end(); it++ )
    {
        if ( it->second.size() == 5 )
        {
            a = it->second [ 0 ];
            b = it->second [ 4 ];
            if ( b - a == 4 )
            {
                work.push_back( 1 );
                work.push_back( b );
                return work;
            }
        }
    }
    work.push_back( 0 );
    return work;
}
deque < int > Four_of_a_kind( deque < string > v )
{
    ///4 cards with the same value. Ranked by the value of the 4 cards.
    value_set( v );
    for ( i = 1 ; i <= 13 ; i++ )
    {
        b = 0;
        for ( it = mpp.begin(); it != mpp.end(); it++ )
        {
            a = it->second.size();
            for ( j = 0 ; j < a; j++ )
                if ( it->second [ j ] == i )b++;
        }
        if ( b == 4 )
        {
            work.push_back( 1 );
            work.push_back( i );
            return work;
        }
    }
    work.push_back( 0 );
    return work;
}
deque < int > Full_House( deque < string > v )
{
    ///3 cards of the same value, with the remaining 2 cards forming a pair. Ranked by the value of the 3 cards.
    value_set( v );
    for ( i = 1 ; i <= 13 ; i++ )
    {
        b = 0;
        for ( it = mpp.begin(); it != mpp.end(); it++ )
        {
            a = it->second.size();
            for ( j = 0 ; j < a; j++ )
                if ( it->second [ j ] == i )b++;
        }
        if ( b == 3 )
        {
            for ( j = 1 ; j <= 13; j++ )
            {
                if ( i == j )continue;
                b = 0;
                for ( it = mpp.begin(); it != mpp.end(); it++ )
                {
                    a = it->second.size();
                    for ( k = 0 ; k < a; k++ )
                        if ( it->second [ k ] == j )b++;
                }
                if ( b == 2 )
                {
                    work.push_back( 1 );
                    work.push_back( i );
                    return work;
                }
            }
        }
    }
    work.push_back( 0 );
    return work;
}
deque < int > Flush( deque < string > v )
{
    ///Hand contains 5 cards of the same suit. Hands which are both flushes are ranked using the rules for High Card.
    value_set( v );
    for ( it = mpp.begin(); it != mpp.end(); it++ )
    {
        if ( it->second.size() == 5 )
        {
            work.push_back( 1 );
            for ( i = 0 ; i < 5; i++ )
            {
                work.push_back( it->second [ i ] );
            }
            return work;
        }
    }
    work.push_back( 0 );
    return work;
}
deque < int > Straight( deque < string > v )
{
    ///Hand contains 5 cards with consecutive values.
    ///Hands which both contain a straight are ranked by their highest card.
    value_set( v );
    for ( it = mpp.begin(); it != mpp.end(); it++ )
    {
        a = it->second.size();
        for ( i = 0 ; i < a; i++ )
        {
            work.push_back( it->second [ i ] );
        }
    }
    sort( work.begin() , work.end() );
    for ( i = 1 ; i < 5; i++ )
    {
        if ( work [ i ] - work [ i - 1 ] != 1 )
        {
            work.clear();
            work.push_back( 0 );
            return work;
        }
    }
    a = work.back();
    work.clear();
    work.push_back( 1 );
    work.push_back( a );
    return work;
}
deque < int > Three_of_a_Kind( deque < string > v )
{
    ///Three of the cards in the hand have the same value.
    ///Hands which both contain three of a kind are ranked by the value of the 3 cards.
    value_set( v );
    for ( i = 1; i <= 13; i++ )
    {
        b = 0;
        for ( it = mpp.begin(); it != mpp.end(); it++ )
        {
            a = it->second.size();
            for ( j = 0 ; j < a; j++ )
            {
                if ( it->second [ j ] == i )b++;
            }
        }
        if ( b == 3 )
        {
            work.push_back( 1 );
            work.push_back( i );
            return work;
        }
    }
    work.push_back( 0 );
    return work;
}
deque < int > Two_Pairs( deque < string > v )
{
    ///The hand contains 2 different pairs. Hands which both contain 2 pairs are ranked by the
    ///value of their highest pair. Hands with the same highest pair are ranked by the value of their
    ///other pair. If these values are the same the hands are ranked by the value of the remaining card.
    value_set( v );
    for ( it = mpp.begin(); it != mpp.end(); it++ )
    {
        a = it->second.size();
        for ( i= 0 ; i < a; i++ )
        {
            work.push_back( it->second [ i ] );
        }
    }
    sort( work.begin() , work.end() );
    if ( work [ 0 ] == work [ 1 ] && work [ 2 ] == work [ 3 ] )
    {
        a = work [ 0 ];
        b = work  [ 2 ];
        c = work [ 4 ];
        work.clear();
        work.push_back( 1 );
        work.push_back( max( a , b ) );
        work.push_back( min( a , b ) );
        work.push_back( c );
        return work;
    }
    if ( work [ 1 ] == work [ 2 ] && work [ 3 ] == work [ 4 ] )
    {
        a = work [ 1 ];
        b = work [ 3 ];
        c = work [ 0 ];
        work.clear();
        work.push_back( 1 );
        work.push_back( max( a , b ) );
        work.push_back( min( a , b ) );
        work.push_back( c );
        return work;
    }
    work.clear();
    work.push_back( 0 );
    return work;
}
deque < int > Pair ( deque < string > v )
{
    ///2 of the 5 cards in the hand have the same value. Hands which both contain a pair are ranked
    ///by the value of the cards forming the pair. If these values are the same, the hands are ranked by
    ///the values of the cards not forming the pair, in decreasing order.
    value_set( v );
    for ( it = mpp.begin(); it != mpp.end(); it++ )
    {
        a = it->second.size();
        for ( j = 0 ; j < a; j++ )
        {
            work.push_back( it->second [ j ] );
        }
    }
    sort( work.begin() , work.end() );
    for ( i = 4; i > 0 ; i-- )
    {
        if ( work [ i ] == work [ i-  1 ] )
        {
            work.push_front( 1 );
            return work;
        }
    }
    work.clear();
    work.push_back( 0 );
    return work;
}
deque < int > High_Card ( deque < string > v )
{
    ///Hands which do not fit any higher category are ranked by the value of their highest card.
    ///If the highest cards have the same value, the hands are ranked by the next highest, and so on.
    value_set( v );
    for ( it = mpp.begin(); it != mpp.end(); it++ )
    {
        a = it->second.size();
        for ( j = 0 ; j < a; j++ )
        {
            work.push_back( it->second [ j ] );
        }
    }
    return work;
}
void clear_()
{
    mpp [ "C" ].clear();
    mpp [ "D" ].clear();
    mpp [ "H" ].clear();
    mpp [ "S" ].clear();
}
void value_set( deque < string > v )
{
    work.clear();
    clear_();
    for ( i = 0 ; i < 5; i++ )
    {
        s2 = v [ i ] [ 0 ];
        s = v [ i ] [ 1 ];
        a = mp [ s2 ];
        mpp [ s ].push_back( a );
    }
    for ( it = mpp.begin(); it != mpp.end(); it++ )
        sort( it->second.begin() , it->second.end() );
}
