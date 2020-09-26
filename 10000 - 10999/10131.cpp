#include<bits/stdc++.h>
using namespace std;
#define mxs 1005
int dp [ mxs ] , dp2 [ mxs ] , dir [ mxs ] , dir2 [ mxs ];
vector < pair < int , pair < int , int > > > v , v2;
vector < int > ans;
int n , m , a , b , c , mx2 , mx1 , start1 , start2;
int lis ( int node );
int lis2 ( int node );
int main()
{
    memset ( dp , -1 , sizeof dp );
    memset ( dp2 , -1 , sizeof dp2 );
    memset ( dir , -1 , sizeof dir );
    memset ( dir2 , -1, sizeof dir2 );
    while ( scanf("%d%d",&a,&b) == 2 )
    {
        v.push_back( make_pair( a , make_pair( b , n ) ) );
        v2.push_back( make_pair ( b , make_pair( a , n++ ) ) );
    }
    sort( v.begin(),v.end() );
    for ( int i = 0; i < n; i++ )
    {
        a = lis( i );
        if ( a > mx1 )
        {
            mx1 = a;
            start1 = i;
        }
    }
    sort( v2.begin() , v2.end() );
    reverse( v2.begin() , v2.end() );
    for ( int i = 0; i < n; i++ )
    {
        a = lis2 ( i );
        if ( a > mx2 )
        {
            mx2 = a;
            start2 = i;
        }
    }
    if ( mx1 > mx2 )
    {
        printf("%d\n",mx1);
        while( dir [ start1 ] != -1 )
        {
            ans.push_back ( v [ start1 ].second.second );
            start1 = dir [ start1 ];
        }
        ans.push_back( v [ start1 ].second.second );
        while ( !ans.empty() )
        {
            printf("%d\n",ans.back() + 1 );
            ans.pop_back();
        }
    }
    else
    {
        printf("%d\n",mx2);
        while ( dir2 [ start2 ] != -1 )
        {
            ans.push_back( v2 [ start2 ].second.second );
            start2 = dir2 [ start2 ];
        }
        ans.push_back( v2 [ start2 ].second.second );
        for ( int i = 0; i != ans.size(); i++ )printf("%d\n",ans [ i ] + 1);
    }

    return 0;
}
int lis ( int node )
{
    if ( dp [ node ] != -1 )return dp [ node ];
    int x , mx = 0;
    for ( int i = node + 1 ; i < n; i++ )
    {
        if ( v [ node ].first < v [ i ].first && v [ node ].second.first > v [ i ].second.first )
        {
            x = lis ( i );
            if ( x > mx )
            {
                mx = x;
                dir [ node ] = i;
            }
        }
    }
    return ( dp [ node ] = ( mx + 1 ) );
}
int lis2 ( int node )
{
    if ( dp2 [ node ] != -1 )return dp2 [ node ];
    int x , mx = 0;
    for ( int i = node + 1 ; i < n; i++ )
    {
        if ( v2 [ node ].first > v2 [ i ].first && v2 [ node ].second.first < v2 [ i ].second.first )
        {
            x = lis2 ( i );
            if ( x > mx )
            {
                mx = x;
                dir2 [ node ] = i;
            }
        }
    }
    return ( dp2 [ node ] = ( mx + 1 ) );
}



///Wrong Solution, but got ac
/*#include<bits/stdc++.h>
using namespace std;
#define mxs 1010
#define inf 99999999
deque < pair < int , pair < int , int > > > wi,iq;
vector < int > ans;
int n , m , a , b , c , mx , mx2 , i , sz , lo , hi , mid;
int dp [ mxs ] , dp2 [ mxs ] , temp [ mxs ] , temp2 [ mxs];
void lis1();
void lis2();
void printer();
void printer2();
int main()
{
    n = 1;
    while ( scanf("%d%d",&a,&b) == 2 )
    {
        wi.push_back ( make_pair( a , make_pair( b , n ) ) );
        iq.push_back ( make_pair( b , make_pair( a , n ) ) );
        n++;
    }
    sort( wi.begin(), wi.end() );
    sort( iq.begin(), iq.end() );
    reverse( iq.begin() , iq.end() );
    wi.push_front ( make_pair( 0 , make_pair( 0 , 0 ) ) );
    iq.push_front ( make_pair( 0 , make_pair( 0 , 0 ) ) );
    temp [ 0 ] = temp2 [ 0 ] = -inf;
    for ( i = 1; i <= n; i++ )temp [ i ] = temp2 [ i ] = inf;
    lis1();
    lis2();
    printf("%d\n",max(mx,mx2));
    if ( mx > mx2 )printer();
    else printer2();
    return 0;
}
void lis1()
{
    for ( i = 1; i <= n; i++ )
    {
        lo = 0;
        hi = n;
        while ( lo <= hi )
        {
            mid = ( lo + hi ) / 2;
            if ( temp [ mid ] >= wi [ i ].second.first )hi = mid - 1 ;
            else lo = mid + 1;
        }
        temp [ lo ] = wi [ i ].second.first;
        dp [ i ] = lo;
        mx = max ( mx , dp [ i ] );
    }
}
void lis2()
{
    for ( i = 1; i <= n; i++ )
    {
        lo = 0;
        hi = n;
        while ( lo <= hi )
        {
            mid = ( lo + hi ) / 2;
            if ( temp2 [ mid ] >= iq [ i ].second.first )hi = mid - 1 ;
            else lo = mid + 1;
        }
        temp2 [ lo ] = iq [ i ].second.first;
        dp2 [ i ] = lo;
        mx2 = max ( mx2 , dp2 [ i ] );
    }
}
void printer()
{
    for ( i = n; i >= 1; i-- )
    {
        if ( mx == dp [ i ] )
        {
            mx--;
            ans.push_back(wi [ i ].second.second );
        }
    }
    while(!ans.empty() )
    {
        printf("%d\n",ans.back());
        ans.pop_back();
    }
}
void printer2()
{
    for ( i = n; i >= 1; i-- )
    {
        if ( mx2 == dp2 [ i ] )
        {
            mx2--;
            ans.push_back(iq [ i ].second.second);
        }
    }
    while ( !ans.empty() )
    {
        printf("%d\n",ans.back());
        ans.pop_back();
    }
}
*/