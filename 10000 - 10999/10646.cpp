#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(2e5+7)
#define ll long long int
int val , n , m , cases , t , a , b , c , i , j ;
deque < string > pile , hand;
string s;
void suffle();
string ans();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin>>t;
    while ( t-- )
    {
        pile.clear();
        hand.clear();
        for ( i = 1; i <= 27; i++ )
        {
            cin>>s;
            pile.push_back( s );
        }
        for ( i = 1; i <= 25; i++ )
        {
            cin>>s;
            hand.push_back( s );
        }
        val = 0;
        suffle();
        suffle();
        suffle();
        s = ans();
        cout<<"Case "<<++cases<<": "<<s<<"\n";
    }
    return 0;
}
void suffle()
{
    s = pile.back();
    pile.pop_back();
    if ( s [ 0 ] >= '2' && s [ 0 ] <= '9' )a = s [ 0 ] - '0';
    else a = 10;
    val += a;
    a = 10 - a;
    while ( a-- )pile.pop_back();
}
string ans()
{
    while( !hand.empty() )
    {
        pile.push_back( hand.front() );
        hand.pop_front();
    }
    return pile [ val - 1 ];
}

