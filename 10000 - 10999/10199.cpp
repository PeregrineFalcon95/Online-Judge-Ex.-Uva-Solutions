#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,kk,time_,l,ooo;
bool visited[ 110 ];
int parent [ 110 ],dis [ 110 ], lo [ 110 ];
map < string, int > com_st;
map < int, string > com_num;
vector < int > graph [ 110 ];
set < int > ans;
int art ( int source );
int main()
{
    while( scanf("%d",&n)==1 && n )
    {
        kk = 0;
        if ( l )putchar(10);
        l++;
        time_ = 0;
        ans.clear();
        string s,s2;
        com_st.clear();
        com_num.clear();
        for ( int i = 1; i <= n; i++ )
        {
            lo [ i ] = 99999;
            dis [ i ] = 0;
            visited [ i ] = 0;
            parent [ i ] = 0;
            graph [ i ].clear();
            cin>>s;
            com_st [ s ] = i;
            com_num [ i ] = s;
        }
        scanf("%d",&m);
        getchar();
        for ( int i = 0; i != m; i++ )
        {
            getline(cin,s);
            stringstream ss ( s );
            c = 0;
            while ( ss >> s2 )
            {
                if ( !c )
                {
                    a = com_st [ s2 ];
                    c++;
                    continue;
                }
                b = com_st [ s2 ];
            }
            graph [ a ].push_back ( b );
            graph [ b ].push_back ( a );
        }
        for ( map < int, string > ::iterator it = com_num.begin(); it != com_num.end(); it++ )
        {
            if ( !visited [ it->first ] )
            {
                kk = 0;
                ooo = it->first;
                art( it->first );
                if ( kk > 1 )
                {
                    ans.insert ( it->first );
                }
            }
        }
        map < string, int > mp;
        for ( set < int > ::iterator it = ans.begin(); it != ans.end(); it++ )
        {
            mp [ com_num [ *it ] ] = 0;
        }
        printf("City map #%d: %d camera(s) found\n",l,ans.size());
        for ( map < string, int > ::iterator it = mp.begin(); it != mp.end(); it++ )
        {
            cout<<it->first<<"\n";
        }
    }
    return 0;
}
int art ( int source )
{
    visited [ source ] = 1;
    time_++;
    dis [ source ] = lo [ source ] = time_;
    int sz = graph [ source ].size();
    for ( int i = 0; i != sz ; i++ )
    {
        int o_o = graph [ source ] [ i ];
        if ( parent [ source ] == o_o )continue;
        if ( visited [ o_o ] )
        {
            lo [ source ] = min ( dis [ o_o ], lo [ source ] );
            continue;
        }
        parent [ o_o ] = source;
        art ( o_o );
        lo [ source ] = min( lo [ source ], lo [ o_o ] );
        if ( source == ooo )
        {
            kk++;
        }
        else if ( source != ooo && dis [ source ] <= lo [ o_o ] )
        {
            ans.insert ( source );
        }
    }
    return 0;
}

