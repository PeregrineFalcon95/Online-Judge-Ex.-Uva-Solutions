#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while ( t-- )
    {
        string month, date;
        cin>>month>>date;
        if ( date == "SUN" || date == "MON" || date == "TUE" )printf("8\n");
        else if ( date == "SAT" )
        {
            if ( month == "FEB")printf("8\n");
            else printf("9\n");
        }
        else if ( date == "WED" )
        {
            if ( month == "FEB" || month == "APR" || month == "JUN" || month == "SEP" || month == "NOV")printf("8\n");
            else printf("9\n");
        }
        else if ( date == "FRI" )
        {
            if ( month == "FEB")printf("8\n");
            else printf("10\n");
        }
        else
        {
            if ( month == "APR" || month == "JUN" || month == "SEP" || month == "NOV" )printf("9\n");
            else if ( month == "FEB")printf("8\n");
            else printf("10\n");
        }
    }
    return 0;
}
