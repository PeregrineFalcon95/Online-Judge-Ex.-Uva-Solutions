#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while( scanf("%d",&n) == 1 && n )
    {
        map < string , int > count_;
        int mx = 0;
        for(int i = 0; i < n; i++ )
        {
            int ar[ 5 ];
            for ( int j = 0; j < 5; j ++ )scanf("%d",&ar[j]);
            sort(ar,ar+5);
            string s;
            for( int j = 0 ; j < 5; j++ )
            {
                int a = ar [ j ];
                while( a != 0 )
                {
                    s.insert(s.end(),(a%10)+'0');
                    a/=10;
                }
            }
            ++count_ [ s ];
        }
        int mx_num = 0;
        for ( map < string , int > ::iterator it = count_.begin(); it != count_.end(); it++ )
        {
            if( it->second >  mx )mx = it->second;
        }
        for ( map < string , int > ::iterator it = count_.begin(); it != count_.end(); it++ )
        {
            if( it->second ==  mx )mx_num++;
        }
        if(!mx_num)mx_num++;
        if(mx>1)printf("%d\n",mx*mx_num);
        else printf("%d\n",n);
    }
    return 0;
}
