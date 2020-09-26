#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[250];
    set <string> st;
    while(gets(str))
    {
        string temp="";
        for(int i=0; str[i]; i++)
        {
            if(isalpha(str[i]))temp+=tolower(str[i]);
            else temp+=" ";
        }
        stringstream sin(temp);
        string token="";
        while(sin>>token)
        {
            st.insert(token);
        }
    }
    for(set<string>::iterator i=st.begin(); i!=st.end(); i++)cout<<*i<<endl;
    return 0;
}
