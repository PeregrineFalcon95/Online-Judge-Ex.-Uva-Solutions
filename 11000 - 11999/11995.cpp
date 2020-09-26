#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) == 1 )
    {
        queue < int > q_u;
        priority_queue < int > p_q;
        stack < int > s_t;
        int a,b;
        int sss = 0, ppp = 0, qqq = 0;
        for( int i = 0; i < n; i++ )
        {
            scanf("%d%d",&a,&b);
            if( a == 1 )
            {
                if( !qqq )q_u.push( b );
                if( !sss )s_t.push( b );
                if( !ppp )p_q.push( b );
            }
            else if( a == 2 )
            {
                if( !sss && (s_t.empty() || (s_t.top() != b )) )sss = 1;
                if( !ppp && (p_q.empty() || (p_q.top() != b )) )ppp = 1;
                if( !qqq && (q_u.empty() || (q_u.front() != b )) )qqq = 1;
                if( !sss )s_t.pop();
                if( !ppp )p_q.pop();
                if( !qqq )q_u.pop();
            }
        }
        if( !sss && qqq && ppp)printf("stack\n");
        else if( !qqq && ppp && sss)printf("queue\n");
        else if( !ppp && qqq && sss)printf("priority queue\n");
        else if((sss+ppp+qqq == 0) || (sss+qqq+ppp == 1))printf("not sure\n");
        else printf("impossible\n");
    }
    return 0;
}

