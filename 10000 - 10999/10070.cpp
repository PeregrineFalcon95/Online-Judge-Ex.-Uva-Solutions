#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int d4,d100,d400,d15,d55,le,hu,bu,i,j,l,c=0;
    char str[110000];
    while(sc("%s",&str)!=EOF)
    {
        if(c)pi("\n");
        c++;
        l=strlen(str);
        d4=d100=d400=d15=d55=0;
        for(i=0; i<l; i++)
        {
            d4=(d4*10+str[i]-'0')%4;
            d100=(d100*10+str[i]-'0')%100;
            d400=(d400*10+str[i]-'0')%400;
            d15=(d15*10+str[i]-'0')%15;
            d55=(d55*10+str[i]-'0')%55;
        }
        if((!d4&&d100)||!d400)
        {
            pi("This is leap year.\n");
            if(!d15)pi("This is huluculu festival year.\n");
            if(!d55)pi("This is bulukulu festival year.\n");
        }
        else
        {
            if(!d15)pi("This is huluculu festival year.\n");
            else pi("This is an ordinary year.\n");
        }
    }
    return 0;
}
