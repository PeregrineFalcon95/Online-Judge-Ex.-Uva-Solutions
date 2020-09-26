#include<bits/stdc++.h>
using namespace std;
int main()
{
    string value;
    int m=0;
    int n;
    while(scanf("%d",&n)==1)
    {
        if(m)printf("\n");
        m++;
        cin.ignore();
        int source,target;
        vector < int > graph[(n*2)+5];
        map < int , string > compress;
        int flag=1;
        for(int i=0; i<n; i++)
        {
            string ss;
            getline(cin,ss);
            string token="";
            stringstream sss(ss);
            int a=0,b=0;
            int ff=0;
            while(sss>>token)
            {
                int c=0;
                if(ff==2)break;
                for(map < int, string >::iterator it=compress.begin(); it!=compress.end(); it++)
                {
                    if(it->second == token)
                    {
                        c=1;
                        if(!ff)
                        {
                            ff=1;
                            a=it->first;
                        }
                        else
                        {
                            ff=2;
                            b=it->first;
                        }
                    }
                }
                if(!c)
                {
                    if(!ff)
                    {
                        ff=1;
                        a=flag++;
                    }
                    else if(ff)
                    {
                        ff=2;
                        b=flag++;
                    }
                }
                if(ff==1)compress[a]=token;
                else if(ff==2)compress[b]=token;
            }
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        string s;
        getline(cin,s);
        stringstream ss(s);
        string token="";
        int ff=0;
        while(ss>>token)
        {
            if(ff==2)break;
            int a;
            for(map < int, string >::iterator it=compress.begin(); it!=compress.end(); it++)
            {
                if(it->second == token)
                {
                    if(!ff)
                    {
                       a=it->first;
                       ff=1;
                    }
                    else if(ff==1)
                    {
                        ff=2;
                        a=it->first;
                    }
                }
            }
            if(ff==1)source=a;
            else if(ff==2)target=a;
        }
        bool visited[n+10];
        memset(visited, 0, sizeof visited);
        map < int, int > back_edges;
        back_edges[source]=-1;
        queue < int > qu;
        qu.push(source);
        visited[source]=1;
        flag=0;
        while(!qu.empty())
        {
            int front_=qu.front();
            qu.pop();
            int sz=graph[front_].size();
            for(int i=0; i!=sz; i++)
            {
                int fff=graph[front_][i];
                if(!visited[fff])
                {
                    qu.push(fff);
                    visited[fff]=1;
                    back_edges[fff]=front_;
                    if(fff==target)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag)break;
        }
        if(!flag)
        {
            printf("No route\n");
            continue;
        }
        vector < int > temp;
        int pre=target;
        while(1)
        {
            temp.push_back(pre);
            pre=back_edges[pre];
            if(pre==-1)break;
        }
        string kk=compress[temp.back()];
        reverse(temp.begin(),temp.end());
        int sz=temp.size();
        for(int i=1; i!=sz; i++)
        {
            cout<<kk<<" ";
            cout<<compress[temp[i]]<<endl;
            kk="";
            kk=compress[temp[i]];
        }
    }
    return 0;
}
