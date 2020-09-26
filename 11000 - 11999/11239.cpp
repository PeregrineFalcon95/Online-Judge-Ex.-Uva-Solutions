#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,s2;
    while ( 1 )
    {
        map < string, pair < int, string > > marker;
        map < string, int > project;
        while ( getline(cin,s) )
        {
            int a = 0;
            if ( s [ 0 ] == '1' )break;
            if ( s [ 0 ] == '0' )return 0;
            if ( s [ 0 ] >= 'A' && s [ 0 ] <= 'Z' )
            {
                project [ s ] = 0;
                while ( getline( cin,s2 ) )
                {
                    if ( s2 [ 0 ] == '1' )
                    {
                        a = 1;
                        break;
                    }
                    if ( s2 [ 0 ] >= 'A' && s2 [ 0 ] <= 'Z' )
                    {
                        s = s2;
                        project [ s ] = 0;
                        continue;
                    }
                    if ( marker.find( s2 ) == marker.end() )
                    {
                        marker [ s2 ].first = 1;
                        marker [ s2 ].second = s;
                    }
                    else if ( marker [ s2 ].second != s )
                    {
                        marker [ s2 ].first = 2;
                    }
                }
            }
            if ( a )break;
        }
        map < string, pair < int, string > > ::iterator it;
        for ( it = marker.begin(); it != marker.end(); it++ )
        {
            if ( it->second.first == 1 )
            {
                project [ it->second.second ]++;
            }
        }
        multimap < int, string > mp;
        for ( map < string, int >::iterator itt = project.begin(); itt != project.end(); itt++ )
        {
            mp.insert( make_pair ( itt->second, itt->first ) );
        }
        multimap < int, string > ::iterator tut;
        tut = mp.end();
        tut--;
        deque < pair < string, int > > ans;
        deque < pair < string, int > > dq;
        for ( ; ; tut-- )
        {
            if ( dq.size() && tut->first == dq.back().second )
            {
                dq.push_back( pair < string, int > ( tut->second, tut->first ) );
            }
            else
            {
                while( !dq.empty() )
                {
                    ans.push_back( pair < string, int > ( dq.back().first, dq.back().second ) );
                    dq.pop_back();
                }
                dq.push_back( pair < string, int > ( tut->second, tut->first ) );
            }
            if( tut == mp.begin())break;
        }
        while( !dq.empty() )
        {
            ans.push_back( pair < string, int > ( dq.back().first, dq.back().second ) );
            dq.pop_back();
        }
        int sz = ans.size();
        for ( int i = 0; i != sz; i++ )
        {
            cout<<ans [ i ].first<<" "<<ans [ i ].second<<"\n";
        }
    }
    return 0;
}
