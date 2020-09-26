#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t=0,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        char ch;
        int a=0,b=0;
        for(int i=1; i<=m; i++)
        {
            cin.ignore();
            scanf("%c",&ch);
            if(ch=='W'){a=0;}
            else a++;
            if(a>=3&&(!b))b=i;
        }
        if(b)printf("Case %d: %d\n",++t,b);
        else printf("Case %d: Yay! Mighty Rafa persists!\n",++t);
    }
    return 0;
}
