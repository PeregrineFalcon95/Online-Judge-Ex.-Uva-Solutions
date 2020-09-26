#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int a,b,c,i,j,n,ar[10];
    while(sc("%d",&n)==1)
    {
        while(n--)
        {
            sc("%d",&a);
            for(i=0; i<10; i++)ar[i]=0;
            for(i=a; i>0; i--)
            {
                c=i;
                while(c>0)
                {
                    b=c%10;
                    c/=10;
                    ar[b]++;
                }
            }
            for(i=0; i<10; i++)
            {
                pi("%d",ar[i]);
                if(i<9)pi(" ");
            }
            pi("\n");
        }
    }
    return 0;
}
