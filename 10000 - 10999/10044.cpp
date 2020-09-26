#include<bits/stdc++.h>
using namespace std;
#define inf 999999999
int n , m , a , b , c , cases , t , i , j ;
int level [ 10010 ];
bool visited [ 10010 ];
map < string , int > mp;
string s , s2 , x , y ;
vector < int > graph [ 10010 ];
vector < string > v;
vector < int > v2;
queue < int > qu;
void clear_();
void bfs();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while ( t-- )
    {
        clear_();
        cin>>n>>m;
        cin.ignore();
        c = 0;
        while ( n-- )
        {
            getline(cin,y);
            stringstream ss ( y );
            a = 0;
            while ( ss >> x )
            {
                if ( !a )
                {
                    s = x;
                    a = 1;
                }
                else if ( a > 0 )
                {
                    s += " ";
                    s += x;
                    if ( s.back() == ':' )a = -1;
                    else a = 0;
                    s.erase( s.end() - 1);
                    v.push_back( s );
                }
            }
            while ( !v.empty() )
            {
                if ( mp.find( v.back() ) == mp.end() )mp [ v.back() ] = ++c;
                v2.push_back( mp [ v.back() ] );
                v.pop_back();
            }
            a = v2.size();
            for ( i = 0; i != a; i++ )
            {
                for ( j = 0; j != a; j++ )
                {
                    if ( i == j )continue;
                    graph [ v2 [ i ] ].push_back ( v2 [ j ] );
                    graph [ v2 [ j ] ].push_back ( v2 [ i ] );
                }
            }
            v2.clear();
        }
        n = c;
        bfs();
        cout<<"Scenario "<<++cases<<"\n";
        while ( m-- )
        {
            getline(cin,s);
            a = mp [ s ];
            if ( level [ a ] == inf )cout<<s<<" infinity\n";
            else cout<<s<<" "<<level [ a ]<<"\n";
        }
    }
    return 0;
}
void clear_()
{
    mp.clear();
    for ( i = 0; i <= 10000; i++ )
    {
        visited [ i ] = 0;
        graph [ i ].clear();
        level [ i ] = inf;
    }
}
void bfs()
{
     a = mp [ "Erdos, P." ];
     qu.push( a );
     visited [ a ] = 1;
     level [ a ] = 0;
     while ( !qu.empty() )
     {
         a = qu.front();
         qu.pop();
         c = graph [ a ].size();
         for ( i = 0 ; i != c; i++ )
         {
             b = graph [ a ] [ i ];
             if ( !visited [ b ] )
             {
                 visited [ b ] = 1;
                 qu.push( b );
                 level [ b ] = level [ a ] + 1;
             }
         }
     }
}
