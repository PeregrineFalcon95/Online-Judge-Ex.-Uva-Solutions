#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x_range,y_range;
    scanf("%d%d",&x_range,&y_range );
    multimap < int, pair < int, int > > trace;

    ///Mapping for the off grids
    for ( int i = -2; i <= x_range+2 ; i++ )
    {
        for ( int j = -2; j <= y_range+2; j++ )
            trace.insert( make_pair (i, make_pair ( j,0 ) ) );
    }
    int grid [ 50+2 ] [ 50+2 ];
    memset ( grid, 0, sizeof grid );
    int x_axis,y_axis;
    char pos;
    multimap < int, pair < int, int > >::iterator it,lo,hi;
    while ( scanf ("%d%d%c%c",&x_axis,&y_axis,&pos,&pos) == 4 )
    {
        char dir [ 110 ];
        scanf("%s",&dir);
        int sz = strlen(dir);

        for ( int i = 0; i != sz; i++ )
        {
            /// Starting of the direction string o_o
            char ss = dir [ i ];
            if ( ss == 'R' )
            {
                if ( pos == 'N' )
                {
                    pos = 'E';
                    if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                }
                else if ( pos == 'E' )
                {
                    pos = 'S';
                    if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                }
                else if ( pos == 'S' )
                {
                    pos = 'W';
                    if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                }
                else if ( pos == 'W' )
                {
                    pos = 'N';
                    if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                }
            }
            else if ( ss == 'L' )
            {
                if ( pos == 'N' )
                {
                    pos = 'W';
                    if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                }
                else if ( pos == 'W' )
                {
                    pos = 'S';
                    if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                }
                else if ( pos == 'S' )
                {
                    pos = 'E';
                    if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                }
                else if ( pos == 'E' )
                {
                    pos = 'N';
                    if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                }
            }
            else if ( ss == 'F' )
            {
                /// Working on the Traverse
                if ( pos == 'N' )
                {
                    if ( y_axis < y_range )
                    {
                        y_axis++;
                        if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                        continue;
                    }


                    int ww = 0;
                    lo = trace.lower_bound ( x_axis );
                    hi = trace.upper_bound ( x_axis );
                    for ( it = lo; it != hi; it++ )
                    {
                        if ( ((*it).first == x_axis ) && (*it).second.first == y_axis+1 )
                        {
                            if ( (*it).second.second == 1 || grid [ x_axis ] [ y_axis ] )
                            {
                                break;
                            }
                            else
                            {
                                ww =1;
                                if( !grid [ x_axis ] [ y_axis ] )printf("%d %d %c LOST\n",x_axis,y_axis,pos);
                                else printf("%d %d %c\n",x_axis,y_axis,pos);
                                grid [ x_axis ] [ y_axis ] = 1;
                                (*it).second.second = 1;
                                break;
                            }
                        }
                    }
                    if ( ww )break;
                    if(sz-1 == i )printf("%d %d %c\n",x_axis,y_axis,pos);
                }
                else if ( pos == 'W' )
                {
                    if ( x_axis > 0 )
                    {
                        x_axis--;
                        if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                        continue;
                    }

                    int ww = 0,tt = 0;
                    lo = trace.lower_bound ( x_axis-1 );
                    hi = trace.upper_bound ( x_axis-1 );
                    for ( it = lo; it != hi; it++ )
                    {
                        if ( ((*it).first == x_axis-1 ) && (*it).second.first == y_axis )
                        {
                            if ( (*it).second.second == 1 || grid [ x_axis ] [ y_axis ] )
                            {
                                break;
                            }
                            else
                            {
                                ww =1;
                                if( !grid [ x_axis ] [ y_axis ] ){printf("%d %d %c LOST\n",x_axis,y_axis,pos);tt = 1;}
                                else printf("%d %d %c\n",x_axis,y_axis,pos);
                                grid [ x_axis ] [ y_axis ] = 1;
                                (*it).second.second = 1;
                                break;
                            }
                        }
                    }
                    if ( ww )break;
                    if(sz-1 == i )printf("%d %d %c\n",x_axis,y_axis,pos);
                }
                else if ( pos == 'S' )
                {
                    if ( y_axis > 0 )
                    {
                        y_axis--;
                        if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                        continue;
                    }
                    int ww = 0;
                    lo = trace.lower_bound ( x_axis );
                    hi = trace.upper_bound ( x_axis );
                    for ( it = lo; it != hi; it++ )
                    {
                        if ( ((*it).first == x_axis ) && (*it).second.first == y_axis-1 )
                        {
                            if ( (*it).second.second == 1 || grid [ x_axis ] [ y_axis ] )
                            {
                                break;
                            }
                            else
                            {
                                ww =1;
                                if( !grid [ x_axis ][ y_axis ] )printf("%d %d %c LOST\n",x_axis,y_axis,pos);
                                else printf("%d %d %c\n",x_axis,y_axis,pos);
                                grid [ x_axis ] [ y_axis ] = 1;
                                (*it).second.second = 1;
                                break;
                            }
                        }
                    }
                    if ( ww )break;
                    if(sz-1 == i )printf("%d %d %c\n",x_axis,y_axis,pos);
                }
                else if ( pos == 'E' )
                {
                    if ( x_axis < x_range )
                    {
                        x_axis++;
                        if(sz-1 == i)printf("%d %d %c\n",x_axis,y_axis,pos);
                        continue;
                    }
                    int ww = 0;
                    lo = trace.lower_bound ( x_axis+1 );
                    hi = trace.upper_bound ( x_axis+1 );
                    for ( it = lo; it != hi; it++ )
                    {
                        if ( ((*it).first == x_axis+1 ) && (*it).second.first == y_axis )
                        {
                            if ( (*it).second.second == 1 || grid [ x_axis ] [ y_axis ] )
                            {
                                break;
                            }
                            else
                            {
                                ww =1;
                                if( !grid [ x_axis ] [ y_axis ] )printf("%d %d %c LOST\n",x_axis,y_axis,pos);
                                else printf("%d %d %c\n",x_axis,y_axis,pos);
                                grid [ x_axis ] [ y_axis ] = 1;
                                (*it).second.second = 1;
                                break;
                            }
                        }
                    }
                    if ( ww )break;
                    if(sz-1 == i )printf("%d %d %c\n",x_axis,y_axis,pos);

                }
            }
            /// End of the direction string o_o
        }
    }
    return 0;
}

