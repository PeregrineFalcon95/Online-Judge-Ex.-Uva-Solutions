#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cases = 0;
    scanf("%d",&t);
    while ( t-- )
    {
        int n,m;
        char names [ 500+2 ];
        scanf("%d%d%c%s",&n,&m,&names[0],&names);
        int ans =0;
        for( int i = 0; i != n; i++ )
        {
            int w_w = i-m;
            if ( w_w < 0)w_w = 0;
            for ( int j = w_w; j != i; j++ )
            {
                if ( names[ i ] == names[ j ])
                {
                    ans++;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",++cases,ans);
    }
    return 0;
}
