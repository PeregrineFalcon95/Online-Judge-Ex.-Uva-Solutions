#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define inf ( int )( 1e9 + 10 )
#define mxs (int)( 1e5 + 10 )
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie( NULL);
//#define md int mid = ( l + r )>>1;
int dx[]={+1,-1,+0,+0};///Four Directions
int dy[]={+0,+0,+1,-1};///Four directions
// int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions 
// int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions 
int t, n, m, cases;
string s, s2, s3;
int matrix [ 30 ] [ 30 ];
void brainfuck();
int main()
{
    fast
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck() 
{
    while( cin>>n>>m )
    {
        memset( matrix, 0 , sizeof matrix );
        while( n-- )
        {
            cin>>s>>s2;
            matrix [ s [ 0 ] - 'a' ] [ s2 [ 0 ] - 'a' ] = 1;
        }

        for ( int i = 0; i < 26; i++ )
            for ( int j = 0; j < 26; j++ )
                for ( int k = 0; k < 26; k++ )
                    matrix [ j ] [ k ] = matrix [ j ] [ k ] || ( matrix [ j ] [ i ] && matrix [ i ] [ k ] );
        int a , marker;
        while( m-- )
        {
            cin>>s>>s2;
            if ( s.size() != s2.size() )cout<<"no\n";
            else 
            {
                marker = 0;
                a = s.size();
                for ( int i = 0; i < a; i++ )
                {
                    if ( s [ i ] == s2 [ i ] )continue;
                    if ( !matrix [ s [ i ] - 'a' ] [ s2 [ i ] - 'a' ] )marker = 1;
                }
                if ( marker )cout<<"no\n";
                else cout<<"yes\n";
            }
        }
    }
}
