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
//#pragma comment(linker, "/stack:200000000")
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define mod ( ll  ) 1000000000000//( 1e9 + 7 )  //( 1e9 + 7 )
#define inf ( int  )( 1e9 + 10 )
#define mxs (int)(1e5+100)
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

int n , m, x, t, ans, cases ;
string s , s2;
vector < int > graph [ mxs ];
int marker [ mxs ] , level [ mxs ];
bool visited [ mxs ];
set < int > st;
set < int >:: iterator it , it2;

int finder()
{
    double mi = 999999999999999999;
    int a , b , c , id;
    c = st.size();
    c--;
    for ( it = st.begin(); it != st.end(); it++ )
    {
        queue < int > qu;
        for ( int i = 1 ; i <= n; i++ )
        {
            visited [ i ] = 0;
        }
        qu.push( *it );
        visited [ *it ] = 1;
        level [ *it ] = 0;
        while( !qu.empty() )
        {
            a = qu.front();
            qu.pop();
            int sz = graph [ a ].size();
            for ( int i = 0 ; i < sz; i++ )
            {
                b = graph [ a ] [ i ];
                if ( !visited [ b ] )
                {
                    visited [ b ] = 1;
                    qu.push( b );
                    level [ b ] = level [ a ] + 2;
                }
            }
        }
        double val = 0.00;
        for ( it2 = st.begin(); it2 != st.end(); it2++ )
        {
            val += (double) level [ *it2 ];
        }
        if ( mi > val / (double)c )
        {
            mi = val / (double)c;
            id = *it;
        }
    }
    return id;
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
    for ( int i = 1 ; i <= n; i++ )
    {
        graph [ i ].clear();
        marker [ i ] = -1;
    }
    st.clear();
    while( m-- )
    {
        cin>>a;
        if ( marker [ a ] != -1 )st.insert( a );
        marker [ a ] = m;
        b = a;
        while( b )
        {
            cin>>a;
            if ( !a )break;
            if ( marker [ a ] != -1 && marker [ a ] != m  )
            {
                st.insert( a );
            }
            marker [ a ] = m;
            graph [ a ].push_back( b );
            graph [ b ].push_back( a );
            b = a;
        }
    }
    cout<<"Krochanska is in: "<<finder()<<"\n";

}

