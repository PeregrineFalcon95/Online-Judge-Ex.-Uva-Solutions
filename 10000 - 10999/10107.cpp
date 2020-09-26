#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
#define lld long long int
int main()
{
    vector <lld> v;
    lld a,c=0;
    while(cin>>a)
    {
        v.push_back(a);
        sort(v.begin(),v.end());
        if(c%2==0)
        {
            int mid=c/2;
            cout<<v[mid]<<endl;
        }
        else
        {
            int mid=c/2;
            int mi=mid+1;
            cout<<(v[mid]+v[mi])/2<<endl;
        }
        ++c;
    }
    return 0;
}
