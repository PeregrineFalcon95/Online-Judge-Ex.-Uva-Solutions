#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,p;
    while(scanf("%d",&n)==1)
    {
        while(n--)
        {
            p=0;
            scanf("%d",&m);
            int ara[m+1];
            for(int i=1; i<=m; i++)
            {
                char str[15];
                scanf("%s",&str);
                if(strcmp(str,"LEFT")==0)ara[i]=-1;
                else if(strcmp(str,"RIGHT")==0)ara[i]=1;
                else
                {
                    int l;
                    scanf("%s%d",&str,&l);
                    ara[i]=ara[l];
                }
            }
            int ans=0;
            for(int i=1; i<=m; i++)ans+=ara[i];
            printf("%d\n",ans);
        }
    }
    return 0;
}
