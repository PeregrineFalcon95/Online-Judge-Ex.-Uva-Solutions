#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e;
    while(scanf("%d%d",&a,&b)==2&&(a!=-1&&b!=-1))
    {
        if(a==0)a=100;
        if(b==0)b=100;
        c=a-b;
        if(c<0)c*=-1;
        if(c>50)
        {
            if(a>b)
            {
                b+=100;
                c=b-a;
            }
            else
            {
                a+=100;
                c=a-b;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
