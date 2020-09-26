#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector < int > input;
    while(scanf("%d",&n)==1)
    {
        input.push_back(n);
    }
    int sz = input.size();
    int compress_array[sz+5];
    memset(compress_array, 0, sizeof compress_array);
    int flag=0;
    map < int, int > mp;
    for(int i = 0; i != sz; i++)
    {
        int x = input[i];
        if(mp.find(x) == mp.end())
        {
            mp[x] = flag++;
        }
        x = mp[x];
        compress_array [ i ] = x;
    }
    int count_array[flag+2];
    memset(count_array, 0, sizeof count_array);
    for( int i = 0; i < sz; i++)
    {
        int x = compress_array[i];
        count_array[x]++;
    }
    for( int i = 0; i < flag; i++)
    {
        int b;
        for(int j = 0; j != sz; j++)
        {
            if(compress_array[j] == i)
            {
                b = j;
                break;
            }
        }
        printf("%d %d\n",input[b],count_array[i]);
    }
    return 0;
}
