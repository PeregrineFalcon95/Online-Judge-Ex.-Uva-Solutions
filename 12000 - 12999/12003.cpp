/// This problem can be solved using various approaches. I solved it using square root decomposition
/// It can also be solved using Merge sort tree, with multi set.
/// My approach - Create some blocks with size of square root of n,
/// For each block save the values of this block in sorted order
/// For each query jump through the blocks, run some binary search, count the number of the values less then the given value.
/// Calculate the required value. Iterate through the vector of the block of the given index.
/// Update the value, sort the particular vector.( To optimize the run time you can skip sorting, just erase the value, and insert the new value in the required index ).
/// After finishing the query just print the array.





///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#define ll long long int
#define inf ( int )( 1e9 + 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod (ll)(1e9)+7
//int dx[]={+1,0,+0,-1};///Four Directions
//int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
ll t, n, m, j, k,a, b, c, d, e,f  , i,sz,cases ,q,ans,le,re,val,idx,hi,lo,mid,x,y;
string s, s2, s3, s4;
vector < ll > v [ 600 ];
vector < ll >::iterator it;
ll ar [ mxs ] , ar2 [ mxs ] , ar3 [ mxs ] , com [ mxs ] , next_right [ mxs ] , next_left [ mxs ];
void brainfuck();
void compress()
{
    sz = sqrt( n + 1 );
    a = 0;
    b = 1;
    for ( i = 1 ; i <= n; i++ )
    {
        a++;
        if ( a == sz )
        {
            a = 0;
            b++;
        }
        com [ i ] = b;
        v [ b ].push_back( ar [ i ] );
    }
    sz = b;
    a = sz + 1;
    for ( i = n; i >= 1 ; i-- )
    {
        if ( com [ i ] + 1 != a  )a--;
        next_right [ i ] = a;
    }
    a = 0;
    for ( i = 1 ; i <= n; i++ )
    {
        if ( com [ i ] - 1 != a )a++;
        next_left [ i ] = a;
    }
    for ( i = 1 ; i <= sz ; i++ )sort( v [ i ].begin() , v [ i ].end() );
}
void query()
{
    ans = 0;
    ///Iterating to the next block
    a = next_right [ le ];
    for ( i = le; i <= re && com [ i ] != a; i++ )
    {
        if ( ar [ i ] < val )ans++;
        le = i;
    }

    ///Iterating to the next block
    b = next_left [ re ];
    for ( i = re; i > le && com [ i ] != b; i-- )
    {
        if ( ar [ i ] < val )ans++;
        re = i;
    }

    ///Querying each block for the number of smaller elements
    if ( a <= b )
    {
        le = a;
        re = b;
        for ( i = le; i <= re; i++ )
        {
            it = upper_bound( v [ i ].begin(), v [ i ].end(), val - 1 );
            if ( it == v [ i ].begin() )
                continue;
            it--;
            ans += (it-v [ i ].begin() )+1;
        }
    }

    a = com [ idx ];
    b = v [ a ].size();
    for ( i = 0 ; i < b; i++ )
    {
        if ( v [ a ] [ i ] == ar [ idx ] )
        {
            v [ a ] [ i ] = (f*ans/( y - x + 1 ));
            ar [ idx ] = (f*ans/( y - x + 1 ));
            break;
        }
    }
    sort( v [ a ].begin() , v [ a ].end() );
}
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>n>>q>>f;
    for ( i = 1 ; i <= n ; i++ )cin>>ar [ i ];
    compress();
    while( q-- )
    {
        cin>>le>>re>>val>>idx;
        x = le , y = re;
        query();
    }
    for ( i = 1 ; i <= n; i++ )cout<<ar [ i ]<<"\n";
}

