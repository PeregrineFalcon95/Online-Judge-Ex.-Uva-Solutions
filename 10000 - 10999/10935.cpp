#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n != 0 )
    {
        deque < int > dq;
        for( int i = 1; i <= n; i++ )
        {
            dq.push_back(i);
        }
        int a = 0, f = 0;
        printf("Discarded cards:");
        while( dq.size() != 1 )
        {
            if( f == 0 && a == 0 )
            {
                printf(" %d",dq.front());
                dq.pop_front();
                a = 1;
                f = 1;
            }
            else if( a == 1 )
            {
                int b = dq.front();
                dq.pop_front();
                dq.push_back( b );
                a = 0;
            }
            else if( !a )
            {
                printf(", %d",dq.front());
                dq.pop_front();
                a = 1;
            }
        }
        printf("\n");
        printf("Remaining card: %d\n",dq.front());
    }
    return 0;
}
