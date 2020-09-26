#include<bits/stdc++.h>
using namespace std;
map < string , string > mp;
string ar [ 5005];
string find_parent( string a );
int main()
{
    int n,m,t = 0;
    while( scanf("%d%d",&n,&m) && ( n || m ))
    {
        if ( t )getchar();
        t++;
        mp.clear();
        for ( int i =0; i != n; i++ )
        {
            cin >> ar [ i ];
            mp [ ar [ i ] ]  = ar [ i ];
        }
        for ( int i = 0; i != m; i++ )
        {
            string s,t;
            cin>>s>>t;
            string ss = find_parent( s );
            string tt = find_parent( t );
            if ( ss != tt ) mp [ tt ] = ss;
        }
        for ( int i = 0; i != n; i++ )
        {
            if ( mp [ ar [ i ] ] != ar [ i ] )
            {
                ar [ i ] = find_parent( ar [ i ]);
            }
        }
        int mx =0;
        map < string, int > mpp;
        for ( int i = 0; i != n; i++ )
        {
            mpp [ ar [ i ] ]++;
        }
        for ( map < string , int > ::iterator it = mpp.begin(); it != mpp.end(); it++ )
        {
            if ( it->second > mx )mx = it->second;
        }
        printf("%d\n",mx);
    }
    return 0;
}
string find_parent( string a )
{
    if ( mp [ a ] == a )return a ;
    mp [ a ] = find_parent( mp [ a ]);
    return mp [ a ];
}
