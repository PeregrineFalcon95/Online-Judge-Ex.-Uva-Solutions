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
ll ans, t, n, m, i, j , k, a, b, c, d, e,f, sz, q,mx,le,re,cases;
string s, s2, s3, s4, s5, s6;
ll ar  [ mxs ] , ar2 [ mxs ];
deque < ll > dq , dq2;
void brainfuck();
ll hexa();
ll octal();
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
    while( cin>>s>>q && q )
    {
        if ( s.size() > 2 && s [ 0 ] == '0' && s [ 1 ] == 'x' )n = hexa();
        else if ( s [ 0 ] == '0' )n = octal();
        else
        {
            ///Decimal
            n = 0;
            for ( i = 0; i < s.size(); i++ )
            {
                n *= 10;
                n += s [ i ] - '0';
            }
        }
        //cout<<n<<endl;
        ans = 0;
        while( q-- )
        {
            cin>>s>>a;
            if ( s [ 0 ] == '-' )
            {
                b = n - 1;
                if ( b == a )ans++;
                n = a;
            }
            else if ( s [ s.size() - 1 ] == '-' )
            {
                if ( a == n )ans++;
                n = a - 1;
            }
            else if ( s [ 0 ] == '+' )
            {
                b = n + 1;
                if (  b == a )ans++;
                n = a;
            }
            else if ( s [ s.size() - 1 ] == '+' )
            {
                b = n;
                if ( b == a )ans++;
                n = a + 1;
            }
            else
            {
                ///Only i
                if ( n == a )ans++;
                n = a;
            }
        }
        cout<<ans<<"\n";
    }
}
ll hexa()
{
    a = 1;
    n = 0;
    for ( i = s.size() - 1; i >= 2; i-- )
    {
        if ( s [ i ] >= '0' && s [ i ] <= '9' )
        {
            n += ( s [ i ] - 48 ) * a;
            a *= 16;
        }
        else
        {
            n += ( s [ i ] - 55 ) * a;
            a *= 16;
        }
    }
    return n;
}
ll octal()
{
    a = 1;
    n = 0;
    for ( i = s.size() - 1; i > 0; i-- )
    {
        n += ( s [ i ] - 48 ) * a;
        a *= 8;
    }
    return n;
}
