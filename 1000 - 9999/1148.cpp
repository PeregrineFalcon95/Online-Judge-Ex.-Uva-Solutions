#include<bits/stdc++.h>
using namespace std;
void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar_unlocked();
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    int n,m;
    fastscan( n );
    m = n-1;
    while( n-- )
    {
        if ( n != m )printf("\n");
        int num;
        while(1){fastscan(num);if(num)break;}
        vector < int > graph[ num+2 ];
        for ( int i = 0; i != num; i++ )
        {
            int father, child, o_o;
            fastscan(father);
            fastscan(o_o);
            for ( int j = 0; j != o_o; j++  )
            {
                fastscan(child);
                graph [ father ].push_back( child );
            }
        }
        int source, target;
        fastscan(source);
        fastscan(target);
        bool visited [ num + 2 ];
        memset( visited, 0, sizeof visited );
        int level [ num+2 ];
        memset( level , 0 ,sizeof level );
        queue < int > qu;
        qu.push( source );
        visited [ source ] = 1;
        while ( !qu.empty() )
        {
            int front_ = qu.front();
            int m_m = 0;
            qu.pop();
            int sz = graph [ front_ ].size();
            for ( int i = 0; i != sz; i++ )
            {
                int w_w = graph [ front_ ] [ i ];
                if ( !visited [ w_w ] )
                {
                    visited [ w_w ] = 1;
                    qu.push(w_w);
                    level [ w_w ] = level [ front_ ]+1;
                    if ( w_w == target )
                    {
                        m_m = 1;
                        break;
                    }
                }
            }
            if ( m_m )break;
        }
        printf("%d %d %d\n",source,target,level [ target ]-1);
    }
    return 0;
}
