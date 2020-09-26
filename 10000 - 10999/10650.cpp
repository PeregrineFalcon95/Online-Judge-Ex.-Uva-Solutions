#include<bits/stdc++.h>
using namespace std;
vector <pair <int, int > > prime;
typedef pair<int,int> pp;
bool status[33000];
void seive();
void solution(int l, int u);
int main()
{
    seive();
    int l,u;
    while(scanf("%d%d",&l,&u)==2 &&(l!=0 ||u!=0))
    {
        if(l>u)swap(l,u);
        solution(l,u);
    }
    return 0;
}
void seive()
{
    int n=32500;
    int sq=sqrt(n);
    prime.push_back(pair<int, int >(2,0));
    int wz=0;
    for(int i=3; i<=sq; i+=2)
    {
        if(!status[i])
        {
            for(int j=i*i; j<n; j+=(i+i))status[j]=1;
        }
    }
    prime.push_back(pair < int ,int> (3,1));
    int pre=3;
    for(int i=5; i<=n; i+=2)
    {
        if(!status[i])
        {
            prime.push_back(pair < int, int >(i,i-pre));
            pre=i;
        }
    }
}
void solution(int l, int u)
{
    int a=l;
    vector < pair <int, int > > ::iterator it = lower_bound(prime.begin(),prime.end(), pp(l,0));
    int lo=it-prime.begin();
    int sz=prime.size();
    vector < vector < int > > ans;
    for(int i=lo; prime[i].first<=u; )
    {
        vector <int > temp;
        if(i)temp.push_back(prime[i-1].first);
        for(int j=i; j<(i+6); j++)
        {
            if(prime[i].second == prime[j].second)
            {
                temp.push_back(prime[j].first);
            }
            else if(temp.size()>=3 && temp.back()<=u && temp.front()>=l && prime[i-1].second!=prime[i].second)
            {
                ans.push_back(temp);
                i=j-1;
                break;
            }
            else {i++;break;}
        }
    }
    for(int i=0; i!=ans.size(); i++)
    {
        for(int j=0; j!=ans[i].size(); j++)
        {
            if(j)printf(" ");
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }
}
