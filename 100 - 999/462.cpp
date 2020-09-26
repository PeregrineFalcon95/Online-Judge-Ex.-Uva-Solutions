#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e4+7)
#define ll long long int
int n , m , t , a , b , c , d , ss , h , ans , cases , e , sum , ms , md , mc , mh;
//ll ar [ mxs ] ;
string s , s2;
vector < string > v;
int game();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 0;
    //cin.ignore();
    while ( getline(cin,s) )
    {
        //cin.ignore();
        v.clear();
        ss = h = d = c = sum = 0;
        stringstream su ( s );
        //cout<<endl;
        while ( su >> s2 )
        {
            v.push_back( s2 );
            //cout<<s2<<endl;
            ///Counting Number of cards in each suit
            if ( s2 [ 1 ] == 'S' )ss++;
            else if ( s2 [ 1 ] == 'H' )h++;
            else if ( s2 [ 1 ] == 'D' )d++;
            else if ( s2 [ 1 ] == 'C' )c++;

            ///Counting Sum
            if ( s2 [ 0 ] == 'K' )sum += 3;
            else if ( s2 [ 0 ] == 'A' )sum += 4;
            else if ( s2 [ 0 ] == 'Q' )sum += 2;
            else if ( s2 [ 0 ] == 'J' )sum += 1;
        }
        e = game();
        if ( e == 1 )cout<<"BID NO-TRUMP\n";
        else if ( e == 2 )
        {
            cout<<"BID ";
            if ( ss >= d && ss >= h && ss >= c )cout<<"S\n";
            else if ( h > ss && h >= d && h >= c )cout<<"H\n";
            else if ( d > ss && d > h && d >= c )cout<<"D\n";
            else cout<<"C\n";
        }
        else cout<<"PASS\n";
    }
    return 0;
}
int game()
{
    //cout<<sum<<endl;
    ms = md = mc = mh = 0;
    for ( int i = 0; i != 13; i++ )
    {
        if ( v [ i ] == "KS" && ss == 1 )sum -= 1;
        else if ( v [ i ] == "KH" && h == 1 )sum -= 1;
        else if ( v [ i ] == "KD" && d == 1 )sum -= 1;
        else if ( v [ i ] == "KC" && c == 1 )sum -= 1;
        else if ( v [ i ] == "QS" && ( ss == 1 || ss == 2 ) )sum -= 1;
        else if ( v [ i ] == "QH" && ( h == 1 || h == 2 ) )sum -= 1;
        else if ( v [ i ] == "QD" && ( d == 1 || d == 2 ) )sum -= 1;
        else if ( v [ i ] == "QC" && ( c == 1 || c == 2 ) )sum -= 1;
        else if ( v [ i ] == "JS" && ( ss == 1 || ss == 2 || ss == 3 ) )sum -= 1;
        else if ( v [ i ] == "JH" && ( h == 1 || h == 2 || h == 3 ) )sum -= 1;
        else if ( v [ i ] == "JD" && ( d == 1 || d == 2 || d == 3 ) )sum -= 1;
        else if ( v [ i ] == "JC" && ( c == 1 || c == 2 || c == 3 ) )sum -= 1;
        else if ( v [ i ] == "AC" )mc = 1;
        else if ( v [ i ] == "AS" )ms = 1;
        else if ( v [ i ] == "AD" )md = 1;
        else if ( v [ i ] == "AH" )mh = 1;

        if ( v [ i ] [ 0 ] == 'K' )
        {
            if ( v [ i ] [ 1 ] == 'S' && ss >= 2 )ms = 1;
            else if ( v [ i ] [ 1 ] == 'H' && h >= 2 )mh = 1;
            else if ( v [ i ] [ 1 ] == 'D' && d >= 2 )md = 1;
            else if ( v [ i ] [ 1 ] == 'C' && c >= 2 )mc = 1;
        }
        else if ( v [ i ] [ 0 ] == 'Q' )
        {
            if ( v [ i ] [ 1 ] == 'S' && ss >= 3 )ms = 1;
            else if ( v [ i ] [ 1 ] == 'H' && h >= 3 )mh = 1;
            else if ( v [ i ] [ 1 ] == 'D' && d >= 3 )md = 1;
            else if ( v [ i ] [ 1 ] == 'C' && c >= 3 )mc = 1;
        }
    }
    if ( sum >= 16 && md && mc && mh && ms )return 1;

    //cout<<"\n"<<sum<<endl;

    if ( ss == 2 )sum++;
    else if ( ss == 1 || !ss )sum += 2;

    if ( d == 2 )sum++;
    else if ( d == 1 || !d )sum += 2;

    if ( c == 2 )sum++;
    else if ( c == 1 || !c )sum += 2;

    if ( h == 2 )sum++;
    else if ( h == 1 || !h )sum += 2;

    //cout<<"\n  xxx "<<sum<<" xxx \n";
    if ( sum < 14 )return 4;
    return 2;
}
//KS QS TH 8H 4H AC QC TC 5C KD QD JD 8D
//AC 3C 4C AS 7S 4S AD TD 7D 5D AH 7H 5H
