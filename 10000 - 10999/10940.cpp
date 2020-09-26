#include<bits/stdc++.h>
using namespace std;
int card_value[500009];
void precal();
int main()
{
    int n;
    precal();
    while( scanf("%d",&n) == 1 && n != 0)
    {
        printf("%d\n",card_value[n]);
    }
    return 0;
}
void precal()
{
    card_value [ 1 ] = 1;
    card_value [ 2 ] = 2;
    card_value [ 3 ] = 2;
    card_value [ 4 ] = 4;
    int ff = 2;
    for ( int i = 5; i <= 500000; i++ )
    {
        if( ff == i)
        {
            card_value [ i ] = ff;
            ff = 2;
        }
        else
        {
            card_value [ i ] = ff;
            ff+=2;
        }
    }
}


/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n != 0 )
    {
        deque < int > dq;
        if(n == 1 )
        {
            printf("1\n");
            continue;
        }
        //if( n & 1)n--;
        for( int i = 2; i <= n; i+=2 )
        {
            dq.push_back(i);
        }
        //for(auto it:dq)cout<<it<<" ";
        //cout<<endl;
        //if( n%2==0 )dq.push_front( n );
        int a = 0, f = 0;
        if( n&1 )a = 1;
        //printf("Discarded cards:");
        while( dq.size() != 1 )
        {
            if( f == 0 && a == 0 )
            {
                //printf(" %d",dq.front());
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
                //printf(", %d",dq.front());
                dq.pop_front();
                a = 1;
            }
        }
        //printf("\n");
        printf("%d\n",dq.front());
    }
    return 0;
}*/

