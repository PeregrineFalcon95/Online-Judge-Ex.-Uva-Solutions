#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        string s;
        cin>>s;
        int ans=0,c=0;
        for(int i=0; i<m; i++)
        {
            if(s[i-1]=='#'&&s[i]=='#'&&c){ans++;c=0;}
            else if(s[i]=='.')c++;
            else if(s[i]=='#'&&c<3&&c){if(i<m-1){if(s[i+1]!='#')c++;}else c++;}
            if(c==3){ans++;c=0;}
        }
        if(c)ans++;
        printf("Case %d: %d\n",++t,ans);
    }
    return 0;
}
