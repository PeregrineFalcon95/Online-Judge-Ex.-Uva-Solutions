#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        cin.ignore();
        vector < string > sen;
        string a;
        for(int i=0; i<n; i++){getline(cin,a);sen.push_back(a);}
        map < char, int > mp;
        char ch;
        for(int i=0; i<n; i++)
        {
            int sz=sen[i].size();
            for(int j=0; j!=sz; j++)
            {
                if((sen[i][j]>=65&&sen[i][j]<=90)||(sen[i][j]>=97&&sen[i][j]<=122)){ch=toupper(sen[i][j]);if(mp.find(ch)==mp.end())mp[ch]=1;else mp[ch]++;}
            }
        }
        map < char, int > ::iterator it,k;
        while(!mp.empty())
        {
            int mx=0;
            for(it=mp.begin(); it!=mp.end(); it++)
            {
                if(it->second>mx){mx=it->second;ch=it->first;k=it;}
            }
            cout<<k->first<<" "<<k->second<<endl;
            mp.erase(k);
        }
    }
    return 0;
}

