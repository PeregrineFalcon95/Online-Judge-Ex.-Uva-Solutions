#include<bits/stdc++.h>
using namespace std;
int main()
{
    int person_num,budget,hotel_num,weeks_num;
    while(scanf("%d%d%d%d",&person_num,&budget,&hotel_num,&weeks_num)==4)
    {
        int h=hotel_num;
        int price[h],seat[h][weeks_num];
        while(h--)
        {
            scanf("%d",&price[h]);
            for(int i=0; i<weeks_num; i++)scanf("%d",&seat[h][i]);
        }
        int k=-1,f=0,ans=214565987;
        for(int i=0; i<hotel_num; i++)
        {
            if(price[i]*person_num<=budget)
            {
                for(int j=0; j<weeks_num; j++)
                {
                    if(seat[i][j]>=person_num)
                    {
                        if(ans>=price[i]*person_num)ans=price[i]*person_num;
                        f=1;
                    }
                }
            }
        }
        if(f==0)printf("stay home\n");
        if(f==1)printf("%d\n",ans);
    }
    return 0;
}
