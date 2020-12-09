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
#define ll long long int
#define mod ( ll  ) ( 1e9 + 7 )  //( 1e9 + 7 )
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
int n , m, t, ans, cases ;
string s , s2;
int ar [ 110 ];
double xx [ 110 ];
double dp [ 22 ] [ 105 ];
double rec ( int idx , int num )
{
    if ( num <= 0 )return 0.00;
    if ( idx > n )return 999999999999.00;
    if ( dp [ idx ] [ num ] != -1 )return dp [ idx ] [ num ];

    dp [ idx ] [ num ] = rec( idx , num - ar [ idx ] ) + xx [ idx ];
    return dp [ idx ] [ num ] = min( dp [ idx ] [ num ] , rec( idx + 1 , num ) );
}
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    fast
    //cin>>t;
    t = 1;
    //scanf("%d",&t);
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    double price;
    while( cin>>price>>n )
    {
        n++;
        for ( int i = 0 ; i <= 21; i++ )
            for ( int j = 1; j <= 101; j++ )dp [ i ] [ j ] = -1;
        ar [ 1 ] = 1;
        xx [ 1 ] = price;
        for ( int i = 2 ; i <= n; i++ )
            cin>>ar [ i ]>>xx [ i ];

        dp [ 1 ] [ 100 ] = rec( 1 , 100 );

        cout<<"Case "<<++cases<<":\n";
        cin.ignore();
        getline(cin,s);
        stringstream ss ( s );
        while( ss >> s2 )
        {
            stringstream num(s2);
            num>>m;
            cout<<fixed<<"Buy "<<m<<" for $"<<setprecision(2)<<rec(1 , m)<<"\n";
        }
    }
}
