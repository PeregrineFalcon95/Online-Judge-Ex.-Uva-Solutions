#include<bits/stdc++.h>
using namespace std;
int main()
{
    map < int, int > mp;
    multiset < pair < int, int > > st;
    string s;
    int a,b;
    int mi =INT_MAX;
    while( cin >> s )
    {
        if( s == "#" )break;
        scanf("%d%d",&a,&b);
        mp [ a ] = b;
        if( b < mi )mi= b;
    }
    scanf("%d",&a);
    for ( map < int, int > ::iterator it = mp.begin(); it != mp.end(); it++ )
    {
        b = it->second;
        int flag = b;
        int c = mi * a;
        for ( int i = 0; ; i++ )
        {
            if( c < flag )break;
            st.insert ( pair < int, int > ( flag, it->first));
            flag += b;
        }
    }
    b = 0;
    multiset < pair < int, int > > ::iterator it =st.begin();
    while( !st.empty() )
    {
        printf("%d\n",it->second);
        b++;
        st.erase( st.begin() );
        it = st.begin();
        if( b == a )break;
    }
    return 0;
}
