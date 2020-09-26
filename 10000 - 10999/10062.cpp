#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int x=0;
    while(getline(cin,s))
    {
        if(x)printf("\n");
        x++;
        int sz=s.size();
        map < int, int > mp;
        for(int i=0; i!=sz; i++)
        {
            int a=s[i];
            mp[a]++;
        }
        multimap < int, int > ans;
        for(map < int, int >::iterator it=mp.begin(); it!=mp.end(); it++)
        {
            ans.insert(pair < int, int > (it->second,it->first));
        }
        deque < pair < int ,int > > sorted;
        int a=0;
        for(multimap < int,int >::iterator it=ans.begin(); it!=ans.end(); it++)
        {
            if(a!=it->first)
            {
                while(!sorted.empty())
                {
                    printf("%d %d\n",sorted.back().second,sorted.back().first);
                    sorted.pop_back();
                }
            }
            a=it->first;
            sorted.push_back(pair < int, int > (it->first, it->second) );
        }
        while(!sorted.empty())
        {
            printf("%d %d\n",sorted.back().second,sorted.back().first);
            sorted.pop_back();
        }
    }
    return 0;
}
