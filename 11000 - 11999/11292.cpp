#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a;
    while ( scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        deque < int > dq,dq2;
        for ( int i = 0; i != n; i++ )
        {
            scanf("%d",&a);
            dq2.push_back ( a );
        }
        for ( int i = 0; i != m; i++ )
        {
            scanf("%d",&a);
            dq.push_back ( a );
        }
        if ( n > m )
        {
            printf("Loowater is doomed!\n");
            continue;
        }
        sort(dq.begin(),dq.end());
        sort(dq2.begin(),dq2.end());
        long long int ans = 0;
        for ( int i = 0; i != n; i++ )
        {
            int a = dq2 [ i ];
            while ( dq.size() && dq.front() < a ){dq.pop_front();}
            if( dq.empty())
            {
                ans = -1;
                break;
            }
            ans+= dq.front();
            dq.pop_front();
        }
        if(ans >= 0 )printf("%lld\n",ans);
        else printf("Loowater is doomed!\n");
    }
    return 0;
}
