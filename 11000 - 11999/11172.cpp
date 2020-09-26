//Uva problem:11172
#include<stdio.h>
int main()
{
    int i,j;
    long int a,b;
    scanf("%d",&i);
    if(i<15)
    {
        for(j=1; j<=i; j++)
        {
            scanf("%ld %ld",&a,&b);
            if(a>b)
                printf(">\n");
            else if(a<b)
                printf("<\n");
            else
                printf("=\n");
        }
    }
    else
    {
        printf("Wrong input\n");
    }
    return 0;
}

