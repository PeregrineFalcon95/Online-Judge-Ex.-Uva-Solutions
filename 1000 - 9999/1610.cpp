
#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//#pragma comment(linker, "/stack:200000000")
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define mod ( ll  ) ( 1e9 + 7 )  //( 1e9 + 7 )
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)(1e6+10)//( 1e6 + 10 )
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves
int n, m, t, ans , cases;
string s , s2;
int ar [ mxs ];
int solution [ mxs ];
int lastPosition [ mxs ];
int gap [ mxs ];
void brainfuck();
int main()
{
    //freopen("tour.in","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    while( cin>>n && n )
    {
        vector < string > v;
        for ( int i = 0 ; i < n; i++ )
        {
            cin>>s;
            v.push_back( s );
        }
        sort( v.begin() , v.end() );

        int mid = n / 2 - 1;

        s = v [ mid ];
        s2 = v [ mid + 1 ];

        string temp = "";

        for ( int i = 0 ; ; i++ )
        {
            temp += "A";
            while( s [ i ] > temp [ i ] )temp [ i ]++;

            if ( temp >= s && temp < s2 )
            {
                cout<<temp<<'\n';
                break;
            }
            if ( temp [ i ] < 'Z' )
            {
                temp [ i ]++;
                if ( temp >= s && temp < s2 )
                {
                    cout<<temp<<'\n';
                    break;
                }
                temp [ i ]--;
            }
        }
    }
}
