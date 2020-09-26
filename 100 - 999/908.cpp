#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,sum,ee,jjj;
int parent [ 1000009 ] , dis [ 1000009 ];
bool visited  [ 100009 ];
vector < pair < int , int >  > graph [ 1000009 ];
int mst();
int main()
{
    while ( scanf("%d",&n) == 1 )
    {
        if( jjj )putchar( 10 );
        jjj++;
        ee = n;
        for ( int i = 0; i <= n; i++ )
        {
            dis [ i ] = INT_MAX;
            graph [ i ].clear();
            parent [ i ] = -1;
            visited [ i ] = 0;
        }
        sum = 0;
        for ( int i = 1; i < n; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            sum+=c;
        }
        scanf("%d",&n);
        for ( int i = 0; i != n; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph [ a ].push_back ( pair < int , int > ( b , c ) );
            graph [ b ].push_back ( pair < int , int > ( a , c ) );
        }
        scanf("%d",&n);
        for ( int i = 0; i != n; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph [ a ].push_back ( pair < int , int > ( b , c ) );
            graph [ b ].push_back ( pair < int , int > ( a , c ) );
        }
        int ans = mst();
        printf("%d\n%d\n",sum,ans);
    }
    return 0;
}
int mst()
{
    dis [ 1 ] = 0;
    int v = 1;
    int ans = 0;
    while ( !visited [ v ] )
    {
        visited [ v ] = 1;
        int sz = graph [ v ].size();
        for ( int i = 0; i != sz; i++ )
        {
            int w = graph [ v ] [ i ].second;
            int u = graph [ v ] [ i ].first;
            if ( !visited [ u ] && w < dis [ u ] )
            {
                dis [ u ] = w;
                parent [ u ] = v;
                int j = w;
                j = -j ;
            }
        }
        int mist = INT_MAX;
        for ( int i = 1; i <= ee; i++ )
        {
            if ( !visited [ i ] && mist > dis [ i ] )
            {
                v = i;
                mist = dis [ i ];
            }
        }
    }
    for ( int i = 1; i <= ee; i++ )
    {
        ans+= dis [ i ];
    }
    return ans;
}

