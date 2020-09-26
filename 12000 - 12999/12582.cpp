#include<bits/stdc++.h>
using namespace std;
int t , n , cases , m;
string s;
map < char , int > mp;
map < char , int > ::iterator it;
void rec ( int lo , int hi );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        cin>>s;
        mp.clear();
        n = s.size();
        rec ( 0 , n - 1 );
        mp [ s [ 0 ] ]--;
        printf("Case %d\n",++cases);
        for ( it = mp.begin(); it != mp.end(); it++ )printf("%c = %d\n",it->first,it->second);
    }
    return 0;
}
void rec ( int lo , int hi )
{
    if ( hi - lo == 1 )
    {
        mp [ s [ hi ] ] = 1;
        return;
    }
    int y , x , o_o = 0 ;
    for ( int i = lo + 1 ; i < hi ; )
    {
        char ch = s [ i ];
        x = i;
        i++;
        while ( s [ i ] != ch )i++;
        y = i;
        o_o++;
        rec ( x , y );
        i++;
    }
    mp [ s [ lo ] ] = o_o + 1;
}





/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cases = 0;
    scanf("%d",&n);
    while( n-- )
    {
        char trail [ 100 ];
        scanf("%s",&trail);
        int sz = strlen(trail);
        map < char, int > mapping;
        for (int i = 0; i != sz; i++ )mapping [ trail [ i ] ] = 0;
        while ( 1 )
        {
            for ( int i = 0; i != sz; i++ )
            {
                if ( trail [ i ] != '!' )
                {
                    char father = trail [ i ];
                    for ( int j = i+1; j != sz;  )
                    {
                        if ( trail [ j ] == father )
                        {
                            trail[ j ] = '!';
                            break;
                        }
                        char check = trail [ j ];
                        mapping [ check ]++;
                        for ( int k = j+1; k !=sz; k++ )
                        {
                            if ( check == trail [ k ] )
                            {
                                j = k+1;
                                mapping [ father ]++;
                                break;
                            }
                        }
                    }
                }
                trail [ i ] = '!';
            }
            int o_o = 0;
            for ( int i = 0; i != sz; i++ )
            {
                if ( trail [ i ] != '!' )o_o++;
            }
            if ( !o_o )break;
        }
        printf("Case %d\n",++cases);
        for ( map < char, int > ::iterator it = mapping.begin(); it != mapping.end(); it++ )
        {
            if ( it->second )printf("%c = %d\n",it->first,it->second);
        }
    }
    return 0;
}
*/