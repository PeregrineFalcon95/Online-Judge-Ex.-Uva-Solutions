#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    char str[10];
    int t;
    while(sc("%d",&t)==1)
    {
        while(t--)
        {
            sc("%s",&str);
            int a=((str[0]-65)*26*26)+((str[1]-65)*26)+((str[2]-65)*1);
            int b=0;
            for(int i=4;i<8;i++)
            {
                b*=10;
                b+=str[i]-48;
            }
            if(b-a<=100&&a-b<=100)pi("nice\n");
            else pi("not nice\n");
        }
    }
    return 0;
}
