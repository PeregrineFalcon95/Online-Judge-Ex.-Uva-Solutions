#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
#pragma comment(linker, "/stack:200000000")
#define mod 100000007
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)( 1e5 + 1e5 + 10 )
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
ll ans, t, n, m, i, j, k, a, b, c, d, g , q , cases;
ll x , y , mid , lo , hi , mi;
string s , s2, s3, s4;
struct data
{
    ll sz;
    ll st , en;
    ll sum;
    ll row , col;
};
vector < data > v;
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
    data lol;
    lol.sz = 1;
    lol.st = 1;
    lol.en = 1;
    lol.sum = 1;
    lol.row = 0;
    lol.col = 0;
    a = b = 1;
    v.push_back( lol );
    for ( i = 1 ; i <= 100002; i++ )
    {
        a = b + 1;
        b = a + 8 * i - 1;

        lol.sz = 8 * i;
        lol.st = a;
        lol.en = b;
        lol.sum = b - a + 1;
        lol.row = i;
        lol.col = i - 1;
        v.push_back( lol );
    }
    ll num , idx , r;
    while( cin>>n>>num && n )
    {
        mid = n / 2 + 1;
        lo = 0 , hi = 100001;
        while ( lo <= hi )
        {
            mi = ( lo + hi )>>1;
            if ( num >= v [ mi ].st && num <= v [ mi ].en )
            {
                idx = mi;
                break;
            }
            else if ( v [ mi ].en < num )lo = mi + 1;
            else hi = mi - 1;
        }
        r = v [ idx ].row + mid;
        c = v [ idx ].col + mid;
        ll sz = idx * 2 + 1;
        if ( num == 1 )x = mid , y = mid;
        else if ( num - v [ idx ].st + 1 < sz  )
        {
            ///UP
            x = r;
            y = ( v [ idx ].col + mid ) - ( num - v [ idx ].st );
        }
        else if ( num - v[ idx ].st + 1 < sz + sz - 1 )
        {
            ///Left
            y = mid - idx;
            x = mid + idx - 2 - ( num - ( v [ idx ].st + sz ) );
        }
        else if ( num - v [ idx ].st + 1 < sz + sz + sz - 2 )
        {
            ///Down
            x = mid - idx;
            y = mid - idx + 1 + ( num - ( v [ idx ].st + sz + sz - 2 ) );
        }
        else
        {
            ///Right
            y = mid + idx;
            x = mid + idx - ( v [ idx ].en - num );
        }
        cout<<"Line = "<<x<<", column = "<<y<<".\n";
    }
}
