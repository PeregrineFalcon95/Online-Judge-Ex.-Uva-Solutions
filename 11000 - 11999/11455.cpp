#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ara[4];
    while(scanf("%d",&n)==1)
    {
        while(n--)
        {
            scanf("%d%d%d%d",&ara[0],&ara[1],&ara[2],&ara[3]);
            //if((a+c)!=(b+d))printf("banana\n");
            sort(ara,ara+4);
            if(ara[0]==ara[1]&&ara[0]==ara[2]&&ara[0]==ara[3])printf("square\n");
            else if((ara[0]==ara[1])&&(ara[2]==ara[3]))printf("rectangle\n");
            else if(ara[0]>=(ara[1]+ara[2]+ara[3])||ara[1]>=(ara[0]+ara[2]+ara[3])||ara[2]>=(ara[0]+ara[1]+ara[3])||ara[3]>=(ara[0]+ara[1]+ara[2]))printf("banana\n");
            else printf("quadrangle\n");
        }
    }
    return 0;
}
