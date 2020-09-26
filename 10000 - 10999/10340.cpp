#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
#define lld long long int
int main()
{
    char str[100020],str2[100020];
    while(sc("%s%s",&str,&str2)!=EOF)
    {
        int l=strlen(str);
        int a=0,b,c=0,k=strlen(str2);
        for(int i=0;i<l;i++)
        {
            b=0;
            for(int j=a;j<k;j++)
            {
                if(str[i]==str2[j])
                {
                    a=j+1;
                    b=1;
                    break;
                }
            }
            if(b==0)
            {
                c=1;
                break;
            }
        }
        if(c==1)pi("No\n");
        else pi("Yes\n");
    }
    return 0;
}
