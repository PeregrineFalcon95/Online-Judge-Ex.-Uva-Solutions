#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, cases = 0,a,b;
    while(scanf("%d",&n) == 1 && n )
    {
        printf("Scenario #%d\n",++cases);
        map < int, int > tress;
        for ( int i = 1; i <= n; i++ )
        {
            scanf("%d",&a);
            for ( int j = 0; j != a; j++ )
            {
                scanf("%d",&b);
                tress [ b ] = i;
            }
        }
        string s;
        map < int, queue< int > > mp_qu;
        int in_marker = 0, out_marker = 0;
        while( cin >> s)
        {
            if( s == "STOP" )break;
            else if ( s == "DEQUEUE" )
            {
                if( mp_qu.empty() )continue;
                else if ( mp_qu [ out_marker ].empty() )
                {
                    mp_qu.erase(out_marker);
                    if( mp_qu [ out_marker +1 ].empty() )continue;
                    else
                    {
                        printf("%d\n",mp_qu [ ++out_marker ].front());
                        mp_qu[ out_marker ].pop();
                    }
                }
                else
                {
                    printf("%d\n",mp_qu[ out_marker ].front());
                    mp_qu[ out_marker ].pop();
                }
            }
            else if ( s == "ENQUEUE")
            {
                int aa;
                scanf("%d",&aa);
                int bb = tress[ aa ];
                int cc = -1;
                for ( map < int,queue < int > >::iterator it = mp_qu.begin(); it != mp_qu.end(); it++ )
                {
                    if ( tress[ it->second.front() ] == bb )
                    {
                        cc = it->first;
                        break;
                    }
                }
                if(cc >= 0)mp_qu[ cc ].push( aa );
                if ( cc == -1 )
                {
                    mp_qu [ ++in_marker ].push( aa );
                }
            }
        }
        printf("\n");
    }
    return 0;
}
