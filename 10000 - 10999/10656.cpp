#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d",&n)==1&&n!=0)
    {
        vector<int>v;
        while(n--)
        {
            scanf("%d",&m);
            v.push_back(m);
        }
        int a=0,b=0;
        for(auto it:v)
        {
            a++;
            if(it!=0)
            {
                if(b!=0)printf(" ");
                b++;
                printf("%d",it);
            }

        }
        if(b==0)printf("0");
        printf("\n");
    }
    return 0;
}
