#include<bits/stdc++.h>
using namespace std;
int marker [ 28 ];
int find_parent( int a );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    scanf("%d",&n);
    getchar();
    getchar();
    m = n-1;
    while(n--)
    {
        if( m != n)
        {
            printf("\n");
        }
        string ch;
        getline(cin,ch);
        int f = ch[0] - 'A';
        for ( int i = 0; i <= f; i++ )marker [ i ] = i;
        set < int > st;
        string s;
        while(1)
        {
            getline(cin,s);
            if(!s.size())break;
            int a,b;
            a = s [ 0 ] - 'A';
            b = s [ 1 ] - 'A';
            int c,d;
            c = find_parent( a );
            d = find_parent( b );
            if ( c != d )
            {
                for( int i = 0; i <= f; i++ )
                {
                    if( marker [ i ] == d )marker [ i ] = c;
                }
                marker [ d ] = c ;
            }
        }
        for ( int i = 0; i <= f; i++ )
        {
            st.insert( marker[i] );
        }
        printf("%d\n",st.size());
    }
    return 0;
}
int find_parent( int a )
{
    if ( marker [ a ] == a ) return a;
    marker [ a ] = find_parent( marker [ a ] );
    return marker [ a ];
}
