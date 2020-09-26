#include<bits/stdc++.h>
using namespace std;
int main()
{
    double l,w,d,k;
    int n,m=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf%lf%lf%lf",&l,&w,&d,&k);
        if(((l<=56&&w<=45&&d<=25)||l+w+d<=125)&&k<=7){m++;printf("1\n");}
        else printf("0\n");
    }
    printf("%d\n",m);
    return 0;
}

