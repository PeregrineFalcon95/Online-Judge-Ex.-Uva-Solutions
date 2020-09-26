#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    string name,country;
    map < string, set < string > > mp;
    for ( int i = 0; i != n; i++ )
    {
        cin>>country;
        getline(cin,name);

        mp [ country ].insert( name );
    }
    for ( map < string, set < string > > ::iterator it = mp.begin(); it != mp.end(); it++ )
    {
        cout<<it->first<<" "<<it->second.size()<<endl;
    }
    return 0;
}
