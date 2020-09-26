#include<bits/stdc++.h>
using namespace std;
long long int ans[101];
void answer()
{
    ans[1]=1;
    for(int i=2; i<=100; i++)ans[i]=ans[i-1]+i*i;
}
int main()
{
    answer();
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        printf("%lld\n",ans[n]);
    }
    return 0;
}
