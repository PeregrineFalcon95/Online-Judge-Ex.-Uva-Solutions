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
struct solver
{
    int numberOfSolved = 0;
    int penalty = 0;
    bool isPresent = false;
    int id;
};
bool cmp( solver a , solver b )
{
    if ( a.isPresent == b.isPresent && a.isPresent == true )
    {
        if ( a.numberOfSolved > b.numberOfSolved )return true;
        if ( b.numberOfSolved > a.numberOfSolved )return false;

        if ( a.penalty < b.penalty )return true;
        if ( b.penalty < a.penalty )return false;

        return a.id < b.id;
    }

    return a.isPresent > b.isPresent;
}
void brainfuck();
int main()
{
    //freopen("tour.in","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    cin>>t;
    //t = 1;
    cin.ignore();
    cin.ignore();
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    ///Array to track the problems for each contestant
    bool marker [ 105 ] [ 11 ];
    memset( marker , false , sizeof marker );

    ///Array to count Penalty of each contestants
    int penalty [ 105 ] [ 11 ];
    memset( penalty , 0 , sizeof penalty );

    ///Structure array to store information
    solver ar [ 105 ];
    memset( ar , 0 , sizeof ar );
    for ( int i = 0 ; i <= 103; i++ )ar [ i ].id = i;

    while( getline( cin , s ) )
    {
        if ( s.empty() )break;
        int time_, idd, num ,counter = 0;

        ///Streaming the entire string
        stringstream ss ( s );
        while( ss >> s2 )
        {
            if ( !counter )
            {
                ///Contestant id
                idd = stoi( s2 );
                ar [ idd ].isPresent = true;
            }
            else if ( counter == 1 )
            {
                ///Problem number
                num = stoi( s2 );
            }
            else if ( counter == 2 )
            {
                ///Submission time
                time_ = stoi( s2 );
            }
            else
            {
                ///Verdict
                if ( s2 [ 0 ] == 'C' && marker [ idd ] [ num ] == false )
                {
                    marker [ idd ] [ num ] = true;
                    penalty [ idd ] [ num ] += time_;

                    ar [ idd ].penalty += penalty [ idd ] [ num ];
                    ar [ idd ].numberOfSolved++;
                }
                else if ( s2 [ 0 ] == 'I' && marker [ idd ] [ num ] == false )
                {
                    penalty [ idd ] [ num ] += 20;
                }
            }

            counter++;
        }
    }

    sort( ar + 1 , ar + 101  , cmp );

    for ( int i = 1 ; i <= 101; i++ )
    {
        if ( ar [ i ].isPresent == true )
        {
            cout<<ar [ i ].id<<" "<<ar [ i ].numberOfSolved<<" "<<ar [ i ].penalty<<"\n";
        }
    }
    if ( t )cout<<"\n";
}
