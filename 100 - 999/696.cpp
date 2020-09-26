#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n)==2 &&(n!=0||m!=0))
    {
        int ans=0;
        if(n==1 || m==1)ans=max(n,m);
        else if(n==2 && m==2)ans=4;
        else if(n==2 || m==2)
        {
            if(n&1 || m&1)ans=(n*m)/2+1;
            else
            {
                int a=0;
                int b=max(n,m);
                int c=4;
                ans=4;
                while(c<b)
                {
                    if(!a)
                    {
                        ans+=4;
                        a=1;
                    }
                    else
                    {
                        ans+=0;
                        a=0;
                    }
                    c+=2;
                }
            }
        }
        else
        {
            int a=n*m;
            if(a&1)ans=(n*m)/2+1;
            else ans=(n*m)/2;
        }
        printf("%d knights may be placed on a %d row %d column board.\n",ans,m,n);
    }
    return 0;
}
