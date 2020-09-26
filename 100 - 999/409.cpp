#include<bits/stdc++.h>
using namespace std;
int n,m,mx,cases;
int main()
{
    while ( scanf("%d%d",&n,&m) == 2 )
    {
        mx =  0;
        string s,s2,s3;
        map < string , int > marker, counter;
        for ( int i = 0; i != n; i++ )
        {
            cin>>s;
            marker [ s ] = 0;
        }
        getchar();
        for ( int i = 0; i != m; i++ )
        {
            getline(cin, s );
            counter [ s ] = 0;
            stringstream ss ( s );
            s2 = "";
            while ( ss>>s2 )
            {
                s3="";
                for ( int k = 0; k != s2.size(); k++ )
                {
                    if ( ( s2 [ k ] >='a' && s2 [ k ] <= 'z' ) || ( s2 [ k ] >= 'A' && s2 [ k ] <= 'Z' ) )
                    {
                        char ch = s2 [ k ];
                        if ( ch >= 'A' && ch <= 'Z' )ch+=32;
                        s3.insert(s3.end(),ch );
                    }
                    else
                    {
                        if ( marker.find(s3) != marker.end() )counter [ s ]++;
                        s3.clear();
                    }
                }
                if ( marker.find(s3) != marker.end() )counter [ s ]++;
            }
            int h = counter [ s ];
            if ( mx < h )mx = h;
        }
        printf("Excuse Set #%d\n",++cases);
        for ( map < string, int > ::iterator it = counter.begin(); it != counter.end(); it++ )
        {
            if ( it->second == mx )
            {
                cout<<it->first<<"\n";
            }
        }
        printf("\n");
    }
    return 0;
}
