#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cases=0,r,c,a,b,mx;
    scanf("%d",&t);
    while ( t-- )
    {
        map < char, int > mp;
        scanf("%d%d%d%d",&r,&c,&a,&b);
        mx = 0;
        for ( int i = 0; i != r; i++ )
        {
            char s[ 25 ];
            scanf("%s",&s);
            for ( int j = 0; j != c; j++ )
            {
                mp [ s [ j ] ]++;
                if ( mp [ s [ j ] ] > mx )
                {
                    mx = mp [ s [ j ] ];
                }
            }
        }
        int ans = 0;
        for ( map < char, int > ::iterator it = mp.begin(); it != mp.end(); it++ )
        {
            if ( it->second == mx )
            {
                ans += ( mx*a );
            }
            else
            {
                ans+= ( it->second * b);
            }
        }
        printf("Case %d: %d\n",++cases,ans);
    }
    return 0;
}
