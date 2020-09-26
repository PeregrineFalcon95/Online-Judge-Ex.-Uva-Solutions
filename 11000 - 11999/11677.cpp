#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sleep,wake,h1,h2,m1,m2;
    while(scanf("%d%d%d%d",&h1,&m1,&h2,&m2)==4&&(h1!=0||h2!=0||m1!=0||m2!=0))
    {
        sleep=h1*60+m1;
        wake=h2*60+m2;
        if(sleep<=wake)printf("%d\n",wake-sleep);
        else
        {
            printf("%d\n",(1440-sleep)+wake);
        }
    }
    return 0;
}
