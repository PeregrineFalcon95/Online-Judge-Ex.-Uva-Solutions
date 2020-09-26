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
    while( cin>>n>>m )
    {
        vector < double > v , temp [ n ];
        double x , y ,a , b = 0.00 , ave = 0.00;
        for ( int i = 1 ; i <= m; i++ )
        {
            cin>>a;
            ave += a;
            v.push_back( a );
        }
        ave /= (double)n;
        sort( v.begin() , v.end() );
        t = 0;
        int marker = 0;
        while( !v.empty() )
        {
            temp [ t ].push_back( v.back() );
            v.pop_back();

            if ( marker )t--;
            else t++;

            if ( t == n )marker = 1 , t--;
        }
        b = 0.00;
        cout<<"Set #"<<++cases<<"\n";
        for ( int i = 0 ; i < n; i++ )
        {
            cout<<" "<<i<<":";
            if ( temp [ i ].size() >= 1 )cout<<" "<<fixed<<setprecision(0)<<temp [ i ] [ 0 ];
            if ( temp [ i ].size() >= 2 )cout<<" "<<fixed<<setprecision(0)<<temp [ i ] [ 1 ];
            x = 0.00;
            for ( int j = 0 ; j < temp [ i ].size(); j++ )
            {
                x += temp [ i ] [ j ];
            }
            b += fabs(ave - x);
            cout<<"\n";
        }
        cout<<"IMBALANCE = "<<fixed<<setprecision(5)<<b<<"\n\n";
    }
}
