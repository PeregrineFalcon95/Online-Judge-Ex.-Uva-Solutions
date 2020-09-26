#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int t;
    while(sc("%d",&t)==1)
    {
        while(t--)
        {
            int n,m;
            queue <pair<int,int>>q;
            priority_queue <int> pq;
            sc("%d%d",&n,&m);
            for(int i=0; i<n; i++)
            {
                int a;
                sc("%d",&a);
                q.push(make_pair(a,i));
                pq.push(a);
            }
            int ans(0);
            while(!q.empty())
            {
                if(q.front().first==pq.top())
                {
                    ans++;
                    if(q.front().second==m)
                        break;
                    q.pop();
                    pq.pop();
                }
                else
                {
                    q.push(q.front());
                    q.pop();
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

