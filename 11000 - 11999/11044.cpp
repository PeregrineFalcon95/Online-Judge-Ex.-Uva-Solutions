#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,p;
    scanf("%d",&p);
    while(p--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",(n/3)*(m/3));
    }
    return 0;
}

