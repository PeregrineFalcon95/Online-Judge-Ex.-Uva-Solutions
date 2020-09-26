#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar [ ] = {1,64,729,4096,15625,46656,117649,262144,531441,1000000,1771561,2985984,4826809,7529536,11390625,16777216,24137569,34012224,47045881,64000000,85766121};
    int n;
    while ( scanf("%d",&n ) && n )
    {
        int ff = 0;
        for ( int i = 0; i != 21; i++ )
        {
            if ( ar [ i ] == n )
            {
                ff = 1;
                printf("Special\n");
                break;
            }
        }
        if ( !ff )printf("Ordinary\n");
    }
    return 0;
}
