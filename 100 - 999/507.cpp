#include<bits/stdc++.h>
using namespace std;
#define mxs 20010
int n , m ,a , b , c , t , cases , i ,start , finish , sum , mx , st , fi , len , ar;
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        st = fi = start = finish = 1;
        sum = mx = len = 0;
        scanf("%d",&n);
        for ( i = 1; i < n; i++ )
        {
            scanf("%d",&ar );
            sum += ar ;
            if ( sum < 0 )
            {
                sum = 0;
                st = fi = i + 1;
            }
            else if ( sum == mx )
            {
                fi = i;
                if ( fi - st == finish - start )continue;
                start = st;
                finish = fi;
            }
            else if ( sum > mx )
            {
                mx = sum;
                start = st;
                finish = i;
                fi = i;
            }
        }
        if (  finish == 1 && start == 1 && mx == 0  )printf("Route %d has no nice parts\n",++cases);
        else printf("The nicest part of route %d is between stops %d and %d\n",++cases,start,finish+1);
    }
    return 0;
}
