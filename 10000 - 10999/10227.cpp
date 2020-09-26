#include<bits/stdc++.h>
using namespace std;
map < set < int > , int > mp;
int t , n , m , a , b ,  c , d , x;
vector < int > v [ 110 ];
string s , s2;
set < int > st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    x = t - 1;
    while ( t-- )
    {
        if ( x != t )cout<<"\n";
        mp.clear();
        cin>>n>>m;
        cin.ignore();
        while ( getline(cin,s) )
        {
            if ( !s.size() )break;
            stringstream ss ( s );
            c = 0;
            while ( ss >> s2 )
            {
                d = 0;
                for ( int j = 0; j != s2.size(); j++ )
                {
                    d *= 10;
                    d += s2 [ j ] - '0';
                }
                if ( !c )
                {
                    a = d;
                    c++;
                }
                else b = d;
            }
            v [ a ].push_back ( b );
        }
        for ( int i = 1; i <= n; i++ )
        {
            if ( !v [ i ].size() )st.insert( 0 );
            while ( !v [ i ].empty() )
            {
                st.insert( v [ i ].back() );
                v [ i ].pop_back();
            }
            mp [ st ] = 1;
            st.clear();
        }
        cout<<mp.size()<<"\n";
    }
    return 0;
}
