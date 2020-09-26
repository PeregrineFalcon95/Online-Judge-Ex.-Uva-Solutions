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
int n, m, cases, t , ans;
string s , s2 , s3;
int ar [ mxs ], ar2 [ mxs ];
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
    cin>>t;
    int xox = 0;
    while( t-- )
    {
        if ( xox )cout<<"\n";
        xox = 1;
        cin>>m;
        int a , b;
        vector < pair < int , int > > v , lol ,temp;
        while( cin>>a>>b && ( a || b ) )
        {
            if ( b < 0 || a > m )continue;
            v.push_back( { a , b } );
        }
        sort( v.begin() , v.end() );
        n = v.size();
        int pos = 0;
        for ( int i = 0 ; i < n; i++ )
        {
            if ( v [ i ].first <= pos )
            {
                temp.push_back( { v [ i ].second , v [ i ].first } );
            }
            else
            {
                if( temp.empty() )break;
                sort( temp.begin() , temp.end() , cmp );

                lol.push_back( { temp.front().second , temp.front().first } );

                temp.clear();
                pos = lol.back().second;
                if ( v [ i ].first <= pos )temp.push_back( { v [ i ].second , v [ i ].first } );

                if ( pos >= m )break;
            }
        }

        if ( pos < m && !temp.empty() )
        {
            sort( temp.begin(), temp.end() , cmp );

            lol.push_back( { temp.front().second , temp.front().first } );

            temp.clear();
            pos = lol.back().second;
        }


        if ( pos < m ){cout<<"0\n";continue;}
        cout<<lol.size()<<"\n";
        n = lol.size();
        for ( int i = 0 ; i < n; i++ )cout<<lol [ i ].first<<" "<<lol [ i ].second<<"\n";
    }
}
