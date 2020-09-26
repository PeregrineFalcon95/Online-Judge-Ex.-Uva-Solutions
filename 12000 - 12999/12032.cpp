#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        int ar[m+1],mx=-1;
        ar[0]=0;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&ar[i]);
            int a=ar[i]-ar[i-1];
            if(a>mx)mx=a;
        }
        mx=-1;
        for(int i=1; i<=m; i++){if(mx<ar[i]-ar[i-1])mx=ar[i]-ar[i-1];}
        int z=mx;
        for(int i=1; i<=m; i++)
        {
            int a=ar[i]-ar[i-1];
            if(a>mx){z++;break;}
            else if(a==mx)mx--;
        }
        printf("Case %d: %d\n",++t,z);
    }
    return 0;
}
