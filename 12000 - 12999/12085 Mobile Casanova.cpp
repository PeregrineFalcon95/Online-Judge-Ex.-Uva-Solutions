#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

#define inf ( int )( 1e9 + 10 )
#define mxs (int)( 2e5 + 10 )
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie( NULL);
//#define md int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions 
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions 
ll t, n, m, cases;
string s, s2;
vector < string > v;
string ar [ mxs ];
void brainfuck();
int main()
{
    //fast
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
    while( cin>>n && n)
    {
        for ( int i = 0; i <= n; i++ )ar [ i ] = "";
        v.clear();
        int lastNum = -1;
        for ( int i = 1; i <= n; i++ )
        {
            cin>>s;
            int a = stoi(s);
            if ( a - lastNum == 1 )
            {
                m = s.size();
                ar [ v.size() - 1 ] = "";
                for ( int j = 0; j < m; j++ )
                {
                    if ( s [ j ] != v [ v.size() - 1 ] [ j ] )
                    {
                        while( j < m )ar [ v.size() - 1 ] += s [ j++ ];
                        break;
                    }
                }
                lastNum = a;
            }
            else 
            {
                v.push_back( s );
                lastNum = stoi(s);
            }
        }
        n = v.size();
        cout<<"Case "<<++cases<<":\n";

        for ( int i = 0; i < n; i++ )
        {
            cout<<v [ i ];
            if ( ar [ i ].size() != 0 )cout<<"-"<<ar [ i ];
            cout<<"\n";
        }
        cout<<"\n";
    }
}
