#include<bits/stdc++.h>
using namespace std;
int cube[202];
int main()
{
    int a=0;
    for(int i=1; i<=200; i++)cube[i]=pow(i,3);
    for(int i=5; i<=200; i++)
    {
        for(int j=2; j<=200; j++)
        {
            for(int k=j+1; k<=200; k++)
            {
                for(int l=k+1; l<=200; l++)
                {
                    if(cube[i]==(cube[j]+cube[k]+cube[l]))
                    {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}

