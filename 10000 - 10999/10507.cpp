#include<bits/stdc++.h>
using namespace std;
char a , b , c , d , e;
int n , m , x , y , z , i , j , k , lol;
int marker [ 30 ] , visited [ 30 ];
vector < int > graph [ 30 ];
map < string , bool > mp;
char ch [ 3 ] , ch2 [ 3 ];
vector < int > v;
int main()
{
    //freopen ("output.txt","w",stdout);
    while ( scanf("%d",&n) == 1 )
    {
        mp.clear();
        for ( i = 0; i <= 26; i++ )
        {
            graph [ i ].clear();
            marker [ i ] = 0;
            visited [ i ] = 1;
        }
        scanf("%d",&m);
        scanf(" %c%c%c",&a,&b,&c);
        while ( m-- )
        {
            scanf(" %c%c",&d,&e);
            visited [ d - 64 ] = visited [ e - 64 ] = 0;
            ch [ 0 ] = d;
            ch [ 1 ] = e;
            ch [ 3 ]= 0;
            ch2 [ 0 ] = e;
            ch2 [ 1 ] = d;
            ch2 [ 3 ]= 0;
            if ( !mp.size() || ( mp.find( ch ) == mp.end() && mp.find( ch2 ) == mp.end() ) )
            {
                graph [ d - 64 ].push_back ( e - 64 );
                graph [ e - 64 ].push_back ( d - 64 );
                mp [ ch ] = 1;
                mp [ ch2 ] = 1;
            }
        }
        visited [ b - 64 ] = visited [ c - 64 ] = visited [ a - 64 ] = 1;
        int ans = 0;
        for ( i = 1; i <= 26; i++ )
        {
            v.clear();
            for ( j = 1; j <= 26; j++ )
            {
                if ( !visited [ j ] )
                {
                    z = graph [ j ].size();
                    lol = 0;
                    for ( k = 0; k != z; k++ )
                    {
                        if ( visited [ graph [ j ] [ k ] ] )lol++;
                    }
                    if ( lol >= 3 )v.push_back( j );
                }
            }
            while ( !v.empty() )
            {
                marker [ v.back() ] = i;
                ans = max ( ans , marker [ v.back() ] );
                visited [ v.back() ] = 1;
                v.pop_back();
            }
        }
        lol = 0;
        for ( i = 1; i <= 26; i++ )if ( !visited [ i ] )lol++;
        if ( lol || ( !ans && n > 3 ) )printf("THIS BRAIN NEVER WAKES UP\n");
        else printf("WAKE UP IN, %d, YEARS\n",ans);
    }
    return 0;
}
