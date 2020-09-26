#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cases=0;
    scanf("%d",&t);
    while ( t-- )
    {
        int date,year,month,target;
        scanf("%d%d%d%d",&date,&month,&year,&target);
        if ( date == 29 && month == 2 )
        {
            int ans = 0;
            year+=4;
            while ( year <= target )
            {
                if ( (year%4==0 && year%100 != 0) || year %400 == 0 )ans++;
                year+=4;
            }
            printf("Case %d: %d\n",++cases,ans);
        }
        else printf("Case %d: %d\n",++cases,target-year);
    }
    return 0;
}
