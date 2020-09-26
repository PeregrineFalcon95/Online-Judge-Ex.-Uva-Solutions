#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int t;
    while(scanf("%lu",&t)==1)
    {
        unsigned long long int b=0;
        while(t--)
        {
            if(b!=0)cout<<endl;
            int n,m;
            cin>>n>>m;
            char str[m][n],test[m][n];
            for(int i=0; i<m; i++)cin>>str[i];
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)test[i][j]=str[i][j];
            }
            vector <int> v(m);
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n-1; j++)
                {
                    for(int k=0; k<n-j-1; k++)
                    {
                        if(test[i][k]>test[i][k+1])
                        {
                            char ch;
                            ch=test[i][k];
                            test[i][k]=test[i][k+1];
                            test[i][k+1]=ch;
                            v[i]++;
                        }
                    }
                }
            }
            vector <int> v2;
            v2=v;
            sort(v2.begin(),v2.end());
            for(int i=0; i<m; i++)
            {
                for(int j=0; j!=v.size(); j++)
                {
                    if(v[j]==v2[i])
                    {
                        for(int k=0; k<n; k++)
                        {
                            cout<<str[j][k];
                        }
                        cout<<endl;
                        v[j]=-5;
                        break;
                    }
                }
            }
            b++;
        }
    }
    return 0;
}
