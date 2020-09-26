#include<bits/stdc++.h>
using namespace std;
int main()
{
    int req,pro,se=0;
    while(scanf("%d%d",&req,&pro)==2 && (req!=0 || pro!=0))
    {
        if(se)printf("\n");
        cin.ignore();
        map < string , int > requirements;
        for(int i=0; i<req; i++)
        {
            string s;
            getline(cin,s);
            requirements[s]=1;
        }
        map < string, vector < string > > proposal_product;
        map < string, pair < double, int > > price_input_serial;
        int mx=0;
        for(int i=1; i<=pro; i++)
        {
            string name;
            getline(cin,name);
            double dam;
            int num;
            cin>>dam;
            scanf("%d",&num);
            cin.ignore();
            price_input_serial[name]=pair < double, int > (dam,i);
            for(int j=1; j<=num; j++)
            {
                string o_o;
                getline(cin,o_o);
                proposal_product[name].push_back(o_o);
            }
            if(proposal_product[name].size()>mx){mx=proposal_product[name].size();}
        }
        map < string, pair < double, int > >ans;
        double shit=999999999999999;
        for(map < string, vector < string > >::iterator it=proposal_product.begin(); it!=proposal_product.end(); it++)
        {
            if(it->second.size()==mx)
            {
                int a=price_input_serial[it->first].second;
                double p=price_input_serial[it->first].first;
                ans[it->first]=pair < double, int >(p,a);
                if(p<shit)shit=p;
            }
        }
        printf("RFP #%d\n",++se);
        map < string, pair < double, int > >::iterator it=ans.begin();
        if(ans.size()==1)cout<<it->first<<endl;
        else
        {
            map < string , int > solve;
            int mi=INT_MAX;
            for(it=ans.begin(); it!=ans.end(); it++)
            {
                if(it->second.first==shit)
                {
                    solve[it->first]=it->second.second;
                    if(it->second.second<mi)mi=it->second.second;
                }
            }
            map < string, int >::iterator ii=solve.begin();
            if(solve.size()==1)cout<<ii->first<<endl;
            else
            {
                string xxx;
                for(ii=solve.begin(); ii!=solve.end(); ii++)
                {
                    if(ii->second==mi){xxx=ii->first;}
                }
                cout<<xxx<<endl;
            }
        }
    }
    return 0;
}
