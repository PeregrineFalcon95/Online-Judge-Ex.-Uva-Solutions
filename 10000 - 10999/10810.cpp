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
#define mxs (int)(1e6+100)
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
int ar [ mxs ] , temp [ mxs ];
ll count_ = 0;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
void mergeSort( int Left, int Right )
{
    if ( Left >= Right )return;
    int mid = ( Left + Right )>>1;

    mergeSort( Left , mid );
    mergeSort( mid + 1 , Right );

    for ( int i = Left ; i <= Right; i++ )
        temp [ i ] = ar [ i ];

    int l = Left , r = mid + 1 , idx = Left;

    while( l <= mid && r <= Right )
    {
        if ( temp [ l ] < temp [ r ] )
        {
            count_ += idx - l;
            ar [ idx++ ] = temp [ l++ ];
        }
        else
        {
            if( idx - r > 0 )count_ += idx - r;
            ar [ idx++ ] = temp [ r++ ];
        }
    }

    while( l <= mid )
    {
        count_ += idx - l;
        ar [ idx++ ] = temp [ l++ ];
    }
    while( r <= Right )
    {
        if( idx - r > 0 ) count_ += idx - r;
        ar [ idx++ ] = temp [ r++ ];
    }
}
void brainfuck();
int main()
{
    //freopen("tour.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //fast
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    while( scanf("%d",&n) == 1 && n )
    {
        getchar();

        for ( int i = 1 ; i <= n; i++ )
        {
            //scanf("%d",&ar [ i ] );
            fastscan( ar [ i ] );
        }

        count_ = 0;
        mergeSort( 1 , n );

        printf("%lld\n",count_);
    }
}



/// https://codeforces.com/gym/101628/problem/f
/// https://codeforces.com/contest/144/problem/D
/// https://codeforces.com/gym/102006/problem/K
/// https://codeforces.com/contest/1397/problem/D
/// https://codeforces.com/contest/59/problem/D
/// https://codeforces.com/contests/page/13

