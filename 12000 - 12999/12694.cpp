#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while( n-- )
    {
        vector < pair < int, int > > v;
        int a,b;
        while( scanf("%d%d",&a,&b)==2 && ( a+b ) )
        {
            v.push_back( pair < int, int > (b,a) );
        }
        sort(v.begin(),v.end());
        int sz = v.size();
        int  ans = 0, wz = 0;
        for( int i = 0; i != sz; i++ )
        {
            if ( wz <= v[i].second )
            {
                ans++;
                wz = v[i].first;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


///Wrong solution AC
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for ( int l = 0; l != n; l++ )
    {
        int a,b;
        multimap < int, pair < int, int > > mp;
        while(scanf("%d%d",&a,&b) == 2 && ( a || b ) )
        {
            mp.insert( make_pair (b-a, make_pair ( a,b ) ) );
        }
        bool visited [ 12 ];
        memset ( visited, 0 , sizeof visited );
        multimap < int, pair < int, int > >::iterator it =mp.begin();
        int ans=0;
        for ( it = mp.begin(); it != mp.end(); it++ )
        {
            int flag = 0;
            int i =it->second.first+1;
            int c = it->second.second;
            for ( ; i < c; i++ )
            {
                if( visited [ i ])
                {
                    flag = 1;
                    break;
                }
            }
            if ( !flag )
            {
                i =it->second.first;
                for ( ; i <= c; i++ )
                {
                    visited [ i ] = 1;
                }
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}*/
