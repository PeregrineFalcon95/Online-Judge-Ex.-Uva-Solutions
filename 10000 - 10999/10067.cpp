#include<bits/stdc++.h>
using namespace std;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar_unlocked();
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
}
int graph[10010][ 10 ];
int marker [ 10005 ];
void make_graph();
int forb[ 10005 ];
int bfs(int source, int target);
int main()
{
    //ios_base::sync_with_stdio(false);
    make_graph();
    int n,a,b,c,d,e,f,target,source;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
     fastscan(n);
    //scanf("%d",&n);
    // getchar();
    while ( n-- )
    {
        //if( n != m )getchar();
        //getchar();
        memset( forb, 0, sizeof forb);
        while( 1 ){
                fastscan(a);
                if( a != -1 )break;
        }
        //cout << a << endl;
        //if( a == -1 )fastscan( a );
        fastscan(b);
        fastscan(c);
        fastscan(d);

        //getchar();
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        //scanf("%d%d%d%d",&a,&b,&c,&d);
        source = 0;
        source+=a;
        source*=10;
        source+=b;
        source*=10;
        source+=c;
        source*=10;
        source+=d;
        //getchar();
        fastscan(a);
        fastscan(b);
        fastscan(c);
        fastscan(d);
        //getchar();
        //getchar();
        //scanf("%d%d%d%d",&a,&b,&c,&d);
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        target = 0;
        target+=a;
        target*=10;
        target+=b;
        target*=10;
        target+=c;
        target*=10;
        target+=d;
        fastscan(e);
        //scanf("%d",&e);
        //getchar();
        for ( int i = 0; i != e; i++ )
        {
            //getchar();
            fastscan(a);
            fastscan(b);
            fastscan(c);
            fastscan(d);
            //scanf("%d%d%d%d",&a,&b,&c,&d);
            //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            f = 0;
            f+=a;
            f*=10;
            f+=b;
            f*=10;
            f+=c;
            f*=10;
            f+=d;
            forb [ f ] = 1;
        }
        //if( n )getchar();
        if (source == target )
        {
            printf("0\n");
            //getchar();
            continue;
        }
        int ans = bfs( source, target );
        printf("%d\n",ans);
        //if(n)getchar();
    }
    return 0;
}
int bfs(int source, int target)
{
    bool visited [ 10020 ];
    memset(visited, 0, sizeof visited);
    int level [ 10020 ];
    memset(level, -1, sizeof level );
    queue < int > qu;
    qu.push( source );
    level [ source ] = 0;
    visited[ source ] = 1;
    int ans = -1;
    while ( !qu.empty() )
    {
        int w_w = 0;
        int front_ = qu.front();
        qu.pop();
        int sz = marker [ front_ ];
        for ( int i = 0; i != sz; i++ )
        {
            int o_o = graph [ front_ ] [ i ];
            if (  !visited [ o_o ] && !forb [ o_o ] )
            {
                qu.push( o_o );
                level [ o_o ] = level [ front_ ]+1;
                visited [ o_o ] = 1;
                if ( o_o == target )
                {
                    ans = level [ target];
                    w_w = 1;
                    break;
                }
            }
        }
        if ( w_w )break;
    }
    return ans;
}

void make_graph()
{
    int a,b,c,d,e,f;
    char st [ 6 ];
    for ( int i = 0 ; i != 10000; i++ )
    {
        if ( i <= 9 )
        {
            st [ 0 ] = '0';
            st [ 1 ] = '0';
            st [ 2 ] = '0';
            st [ 3 ] = i + '0';
            st [ 4 ] = 0;
        }
        else if ( i <= 99 )
        {
            c = i;
            a = c%10;
            c/=10;
            b = c%10;
            st [ 0 ] = '0';
            st [ 1 ] = '0';
            st [ 2 ] = b + '0';
            st [ 3 ] = a + '0';
            st [ 4 ] = 0;
        }
        else if ( i <= 999 )
        {
            d = i;
            c = d%10;
            d/=10;
            b = d%10;
            d/=10;
            a = d;
            st [ 0 ] = '0';
            st [ 1 ] = a + '0';
            st [ 2 ] = b + '0';
            st [ 3 ] = c + '0';
            st [ 4 ] = 0;
        }
        else if ( i <= 9999 )
        {
            e = i;
            d = e%10;
            e/=10;
            c = e%10;
            e/=10;
            b = e%10;
            e/=10;
            a = e;
            st [ 0 ] = a + '0';
            st [ 1 ] = b + '0';
            st [ 2 ] = c + '0';
            st [ 3 ] = d + '0';
            st [ 4 ] = 0;
        }
        if ( st [ 3 ] > '0' && st [ 3 ] < '9' )
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ]-'0'-1;
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= st [ 3 ] -'0'+1;
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
        else if ( st [ 3 ] == '0' )
        {
            a = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ] -'0'+1;
            b = 0;
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ]-'0';
            b*=10;
            b+= st [ 2 ]-'0';
            b*=10;
            b+= 9;
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
        else if ( st [ 3 ] =='9' )
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+=8;
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= 0;
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
        if ( st [ 2 ] > '0' && st [ 2 ] < '9' )
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0'-1;
            a*=10;
            a+= st [ 3 ]-'0';
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= st [ 2 ] -'0'+1;
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
        else if ( st [ 2 ] == '0' )
        {
            a = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0'+1;
            a*=10;
            a+= st [ 3 ] -'0';
            b = 0;
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ]-'0';
            b*=10;
            b+= 9;
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
        else if ( st [ 2 ] == '9')
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= 0;
            a*=10;
            a+= st [ 3 ]-'0';
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= 8;
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
        if ( st [ 1 ] > '0' && st [ 1 ] < '9' )
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0'-1;
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ]-'0';
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ] -'0'+1;
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
        else if ( st [ 1 ] =='0' )
        {
            a = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0'+1;
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ] -'0';
            b = 0;
            b+= st [ 0 ]-'0';
            b*=10;
            b+= 9;
            b*=10;
            b+= st [ 2 ]-'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
        else if ( st [ 1 ] == '9' )
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= 0;
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ]-'0';
            b+= st [ 0 ]-'0';
            b*=10;
            b+= 8;
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
        if ( st [ 0 ] > '0' && st [ 0 ] < '9')
        {
            a = b = 0;
            a+= st [ 0 ]-'0'-1;
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ]-'0';
            b+= st [ 0 ]-'0'+1;
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
        else if ( st [ 0 ] =='0' )
        {
            a = 0;
            a+= st [ 0 ]-'0'+1;
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ] -'0';
            b = 0;
            b+= 9;
            b*=10;
            b+= st [ 1 ]-'0';
            b*=10;
            b+= st [ 2 ]-'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
        else if ( st [ 0 ] == '9' )
        {
            a = b = 0;
            a+= 0;
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ]-'0';
            b+= 8;
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ] [ marker [ i ]++ ] = a;
            graph [ i ] [ marker [ i ]++ ] = b;
        }
    }
}































/*#include<bits/stdc++.h>
using namespace std;
vector < int > graph[10010];
void make_graph();
int forb[ 10020 ];
int bfs(int source, int target);
int main()
{
    make_graph();
    int n,a,b,c,d,e,f,target,source;
    scanf("%d",&n);
    while ( n-- )
    {
        memset( forb, 0, sizeof forb);
        scanf("%d%d%d%d",&a,&b,&c,&d);
        source = 0;
        source+=a;
        source*=10;
        source+=b;
        source*=10;
        source+=c;
        source*=10;
        source+=d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        target = 0;
        target+=a;
        target*=10;
        target+=b;
        target*=10;
        target+=c;
        target*=10;
        target+=d;
        scanf("%d",&e);
        for ( int i = 0; i != e; i++ )
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            f = 0;
            f+=a;
            f*=10;
            f+=b;
            f*=10;
            f+=c;
            f*=10;
            f+=d;
            forb [ f ] = 1;
        }
        if (source == target )
        {
            printf("0\n");
            continue;
        }
        int ans = bfs( source, target );
        printf("%d\n",ans);
    }
    return 0;
}
int bfs(int source, int target)
{
    bool visited [ 10020 ];
    memset(visited, 0, sizeof visited);
    int level [ 10020 ];
    memset(level, -1, sizeof level );
    queue < int > qu;
    qu.push( source );
    level [ source ] = 0;
    visited[ source ] = 1;
    int ans = -1;
    while ( !qu.empty() )
    {
        int w_w = 0;
        int front_ = qu.front();
        qu.pop();
        int sz = graph [ front_ ].size();
        for ( int i = 0; i != sz; i++ )
        {
            int o_o = graph [ front_ ] [ i ];
            if (  !visited [ o_o ] && !forb [ o_o ] )
            {
                qu.push( o_o );
                level [ o_o ] = level [ front_ ]+1;
                visited [ o_o ] = 1;
                if ( o_o == target )
                {
                    ans = level [ target];
                    w_w = 1;
                    break;
                }
            }
        }
        if ( w_w )break;
    }
    return ans;
}

void make_graph()
{
    int a,b,c,d,e,f;
    char st [ 6 ];
    for ( int i = 0 ; i != 10000; i++ )
    {
        if ( i <= 9 )
        {
            st [ 0 ] = '0';
            st [ 1 ] = '0';
            st [ 2 ] = '0';
            st [ 3 ] = i + '0';
            st [ 4 ] = 0;
        }
        else if ( i <= 99 )
        {
            c = i;
            a = c%10;
            c/=10;
            b = c%10;
            st [ 0 ] = '0';
            st [ 1 ] = '0';
            st [ 2 ] = b + '0';
            st [ 3 ] = a + '0';
            st [ 4 ] = 0;
        }
        else if ( i <= 999 )
        {
            d = i;
            c = d%10;
            d/=10;
            b = d%10;
            d/=10;
            a = d;
            st [ 0 ] = '0';
            st [ 1 ] = a + '0';
            st [ 2 ] = b + '0';
            st [ 3 ] = c + '0';
            st [ 4 ] = 0;
        }
        else if ( i <= 9999 )
        {
            e = i;
            d = e%10;
            e/=10;
            c = e%10;
            e/=10;
            b = e%10;
            e/=10;
            a = e;
            st [ 0 ] = a + '0';
            st [ 1 ] = b + '0';
            st [ 2 ] = c + '0';
            st [ 3 ] = d + '0';
            st [ 4 ] = 0;
        }
        if ( st [ 3 ] > '0' && st [ 3 ] < '9' )
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ]-'0'-1;
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= st [ 3 ] -'0'+1;
            graph [ i ].push_back( a );
            graph [ i ].push_back( b );
        }
        else if ( st [ 3 ] == '0' )
        {
            a = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ] -'0'+1;
            b = 0;
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ]-'0';
            b*=10;
            b+= st [ 2 ]-'0';
            b*=10;
            b+= 9;
            graph [ i ].push_back( a );
            graph [ i ].push_back( b );
        }
        else if ( st [ 3 ] =='9' )
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+=8;
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= 0;
            graph [ i ].push_back( a );
            graph [ i ].push_back( b );
        }
        if ( st [ 2 ] > '0' && st [ 2 ] < '9' )
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0'-1;
            a*=10;
            a+= st [ 3 ]-'0';
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= st [ 2 ] -'0'+1;
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ].push_back( a );
            graph [ i ].push_back( b );
        }
        else if ( st [ 2 ] == '0' )
        {
            a = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0'+1;
            a*=10;
            a+= st [ 3 ] -'0';
            graph [ i ].push_back( a );
            b = 0;
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ]-'0';
            b*=10;
            b+= 9;
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ].push_back( b );
        }
        else if ( st [ 2 ] == '9')
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= 0;
            a*=10;
            a+= st [ 3 ]-'0';
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= 8;
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ].push_back( a );
            graph [ i ].push_back( b );
        }
        if ( st [ 1 ] > '0' && st [ 1 ] < '9' )
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0'-1;
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ]-'0';
            b+= st [ 0 ]-'0';
            b*=10;
            b+= st [ 1 ] -'0'+1;
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ].push_back( a );
            graph [ i ].push_back( b );
        }
        else if ( st [ 1 ] =='0' )
        {
            a = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= st [ 1 ]-'0'+1;
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ] -'0';
            graph [ i ].push_back( a );
            b = 0;
            b+= st [ 0 ]-'0';
            b*=10;
            b+= 9;
            b*=10;
            b+= st [ 2 ]-'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ].push_back( b );
        }
        else if ( st [ 1 ] == '9' )
        {
            a = b = 0;
            a+= st [ 0 ]-'0';
            a*=10;
            a+= 0;
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ]-'0';
            b+= st [ 0 ]-'0';
            b*=10;
            b+= 8;
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ].push_back( a );
            graph [ i ].push_back( b );
        }
        if ( st [ 0 ] > '0' && st [ 0 ] < '9')
        {
            a = b = 0;
            a+= st [ 0 ]-'0'-1;
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ]-'0';
            b+= st [ 0 ]-'0'+1;
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ].push_back( a );
            graph [ i ].push_back( b );
        }
        else if ( st [ 0 ] =='0' )
        {
            a = 0;
            a+= st [ 0 ]-'0'+1;
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ] -'0';
            graph [ i ].push_back( a );
            b = 0;
            b+= 9;
            b*=10;
            b+= st [ 1 ]-'0';
            b*=10;
            b+= st [ 2 ]-'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ].push_back( b );
        }
        else if ( st [ 0 ] == '9' )
        {
            a = b = 0;
            a+= 0;
            a*=10;
            a+= st [ 1 ]-'0';
            a*=10;
            a+= st [ 2 ]-'0';
            a*=10;
            a+= st [ 3 ]-'0';
            b+= 8;
            b*=10;
            b+= st [ 1 ] -'0';
            b*=10;
            b+= st [ 2 ] -'0';
            b*=10;
            b+= st [ 3 ] -'0';
            graph [ i ].push_back( a );
            graph [ i ].push_back( b );
        }
    }
}
*/
