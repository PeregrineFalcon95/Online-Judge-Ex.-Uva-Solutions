#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,ans,i_i;
    map < char, int > con;
    while ( scanf("%d",&n)==1 && n != -1 )
    {
        con.clear();
        string s,s2;
        cin>>s;
        cin>>s2;
        for ( int i = 0; i != s.size(); i++ )
        {
            con [ s [ i ] ] ++;
        }
        ans = 0;
        set < char > o_o;
        for ( int i = 0; i != s2.size(); i++ )
        {
            if ( con.find( s2 [ i ] ) != con.end() )
            {
                con [ s2 [ i ] ] = 0;
            }
            else
            {
                o_o.insert( s2 [ i ] );
                if ( o_o.size() == 7  )break;
            }
        }
        i_i = 0;
        for ( map < char, int > ::iterator it = con.begin(); it != con.end(); it++ )
        {
            if ( it->second != 0 )
            {
                i_i = 1;
                break;
            }
        }
        if ( !i_i )printf("Round %d\nYou win.\n",n);
        else if ( o_o.size() >= 7 )printf("Round %d\nYou lose.\n",n);
        else printf("Round %d\nYou chickened out.\n",n);
    }
    return 0;
}
