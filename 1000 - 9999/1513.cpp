/*One Last Drive*/
#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
#pragma comment(linker, "/stack:200000000")
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define mod ( ll  ) ( 1e9 + 7 )
#define inf ( int  )( 1e9 + 10 )
#define mxs (int)(1e6+100)
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves

//void fastscan(int &number)
//{
//    register int c;
//    number = 0;
//    c = getchar();
//    for (; (c>47 && c<58); c=getchar())
//        number = number *10 + c - 48;
//}
int n , m, x, t, ans, cases , last;
string s , s2;
int pos [ mxs ];
struct dat
{
    int val;
    int lazy;
};
dat tre [ mxs ];
void build( int node , int le , int re )
{
    if ( le == re )
    {
        if ( le > n )
        {
            tre [ node ].lazy = 0;
            tre [ node ].val = 0;
            return;
        }
        int x = n - ( le - 1 );
        pos [ x ] = le;
        tre [ node ].val = n - x;
        tre [ node ].lazy = 0;
        return;
    }
    int mid = ( le + re )>>1;
    build( node + node , le , mid );
    build( node + node + 1, mid + 1 , re );
    tre [ node ].lazy = 0;
}
void pushLazy( int node , int le , int re )
{
    if ( tre [ node ].lazy )
    {
        if ( le == re )tre [ node ].val += tre [ node ].lazy;

        tre [ node + node ].lazy += tre [ node ].lazy;
        tre [ node + node + 1 ].lazy += tre [ node ].lazy;
        tre [ node ].lazy = 0;
    }
}
void update( int node , int le , int re , int Left , int Right )
{
    if ( Left > Right )return;
    if ( le == Left && re == Right )
    {
        ///In range
        tre [ node ].lazy -= 1;
        pushLazy( node , le , re );
        return;
    }
    int mid = ( le + re )>>1;
    pushLazy( node , le , re );
    update( node + node , le , mid , Left , min( Right , mid ) );
    update( node + node + 1 , mid + 1 , re , max(Left , mid + 1 ) , Right );
}
void updateVal( int node , int le , int re , int Left, int Right )
{
    if ( Left > Right )return;
    if ( le == Left && re == Right )
    {
        tre [ node ].lazy = 0;
        tre [ node ].val = n - 1;
        return;
    }
    int mid = ( le + re )>>1;
    pushLazy( node , le , re );
    updateVal( node + node , le , mid , Left , min( Right , mid ) );
    updateVal( node + node + 1 , mid + 1 , re , max(Left , mid + 1 ) , Right );
}
int query( int node , int le , int re , int Left , int Right )
{
    if ( Left > Right )return inf;
    if ( le == Left && re == Right )
    {
        tre [ node ].val += tre [ node ].lazy;
        tre [ node ].lazy = 0;
        return tre [ node ].val;
    }
    int mid = ( le + re )>>1;
    pushLazy( node , le , re );
    return min( query( node + node , le , mid , Left , min( Right , mid  ) ) , query( node + node + 1 , mid + 1 , re , max( Left , mid + 1 ) , Right ) );
}
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    cin>>t;
    //t = 1;
    //scanf("%d",&t);
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    int a , b , c;
    cin>>n>>m;
    last = n;
    build( 1 , 1 , n + m);
    int xx = m;
    while( m-- )
    {
        cin>>a;
        cout<<( n - ( query( 1 , 1 , n + xx , pos [ a ] , pos [ a ] ) + 1 ));
        if ( m )cout<<" ";
        update( 1 , 1 , n + xx , pos [ a ] + 1 , last );
        last++;
        updateVal( 1 , 1 , n + xx, last , last );
        pos [ a ] = last;
    }
    cout<<"\n";
}

