#include<bits/stdc++.h>
using namespace std;
char str[32];
int n,total;
map<string,int> mp;
map<string,int>::iterator it;
int main()
{
    int n;
    scanf("%d",&n);
    gets(str);
    gets(str);
    while(n--)
    {
        mp.clear();
        total=0;
        while(gets(str)&&str[0])
        {
            ++mp[str];
            ++total;
        }
        
        for(it=mp.begin(); it!=mp.end(); it++)
        {
            cout<<it->first<<" ";
            printf("%.4lf\n",(double)(100*it->second)/total);
        }
        if(n)putchar('\n');
    }
    return 0;
}
