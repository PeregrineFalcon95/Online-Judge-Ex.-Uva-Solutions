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
map < ll , ll > mp;
set < set < ll > > st;
set < ll > nodes;
void build( ll node, ll val )
{
    if ( mp.find(node) == mp.end() )
    {
        nodes.insert(node);
        mp [ node ] = val;
    }
    else if ( mp [ node ] > val )
    {
        build( node * 2 + 1, val );
    }
    else
    {
        build( node * 2 , val);
    }
}
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
        st.clear();
        for ( int i = 1 ; i <= n; i++ )
        {
            mp.clear();
            nodes.clear();
            for ( int j = 0; j < m; j++ )
            {
                ll a;
                cin>>a;
                build( 1 , a );
            }
            st.insert( nodes );
        }
        ll a = st.size();
        cout<<a<<"\n";
    }
}