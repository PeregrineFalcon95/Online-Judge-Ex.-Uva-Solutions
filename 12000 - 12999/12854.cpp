#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e;
    while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)==5)
    {
        int ans=0,ara[5];
        ara[0]=a,ara[1]=b,ara[2]=c,ara[3]=d,ara[4]=e;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        ara[0]+=a,ara[1]+=b,ara[2]+=c,ara[3]+=d,ara[4]+=e;
        for(int i=0; i<5; i++){if(ara[i]!=1){ans=1;break;}}
        if(ans)printf("N\n");
        else printf("Y\n");
    }
    return 0;
}
