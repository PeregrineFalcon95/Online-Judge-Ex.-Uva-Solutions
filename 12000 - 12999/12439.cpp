#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cases=0,t=0,date1=0,date2=0,year1=0,year2=0;
    scanf("%d",&t);
    string month1,month2;
    cin.ignore();
    while(t--)
    {
        char ch;
        cin>>month1>>date1>>ch>>year1>>month2>>date2>>ch>>year2;
        if(month1!="January"&&month1!="February")year1++;
        if(month2=="January"||(month2=="February"&&date2<=28))year2--;
        int ans=0;
        int a=year1;
        int b=year2;
        while(a<=b)
        {
            if(a%4==0&&a%100!=0&&a%400!=0)ans++;
            if(b%4==0&&b%100!=0&&b%400!=0&&b!=a)ans++;
            if(a==b||(a%400==0&&b%400==0)||a==year2||b==year1)break;
            if(a%400!=0&&a<=year2)a++;
            if(b%400!=0&&b>=year1)b--;
        }
        int mod=(b-a)/400;
        if((year1%400==0||year2%400==0)&&!mod&&year1<=year2)ans++;
        if(mod)ans+=(mod*97)+1;
        printf("Case %d: %d\n",++cases,ans);
    }
    return 0;
}

