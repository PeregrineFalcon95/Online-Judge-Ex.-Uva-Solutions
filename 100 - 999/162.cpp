#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e4+7)
#define ll long long int
int n , m , t , a , b , c , d , ans , cases , e;
//ll ar [ mxs ] ;
string s , s2;
deque < string > de , no , temp;
int game();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    n = 0;
    while ( cin>>s && s != "#" )
    {
        n++;
        if ( n&1 )no.push_back( s );
        else de.push_back( s );
        if ( n == 52 )
        {
            ///Strat game;
            e = game();
            printf("%d",e);
            if(e == 1 )printf("%3d\n",de.size() );
            else printf("%3d\n",no.size());
            de.clear();
            no.clear();
            temp.clear();
            n = 0;
        }
    }
    return 0;
}
int game()
{
    ///Dealer == 1
    ///Non-Dealer == 2
    a = 0;
    b = 0;
    while ( 1 )
    {
        if ( !a )
        {
            ///Non-Dealers turn
            if ( no.empty() )return 1;
            a = 1;
            if ( b )
            {
                c = 0;
                while ( b-- )
                {
                    if ( no.empty() )return 1;
                    s = no.back();
                    no.pop_back();
                    temp.push_back( s );
                    if ( s [ 1 ] == 'K' )
                    {
                        b = 3;
                        c = 1;
                        break;
                    }
                    else if ( s [ 1 ] == 'Q' )
                    {
                        b = 2;
                        c = 1;
                        break;
                    }
                    else if ( s [ 1 ] == 'J' )
                    {
                        b = 1;
                        c = 1;
                        break;
                    }
                    else if ( s [ 1 ] == 'A' )
                    {
                        b = 4;
                        c = 1;
                        break;
                    }
                }
                if ( !c )
                {
                    while( !temp.empty() )
                    {
                        de.push_front( temp.front() );
                        temp.pop_front();
                    }
                    b = 0;
                }
            }
            else
            {
                s = no.back();
                no.pop_back();
                temp.push_back( s );
                if ( s [ 1 ] == 'K' )b = 3;
                else if ( s [ 1 ] == 'Q' )b = 2;
                else if ( s [ 1 ] == 'J' )b = 1;
                else if ( s [ 1 ] == 'A' )b = 4;
                else b = 0;
            }
        }
        else
        {
            ///Dealers turn
            if ( de.empty() )return 2;
            a = 0;
            if ( b )
            {
                c = 0;
                while ( b-- )
                {
                    if ( de.empty() )return 2;
                    s = de.back();
                    de.pop_back();
                    temp.push_back( s );
                    if ( s [ 1 ] == 'K' )
                    {
                        b = 3;
                        c = 1;
                        break;
                    }
                    else if ( s [ 1 ] == 'Q' )
                    {
                        b = 2;
                        c = 1;
                        break;
                    }
                    else if ( s [ 1 ] == 'J' )
                    {
                        b = 1;
                        c = 1;
                        break;
                    }
                    else if ( s [ 1 ] == 'A' )
                    {
                        b = 4;
                        c = 1;
                        break;
                    }
                }
                if ( !c )
                {
                    while( !temp.empty() )
                    {
                        no.push_front( temp.front() );
                        temp.pop_front();
                    }
                    b = 0;
                }
            }
            else
            {
                s = de.back();
                de.pop_back();
                temp.push_back( s );
                if ( s [ 1 ] == 'K' )b = 3;
                else if ( s [ 1 ] == 'Q' )b = 2;
                else if ( s [ 1 ] == 'J' )b = 1;
                else if ( s [ 1 ] == 'A' )b = 4;
                else b = 0;
            }
        }
    }
}
