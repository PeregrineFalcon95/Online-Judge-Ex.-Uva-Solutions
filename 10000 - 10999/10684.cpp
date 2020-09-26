#include<bits/stdc++.h>
using namespace std;
int i , n , bet , sum , mx;
int main()
{
    while(scanf("%d",&n)==1&&n!=0)
    {
        sum = mx = 0;
        for( i = 0 ; i < n ; i++)
        {
            scanf("%d",&bet);
            sum += bet;
            if( sum > mx )mx=sum;
            if( sum < 0 )sum=0;
        }
        if( !mx )printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n",mx);
    }
    return 0;
}


