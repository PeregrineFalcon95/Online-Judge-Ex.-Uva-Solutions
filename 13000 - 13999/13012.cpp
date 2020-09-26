#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5],b,f;
    while(scanf("%d",&f)==1)
    {
        b=0;
        for(int i=0; i<5; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==f)b++;
        }
        printf("%d\n",b);
    }
    return 0;
}

