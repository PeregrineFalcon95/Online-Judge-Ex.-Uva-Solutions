#include<bits/stdc++.h>
using namespace std;
int value[61];
void power_of_3()
{
    value[1]=1;
    for(int i=2; i<=60; i++)value[i]=pow(i,3);
}
int main()
{
    int n;
    power_of_3();
    while(scanf("%d",&n)==1&&n!=0)
    {
        int a=0,b,c;
        for(int i=60; i>=2; i--)
        {
            for(int j=1; j<=60; j++)
            {
                if(n==(value[i]-value[j]))
                {
                    a=1;
                    b=i;
                    c=j;
                    break;
                }
            }
        }
        if(a==1)printf("%d %d\n",b,c);
        else printf("No solution\n");
    }
    return 0;
}
