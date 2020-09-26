#include<bits/stdc++.h>
using namespace std;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar_unlocked();
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;

}
int a,b,c,t,cases,num,con,source,target;
vector < pair < int, int >  > graph [ 20002 ];
int dijk();
int main()
{
    ios_base::sync_with_stdio(false);
    fastscan(t);
    while ( t-- )
    {
        while(1){fastscan(num);if(num)break;}
        fastscan(con);
        fastscan(source);
        fastscan(target);
        for ( int i = 0; i <=num; i++ )graph[i].clear();
        for ( int i = 0; i != con; i++ )
        {
            fastscan(a);
            fastscan(b);
            fastscan(c);
            graph [ a ].push_back( pair < int , int > ( c ,b ) );
            graph [ b ].push_back( pair < int , int > ( c ,a ) );
        }
        int ans = -1;
        if(con)ans = dijk();
        if( ans == -1 )printf("Case #%d: unreachable\n",++cases);
        else printf("Case #%d: %d\n",++cases,ans);
    }
    return 0;
}
int dijk()
{
    int dis [ num ];
    memset( dis, -1 ,sizeof dis );
    priority_queue < pair < int, int > > pq;
    pq.push( pair < int , int > ( 0 , source) );
    dis [ source ] = 0;
    while ( !pq.empty() )
    {
        int front_value = pq.top().first;
        int front_node = pq.top().second;
        front_value*= ( -1 );
        pq.pop();
        int sz = graph [ front_node ].size();
        for ( int i = 0; i != sz; i++ )
        {
            int value = graph [ front_node ][ i ].first;
            int node = graph[ front_node ][ i ].second;
            if ( dis [ node ] >=0 && ( front_value + value ) < dis [ node ] )
            {
                int aa = (front_value+value);
                dis[ node ] = aa;
                aa = - aa;
                pq.push( pair < int, int > ( aa, node ));
            }
            else if( dis [ node ] == -1 )
            {
                int aa = (front_value+value);
                dis[ node ] = aa;
                aa = - aa;
                pq.push( pair < int, int > ( aa, node ));
            }
         }
    }
    return dis [ target ];
}
