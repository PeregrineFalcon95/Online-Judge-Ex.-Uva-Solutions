#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    string name [ t+1 ];
    int in_e,e_date=INT_MAX,e_month=INT_MAX,e_year=INT_MAX,mi = INT_MAX;
    int in_y,y_date=0,y_month=0,y_year=0,mx = 0;
    for ( int i = 0; i != t; i++ )
    {
        cin>>name[ i ];
        scanf("%d%d%d",&a,&b,&c);
        if ( c >= y_year )
        {
            if( c == y_year )
            {
                if( y_month <= b )
                {
                    if( y_month == b )
                    {
                        if ( y_date <= a )
                        {
                            if ( y_date == a )
                            {
                                y_year = c;
                                y_month = b;
                                y_date = a;
                                in_y = i;
                            }
                            else
                            {
                                y_year = c;
                                y_month = b;
                                y_date = a;
                                in_y = i;
                            }
                        }
                    }
                    else
                    {
                        y_year = c;
                        y_month = b;
                        y_date = a;
                        in_y = i;
                    }
                }
            }
            else
            {
                y_year = c;
                y_month = b;
                y_date = a;
                in_y = i;
            }
        }
        if ( c <= e_year )
        {
            if ( c == e_year )
            {
                if( e_month >= b )
                {
                    if( e_month == b )
                    {
                        if ( e_date >= a )
                        {
                            if ( e_date == a )
                            {
                                e_year = c;
                                e_month = b;
                                e_date = a;
                                in_e = i;
                            }
                            else
                            {
                                e_year = c;
                                e_month = b;
                                e_date = a;
                                in_e = i;
                            }
                        }
                    }
                    else
                    {
                        e_year = c;
                        e_month = b;
                        e_date = a;
                        in_e = i;
                    }
                }
            }
            else
            {
                e_year = c;
                in_e = i;
                e_month = b;
                e_date = a;
            }
        }
    }
    cout<<name [ in_y ]<<"\n";
    cout<<name [ in_e ]<<"\n";
    return 0;
}
