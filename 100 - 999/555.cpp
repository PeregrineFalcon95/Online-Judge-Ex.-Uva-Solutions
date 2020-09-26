#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e4+7)
#define ll long long int
//ll ar [ mxs ] ;
int a , b , c , d , m , n ;
deque < int > ss , w , nn , e ;
string s , s2 , s3;
map < string , int > mp;
map < int , string > mp2;
void marker();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marker();
    while ( cin>>s3 && s3 != "#" )
    {
        cin>>s;
        cin>>s2;
        s += s2;
        n = s.size();
        if ( s3 == "N" )m = 4;
        else if ( s3 == "E" )m = 1;
        else if ( s3 == "S" ) m = 2;
        else if ( s3 == "W" )m = 3;
        s3 = "";
        for ( int i = 0; i != n; i++ )
        {
            if ( i&1 )
            {
                s3 += s [ i ];
                if ( m == 1 )ss.push_back( mp [ s3 ] );
                else if ( m == 2 )w.push_back( mp [ s3 ] );
                else if ( m == 3 )nn.push_back( mp [ s3 ] );
                else if ( m == 4 )e.push_back( mp [ s3 ] );
                s3 = "";
                m++;
                if ( m == 5 )m = 1;
            }
            else s3 += s [ i ];
        }
        sort( ss.begin() , ss.end() );
        sort( w.begin() , w.end() );
        sort( nn.begin() , nn.end() );
        sort( e.begin() , e.end() );
        cout<<"S:";
        while ( !ss.empty() )
        {
            cout<<" "<<mp2 [ ss.front() ];
            ss.pop_front();
        }
        cout<<"\n";
        cout<<"W:";
        while ( !w.empty() )
        {
            cout<<" "<<mp2 [ w.front() ];
            w.pop_front();
        }
        cout<<"\n";
        cout<<"N:";
        while ( !nn.empty() )
        {
            cout<<" "<<mp2 [ nn.front() ];
            nn.pop_front();
        }
        cout<<"\n";
        cout<<"E:";
        while ( !e.empty() )
        {
            cout<<" "<<mp2 [ e.front() ];
            e.pop_front();
        }
        cout<<"\n";
    }
    return 0;
}
void marker()
{
    mp [ "C2" ] = 1;
    mp2 [ 1 ] = "C2";
    mp [ "C3" ] = 2;
    mp2 [ 2 ] = "C3";
    mp [ "C4" ] = 3;
    mp2 [ 3 ] = "C4";
    mp [ "C5" ] = 4;
    mp2 [ 4 ] = "C5";
    mp [ "C6" ] = 5;
    mp2 [ 5 ] = "C6";
    mp [ "C7" ] = 6;
    mp2 [ 6 ] = "C7";
    mp [ "C8" ] = 7;
    mp2 [ 7 ] = "C8";
    mp [ "C9" ] = 8;
    mp2 [ 8 ] = "C9";
    mp [ "CT" ] = 9;
    mp2 [ 9 ] = "CT";
    mp [ "CJ" ] = 10;
    mp2 [ 10 ] = "CJ";
    mp [ "CQ" ] = 11;
    mp2 [ 11 ] = "CQ";
    mp [ "CK" ] = 12;
    mp2 [ 12 ] = "CK";
    mp [ "CA" ] = 13;
    mp2 [ 13 ] = "CA";

    mp [ "D2" ] = 14;
    mp2 [ 14 ] = "D2";
    mp [ "D3" ] = 15;
    mp2 [ 15 ] = "D3";
    mp [ "D4" ] = 16;
    mp2 [ 16 ] = "D4";
    mp [ "D5" ] = 17;
    mp2 [ 17 ] = "D5";
    mp [ "D6" ] = 18;
    mp2 [ 18 ] = "D6";
    mp [ "D7" ] = 19;
    mp2 [ 19 ] = "D7";
    mp [ "D8" ] = 20;
    mp2 [ 20 ] = "D8";
    mp [ "D9" ] = 21;
    mp2 [ 21 ] = "D9";
    mp [ "DT" ] = 22;
    mp2 [ 22 ] = "DT";
    mp [ "DJ" ] = 23;
    mp2 [ 23 ] = "DJ";
    mp [ "DQ" ] = 24;
    mp2 [ 24 ] = "DQ";
    mp [ "DK" ] = 25;
    mp2 [ 25 ] = "DK";
    mp [ "DA" ] = 26;
    mp2 [ 26 ] = "DA";

    mp [ "S2" ] = 27;
    mp2 [ 27 ] = "S2";
    mp [ "S3" ] = 28;
    mp2 [ 28 ] = "S3";
    mp [ "S4" ] = 29;
    mp2 [ 29 ] = "S4";
    mp [ "S5" ] = 30;
    mp2 [ 30 ] = "S5";
    mp [ "S6" ] = 31;
    mp2 [ 31 ] = "S6";
    mp [ "S7" ] = 32;
    mp2 [ 32 ] = "S7";
    mp [ "S8" ] = 33;
    mp2 [ 33 ] = "S8";
    mp [ "S9" ] = 34;
    mp2 [ 34 ] = "S9";
    mp [ "ST" ] = 35;
    mp2 [ 35 ] = "ST";
    mp [ "SJ" ] = 36;
    mp2 [ 36 ] = "SJ";
    mp [ "SQ" ] = 37;
    mp2 [ 37 ] = "SQ";
    mp [ "SK" ] = 38;
    mp2 [ 38 ] = "SK";
    mp [ "SA" ] = 39;
    mp2 [ 39 ] = "SA";

    mp [ "H2" ] = 40;
    mp2 [ 40 ] = "H2";
    mp [ "H3" ] = 41;
    mp2 [ 41 ] = "H3";
    mp [ "H4" ] = 42;
    mp2 [ 42 ] = "H4";
    mp [ "H5" ] = 43;
    mp2 [ 43 ] = "H5";
    mp [ "H6" ] = 44;
    mp2 [ 44 ] = "H6";
    mp [ "H7" ] = 45;
    mp2 [ 45 ] = "H7";
    mp [ "H8" ] = 46;
    mp2 [ 46 ] = "H8";
    mp [ "H9" ] = 47;
    mp2 [ 47 ] = "H9";
    mp [ "HT" ] = 48;
    mp2 [ 48 ] = "HT";
    mp [ "HJ" ] = 49;
    mp2 [ 49 ] = "HJ";
    mp [ "HQ" ] = 50;
    mp2 [ 50 ] = "HQ";
    mp [ "HK" ] = 51;
    mp2 [ 51 ] = "HK";
    mp [ "HA" ] = 52;
    mp2 [ 52 ] = "HA";
}
