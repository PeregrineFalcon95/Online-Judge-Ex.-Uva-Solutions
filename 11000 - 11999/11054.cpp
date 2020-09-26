#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//#pragma comment(linker, "/stack:200000000")
#define mod ( ll  ) ( 998244353 )  //( 1e9 + 7 )
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
ll n, m, cases, t , ans;
string s , s2 , s3;
ll ar [ mxs ], ar2 [ mxs ];
bool cmp( pair < int , int > a , pair < int , int > b )
{
    if ( a.first == b.first )return a.second < b.second;
    return a.first > b.first;
}
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
    while( cin>>n && n )
    {
        for ( int i = 1 ; i <= n; i++ )cin>>ar [ i ];
        ans = 0;
        ll carry = 0;
        for ( int i = 1;  i <= n; i++ )
        {
            ans += abs(carry);
            carry += ar [ i ];
        }
        cout<<ans<<"\n";
    }
}
