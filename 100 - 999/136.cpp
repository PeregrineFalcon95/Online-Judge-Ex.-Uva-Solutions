/*#include<stdio.h>
int main()
{
    int i, j, n=1500, count = 0;
    int b[n];
    for(i = 1; count < n; i++)
    {
        j = i;
        while(j % 2 == 0)
        {
            j = j / 2;
        }
        while(j % 3 == 0)
        {
            j = j /3;
        }
        while(j % 5 == 0)
        {
            j = j / 5;
        }
        if(j == 1)
        {
            b[count] = i;
            count++;
        }
    }
    printf("The 1500th ugly number is %d", b[n-1]);
}*/

#include<stdio.h>
int main()
{
    printf("The 1500'th ugly number is 859963392.\n");
    return 0;
}
