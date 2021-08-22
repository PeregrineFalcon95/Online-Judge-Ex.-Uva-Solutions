#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

#define inf ( int )( 1e9 + 10 )
#define mxs (int)( 2e5 + 10 )
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie( NULL);
//#define md int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions 
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions 
ll t, n, m, cases;
double currentSecond, currentDistance, currentSpeed;
char s [ 100 ] , s2 [ 100 ];
void brainfuck();
int main()
{
    fast
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck() 
{
    while( cin.getline(s2,100) )
    {
        double hour, mi, sec;
        sscanf(s2,"%lf:%lf:%lf",&hour,&mi,&sec);
        sec += (mi * 60.0) + (hour * 60.0 * 60.0);
        if ( s2 [ 8 ] == '\0' )
        {
            double dis = sec - currentSecond;
            dis = ( currentSpeed * dis ) / 3600;
            cout<<s2<<" "<<fixed<<setprecision(2)<<dis + currentDistance<<" km\n";
        }
        else
        {
            double speed ;
            sscanf(s2+8,"%lf",&speed);
            double temp = sec - currentSecond;
            temp = ( currentSpeed * temp ) / 3600.0;
            currentDistance += temp;
            currentSecond = sec;
            currentSpeed = speed;
        }
    }
}
