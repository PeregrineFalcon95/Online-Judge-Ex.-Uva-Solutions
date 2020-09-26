#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c;
    while(scanf("%d%d%d",&n,&m,&c)==3&&(n!=0||m!=0||c!=0))
    {
        if(c==1)printf("%d\n",((n-7)*(m-7)+1)/2);
        else printf("%d\n",((n-7)*(m-7))/2);
    }
    return 0;
}
