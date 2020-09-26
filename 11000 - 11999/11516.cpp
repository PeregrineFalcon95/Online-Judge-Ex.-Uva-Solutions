///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#define ll long long int
#define inf ( int )( 1e9 + 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod (int)(1e9)+7
//int dx[]={+1,0,+0,-1};///Four Directions
//int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2}; ///Knights Move
//int dy[]={1,-1,-2,-2,2,2,-1,1}; ///Knights Move
int t, n, m, j,a, b, c, d, e,f, i,ans,cases;
string s, s2, s3, s4;
vector < double > v;
void brainfuck();
bool checker( double x , int y );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>t;
    double mx , x , lo , hi , mid;
    while( t-- )
    {
        v.clear();
        cin>>n>>m;
        mx = 0.00;
        for ( i =1 ; i <= m; i++ )
        {
            cin>>x;
            mx = max( mx , x );
            v.push_back( x );
        }
        sort( v.begin() , v.end() );
        lo = 0.00 , hi = mx;
        e = 0;
        double lol = 9999999999.00;
        while( e++ <= 100 )
        {
            mid = ( lo + hi ) / 2.00;
            if ( checker( mid , n ) )
            {
                lol = min( lol , mid );
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }
        cout<<fixed<<setprecision(1)<<lol<<"\n";
    }
}
bool checker( double x , int y )
{
    double pos = -1.00;
    for ( i = 0 ; i < m; i++ )
    {
        if ( pos == -1.00 )
        {
            if ( !y )return 0;
            y--;
            pos = v [ i ] + x;
            pos = v [ i ] + x;
        }
        else
        {
            if ( v [ i ] - pos <= x )continue;
            else
            {
                if ( !y )return 0;
                y--;
                pos = v [ i ] + x;
            }
        }
    }
    return 1;
}
