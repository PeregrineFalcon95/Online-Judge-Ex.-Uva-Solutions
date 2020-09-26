#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cases=0,sum=0,a,n;
    while(scanf("%d",&n)==1&&n>=0)
    {
        queue<int>qu;
        for(int i=0; i<12; i++){scanf("%d",&a);qu.push(a);}
        sum=n;
        printf("Case %d:\n",++cases);
        for(int i=0; i<12; i++)
        {
            scanf("%d",&a);
            if(a<=sum){printf("No problem! :D\n");sum-=a;}
            else printf("No problem. :(\n");
            sum+=qu.front();
            qu.pop();
        }
    }
    return 0;
}

