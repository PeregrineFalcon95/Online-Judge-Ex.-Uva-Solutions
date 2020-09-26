#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    map < string , string > dic;
    while(getline(cin,s))
    {
        if(s == "")break;
        string english,foreign;
        int f=0;
        stringstream ss(s);
        string token;
        while( ss >> token )
        {
            if( f == 2 )break;
            else if( f == 0 )
            {
                english = token;
                f = 1;
            }
            else if( f == 1 )
            {
                foreign = token;
                f = 2;
            }
        }
        dic [ foreign ] = english;
    }
    while(cin>>s)
    {
        if( dic.find(s) == dic.end()){printf("eh\n");continue;}
        cout<< dic[s] <<"\n";
    }
    return 0;
}
