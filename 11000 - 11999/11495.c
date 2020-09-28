#include<stdio.h>
int n , m , i  , leftPointer , rightPointer , pointVar;
int ar [ 100100 ] , counter [ 100100 ] , temp [ 100100 ];
void mergeSort( int Left , int Right );
int main()
{
    while( scanf("%d",&n) == 1 && n )
    {
        for ( i = 1 ; i <= n; i++ )
        {
            scanf("%d",&ar [ i ] );
            counter [ i ] = 0;
        }
        mergeSort( 1 , n );
        long long int ans = 0;
        for ( i = 1 ; i <= n; i++ )ans += (long long int )counter [ i ];

        if ( ans&1 )printf("Marcelo\n");
        else printf("Carlos\n");
    }
    return 0;
}

void mergeSort( int Left , int Right )
{
    if ( Left >= Right )return;
    int mid = ( Left + Right )>>1;

    mergeSort( Left , mid  );
    mergeSort( mid + 1 , Right );

    for ( i = Left; i <= Right; i++ )temp [ i ] = ar [ i ];

    leftPointer = Left , rightPointer = mid + 1;
    pointVar = Left;

    while( leftPointer <= mid && rightPointer <= Right )
    {
        if ( temp [ leftPointer ] < temp [ rightPointer ] )
        {
            counter [ temp [ leftPointer ] ] += pointVar - leftPointer;
            ar [ pointVar++ ] = temp [ leftPointer++ ];
        }
        else
        {
            if( pointVar - rightPointer > 0 )counter [ temp [ rightPointer ] ] += pointVar - rightPointer;
            ar [ pointVar++ ] = temp [ rightPointer++ ];
        }
    }

    while( leftPointer <= mid )
    {
        counter [ temp [ leftPointer ] ] += pointVar - leftPointer;
        ar [ pointVar++ ] = temp [ leftPointer++ ];
    }

    while( rightPointer <= Right )
    {
        if( pointVar - rightPointer > 0 )counter [ temp [ rightPointer ] ] += pointVar - rightPointer;
        ar [ pointVar++ ] = temp [ rightPointer++ ];
    }
}
