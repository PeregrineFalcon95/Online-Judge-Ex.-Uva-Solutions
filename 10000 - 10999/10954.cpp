#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        priority_queue < int > pq;
        for(int i=0; i<n; i++)
        {
            int a;
            scanf("%d",&a);
            pq.push(-a);
        }
        if(n==1){printf("%d\n",abs(pq.top()));continue;}
        int sum=0;
        while(pq.size()>1)
        {
            int zz=pq.top();
            pq.pop();
            zz+=pq.top();
            pq.pop();
            sum+=zz;
            pq.push(zz);
        }
        printf("%d\n",abs(sum));
    }
    return 0;
}
