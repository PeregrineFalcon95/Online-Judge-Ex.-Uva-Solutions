#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,cases=0;
    while(scanf("%d",&n)==1)
    {
        vector < string > nodes;
        string a,b;
        for(int i=0; i<n; i++){cin>>a;nodes.push_back(a);}
        map < string , vector < string > > Graph;
        map < string, int > degree;
        scanf("%d",&m);
        for(int i=0; i<m; i++){cin>>a>>b;Graph[a].push_back(b);degree[b]++;}
        vector < string > sorted;
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                a=nodes[i];
                if(degree[a]==0)
                {
                    sorted.push_back(a);
                    degree[a]=-1;
                    int sz=Graph[a].size();
                    for(int j=0; j<sz; j++)
                    {
                        b=Graph[a][j];
                        degree[b]--;
                    }
                    degree[a]=-1;
                    break;
                }
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",++cases);
        for(auto it: sorted)cout<<" "<<it;
        printf(".\n\n");
    }
    return 0;
}

