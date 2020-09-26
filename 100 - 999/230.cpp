#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e4+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , g , i , j , k , q ;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
//bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
//int ar [ mxs ] ;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
bool marker [ mxs ] , temp [ mxs ] , lol [ mxs ];
string s , s2 , s3 , name;
map < string , vector < string > > mp;
map < string , vector < string > >::iterator it;
map < string , int > num;
map < int , string > st;
deque < int > v;
void brainfuck();
void making_list();
void compress();
void shelve();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    making_list();
    brainfuck();
    return 0;
}
void brainfuck( )
{
    //cout<<a<<" xxx\n";
    while( cin>>s && s != "END" )
    {
        if ( s == "SHELVE" )
        {
            shelve();
            continue;
        }
        getline(cin,s2);
        //cout<<endl<<"  "<<s<<"  "<<s2<<endl;
        if ( s == "BORROW" )
        {
            while(s2 [ 0 ] == ' ' )s2.erase( s2.begin() );
            b = num [ s2 ];
            marker [ b ] = 1;
            temp [ b ] = 0;
        }
        else if ( s == "RETURN" )
        {
            //cout<<"l"<<s2<<"l\n";
            while(s2 [ 0 ] == ' ' )s2.erase( s2.begin() );
            //cout<<"l"<<s2<<"l\n";
            b = num [ s2 ];
            temp [ b ] = 1;
            v.push_back( b );
            //cout<<b<<"  xxxlol\n";
        }
    }
}
void making_list()
{
    while( getline( cin , s ) && s != "END" )
    {
        name = "";
        name += '"';
        n = s.size();
        a = 0;
        while ( s [ a ] && s [ a++ ] != '"' );
        for ( i = a; s [ i ] != '"'; i++ )name += s [ i ];
        name += '"';
        /*stringstream ss ( s );
        a = 0;
        s3 = "";
        while ( ss >> s2 )
        {
            if ( s2 == "by" )
            {
                a = 1;
            }
            else if ( a )
            {
                s3 += s2;
            }
        }*/
        //cout<<"l"<<name<<"l\n";
        s3 = "";
        while( s [ i++ ] != 'y' );
        for ( i++; i < n; i++ )s3 += s [ i ];//if( ( s [ i ] >= 'A' && s [ i ] <= 'Z' ) || ( s [ i ] >= 'a' && s [ i ] <= 'z' ) )s3 += s [ i ];
        //cout<<name<<"  "<<s3<<endl;
        mp [ s3 ].push_back( name );
    }
    compress();
}
void compress()
{
    a = 0;
    for ( it = mp.begin(); it != mp.end(); it++ )
    {
        b = it->second.size();
        sort( it->second.begin() , it->second.end() );
        for ( i = 0; i != b; i++ )
        {
            s = it->second [ i ];
            num [ s ] = ++a;
            st [ a ] = s;
        }
    }
}
void shelve()
{
    //cout<<v.size()<<"  xxx\n";
    memset( lol , 0 , sizeof lol );
    sort( v.begin() , v.end() );
    while ( !v.empty() )
    {
        b = v.front();
        v.pop_front();
        //cout<<b<<"  shit"<<endl;
        if ( !lol [ b ] && temp [ b ] )
        {
            c = b;
            e = 0;
            while( c && marker [ --c ] );
            //cout<<c<<endl;
            //for ( i = c; i <= b; i++ )cout<<marker [ i ]<<"  ";
            //cout<<endl;
            //cout<<marker [ b ] <<"   "<<marker [ c ]<<"  "<<st [ c ]<<endl;
            if( c && !marker [ c ] )cout<<"Put "<<st [ b ]<<" after "<<st [ c ]<<"\n";
            else cout<<"Put "<<st [ b ]<<" first\n";
            marker [ b ] = 0;
            lol [ b ] = 1;
        }
        //marker [ b ] = 0;
        //lol [ b ] = 1;
    }
    /*for ( i = 1; i <= a; i++ )
    {
        if ( temp [ i ] )
        {
            b = st [ i ];
            marker [ b ] = 0;
        }
    }*/
    cout<<"END\n";
    memset( temp , 0 , sizeof temp );
}
