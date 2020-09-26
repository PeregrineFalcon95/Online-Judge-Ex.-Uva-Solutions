#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,t=0;
    scanf("%d",&m);
    while(m--)
    {
        int ans=0;
        for(int i=0; i<13; i++)
        {
            int a;
            scanf("%d",&a);
            if(!ans){if(!a)ans=1;}
        }
        if(ans)printf("Set #%d: No\n",++t);
        else printf("Set #%d: Yes\n",++t);
    }
    return 0;
}
