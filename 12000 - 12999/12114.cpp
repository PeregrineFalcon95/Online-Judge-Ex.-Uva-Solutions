#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,cases=0;
    while ( scanf("%d%d",&a,&b)==2 && (a || b) )
    {
        if ( a == 1 )printf("Case %d: :-\\\n",++cases);
        else if ( a > b)printf("Case %d: :-(\n",++cases);
        else printf("Case %d: :-|\n",++cases);
    }
    return 0;
}
