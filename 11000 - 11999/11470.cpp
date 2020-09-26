#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m=0;
    while(scanf("%d",&n)==1&&n!=0)
    {
        int matrix[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)scanf("%d",&matrix[i][j]);
        }
        int k=0,l=n-1;
        vector<int>ans;
        printf("Case %d: ",++m);
        while(k<=l)
        {
            int a=0;
            if(k==l)a=matrix[l][k];
            else
            {
                for(int i=k; i<=l; i++)a+=matrix[k][i];
                for(int i=k; i<=l; i++)a+=matrix[l][i];
                for(int i=k+1; i<l; i++)a+=matrix[i][k];
                for(int i=k+1; i<l; i++)a+=matrix[i][l];
            }
            ans.push_back(a);
            k++;
            l--;
        }
        for(auto it:ans)
        {
            printf("%d",it);
            if(it!=ans.back())printf(" ");
        }
        printf("\n");
    }
    return 0;
}

