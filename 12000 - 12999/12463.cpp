#include<bits/stdc++.h>
using namespace std;
int main()
{ 
   long long int a,b,c,d,e;
   while(scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e)==5&&(a!=0||b!=0||c!=0||d!=0||e!=0))
   {
      printf("%lld\n",(a*b*c*d*e*d*e));
   }
   return 0;
}
