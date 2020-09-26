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
int ar [ mxs ] ;
string s , s2;
struct problem
{
    int id;
    int time_;
};
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
    int tt;
    cin>>n>>tt>>m;

    ///Struct array, to save result of each problem
    problem arr [ n + 1 ];
    memset( arr , 0 , sizeof arr );

    ///Array to mark the first submission of each team.
    bool marker [ n + 1 ] [ tt + 1 ];
    memset( marker , false , sizeof marker );

    int tim , idd;
    string pro , ver;
    while( m-- )
    {
        cin>>tim>>idd>>pro>>ver;

        ///Checking for each problem
        if ( arr [ pro [ 0 ] - 'A' ].time_ <= tim && ver [ 0 ] == 'Y' && marker [ pro [ 0 ] - 'A' ] [ idd ] == false )
        {
            arr [ pro [ 0 ] - 'A' ].id = idd;
            arr [ pro [ 0 ] - 'A' ].time_ = tim;
            marker [ pro [ 0 ] - 'A' ] [ idd ] = true;
        }
    }
    for ( int i = 0 ; i < n; i++ )
    {
        if ( arr [ i ].id )cout<<(char)(i+'A')<<" "<<arr [ i ].time_<<" "<<arr [ i ].id<<"\n";
        else cout<<(char)(i+'A')<<" - -\n";
    }
}
