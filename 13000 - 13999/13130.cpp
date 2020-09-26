#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[5];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]);
        int f=0;
        for(int i=0; i<4; i++){if(a[i]+1!=a[i+1]){f=1;break;}}
        if(f==1)printf("N\n");
        else printf("Y\n");
    }
    return 0;
}

