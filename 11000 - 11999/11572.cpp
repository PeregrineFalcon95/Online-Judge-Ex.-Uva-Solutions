#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m,ff=0;
        scanf("%d",&m);
        map < int, deque < int > > index;
        deque < int > dq;
        for( int i = 0; i != m; i++ )
        {
            int a;
            scanf("%d",&a);
            dq.push_back( a );
            index [ a ].push_back( i );
        }
        int mx = 0, flag = 0;
        for ( int i = 0; i != m; i++)
        {
            int a = dq [ i ];
            if( index [ a ].front() == i)
            {
                if( mx < ((i - flag) + 1) )
                {
                    mx = (i - flag) + 1;
                }
            }
            else if( index [ a ].front() < i )
            {
                if(flag <= index [ a ].front())
                {
                    if( mx < (i - flag) )mx = (i - flag);
                    flag = index[ a ].front() + 1;
                }
                else if( mx < (i - flag)+1 )mx = (i - flag)+1;
                index [ a ].pop_front();
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
