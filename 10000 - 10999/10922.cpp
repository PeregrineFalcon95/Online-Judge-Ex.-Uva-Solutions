#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        if(s=="0")return 0;
        int b=0,a=1,sum=0,len=s.size();
        for(int i=0; i!=len; i++)sum+=s[i]-'0';
        if(sum%9!=0)cout<<s<<" is not a multiple of 9.\n";
        else
        {
            while(sum>9)
            {
                a++;
                b=0;
                while(sum>0)
                {
                    b+=sum%10;
                    sum/=10;
                }
                sum=b;
            }
            if(sum==9)cout<<s<<" is a multiple of 9 and has 9-degree "<<a<<".\n";
        }
    }
    return 0;
}

