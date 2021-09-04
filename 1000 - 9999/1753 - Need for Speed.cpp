#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define inf ( int )( 1e9 + 10 )
#define mxs (int)( 1e5 + 10 )
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie( NULL);
//#define md int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions 
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions 
int t, n, m, cases;
string s, s2, s3;
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
    double ti;
    while( cin>>n>>ti )
    {
        deque < pair < double , double > > dq;
        double x, y , hi = 10100000.0, lo = -10100000.0, mid;
        for ( int i = 0; i < n; i++ )
        {
            cin>>x>>y;
            dq.push_back( { x , y } );
        }
        int xx = 10000;
        while( xx-- )
        {
            mid = ( hi + lo )/2.0;
            double tot = 0.0;
            bool marker = false;
            for ( int i = 0; i < n; i++ )
            {
                if ( dq [ i ].second + mid <= 0.000000 )
                {
                    marker = true;
                    break;
                }
                tot += dq [ i ].first / ( dq [ i ].second + mid );
            }
            if ( marker == true )
            {
                lo = mid;
                continue;
            }
            if ( tot > ti )lo = mid;
            else hi = mid;
        }
        cout<<fixed<<setprecision(9)<<mid<<"\n";
    }
}