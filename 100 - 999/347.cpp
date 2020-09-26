#include<bits/stdc++.h>
using namespace std;
int cases;
int main()
{
    int n;
    while ( scanf("%d",&n) == 1 && n )
    {
        char st [ 10 ];
        for ( int i = n; ; i++ )
        {
            int ff = 0, w_w = 0, num = i;
            while ( num > 0 )
            {
                st [ ff++ ] = (num%10)+'0';
                num/=10;
            }
            st[ff ] = 0;
            reverse(st,st+ff);
            int a = 0;
            for ( int j = 0 ; j != ff; j++ )
            {
                if ( st [ j ] =='0'){a = 1;break;}
            }
            bool mark [ 10 ];
            memset(mark, 0 , sizeof mark );
            for ( int j  = 0; j != ff; j++ )
            {
                int h = st [ j ] - '0';
                if ( mark [ h ] )
                {
                    a = 1;
                    break;
                }
                else mark [ h ] = 1;
            }
            if ( a )continue;
            num = st [ 0 ] - '0';
            st [ 0 ] = '!';
            int flag = 0;
            while ( 1 )
            {
                int marker = 0, coun = 0;
                for ( int j = flag+1; ; j++ )
                {
                    coun++;
                    if ( j == ff )
                    {
                        j = 0;
                    }
                    if ( coun == num )
                    {
                        if ( j && st [ j ] == '!' )
                        {
                            marker = 1;
                            break;
                        }
                        else if ( !j && st [ j ] == '!' )
                        {
                            marker = 1;
                            st [ j ] ='@';
                            break;
                        }
                        else if ( st [ j ] !='!' )
                        {
                            num = st [ j ] -'0';
                            st [ j ] ='!';
                            if ( j+1 == ff)
                            {
                                flag = -1;
                                break;
                            }
                            else
                            {
                                flag = j;
                                break;
                            }
                        }
                    }
                }
                if( marker )break;
            }
            flag = 0;
            int o_o = 0;
            for ( int j = 0; j != ff; j++ )
            {
                if ( st [ j ] == '!' || st [ j ] =='@')
                {
                    flag = 0;
                    if ( st [ j ] =='@')o_o = 1;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            if ( !flag && o_o )
            {
                printf("Case %d: %d\n",++cases,i);
                break;
            }
        }
    }
    return 0;
}
