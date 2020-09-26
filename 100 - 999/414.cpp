#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   while(scanf("%d",&n)==1 && n )
   {
       char ar [ 30 ];
       int count_ [ n ];
       cin.ignore();
       int mx = 0;
       for ( int i = 0; i != n; i++ )
       {
          scanf(" %[^\n]",&ar);
          int a = 0;
          for ( int j = 0; j != 25; j++ )
          {
             if ( ar [ j ] == 'X')a++;
          }
          count_ [ i ] = a;
          if ( a > mx )mx = a;
       }
       int ans = 0;
       for ( int i = 0; i != n; i++ )
       {
          ans += mx- count_ [ i ];
       }
       printf("%d\n",ans);
   }
   return 0;
}
