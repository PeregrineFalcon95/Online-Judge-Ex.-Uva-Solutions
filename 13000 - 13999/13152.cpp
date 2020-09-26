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
int ans, t, n, m, i, j , k, a, b, c, d, e,f, sz, q,mx,le,re,cases;
string s, s2, s3, s4, s5, s6;
int ar [ mxs ] ;
int marker [ 100007 ];
void brainfuck();
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
    cin>>t;
    while( t-- )
    {
        memset( marker , 0 , sizeof marker );
        cin>>n;
        b = 0;
        for ( i = 1 ; i <= n; i++ )
        {
            cin>>a;
            if ( a > n )
            {
                b = 1;
            }
            if( !b )marker [ a ]++;
        }
        if ( b )
        {
            cout<<"Case "<<++cases<<": invalid\n";
            continue;
        }
        a = 0;
        s = "";
        for ( i = 1 ; i <= n; i++ )
        {
            if ( marker [ a + 1 ] )
            {
                a++;
                marker [ a ]--;
                s += "(";
            }
            else if ( marker [ a - 1 ] )
            {
                a--;
                marker [ a ]--;
                s += ")";
            }
            else
            {
                cout<<"Case "<<++cases<<": invalid\n";
                a = -2;
                break;
            }
        }
        if ( a == -2 )continue;
        if ( a )
        {
            cout<<"Case "<<++cases<<": invalid\n";
            continue;
        }
        for ( i = 0 ; i <= n; i++ )
        {
            if ( marker [ i ] )
            {
                cout<<"Case "<<++cases<<": invalid\n";
                a = -2;
                break;
            }
        }
        if ( a == -2 )continue;
        cout<<"Case "<<++cases<<": "<<s<<"\n";
    }
}


