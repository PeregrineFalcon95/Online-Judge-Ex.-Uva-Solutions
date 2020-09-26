#include<bits/stdc++.h>
using namespace std;
int last[15]={ 0, 31 , -1 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
int last_date(int y, int x)
{
    if(y==2)
    {
        if((x%4==0&&x%100!=0)||(x%400==0)){return 29;}
        else return 28;
    }
    return last[y];
}
int main()
{
    int date,month,year,num;
    while(scanf("%d%d%d%d",&num,&date,&month,&year))
    {
        if(!date && !month && !year && !num)return 0;
        while(1)
        {
            if(date==1&&month==1)break;
            num++;
            if(date==1){month--;date=last_date(month, year);}
            else date--;
        }
        while(num>365)
        {
            if((year%4==0&&year%100!=0)||year%400==0)num-=366;
            else num-=365;
            year++;
        }
        while(num)
        {
            num--;
            if(date==31&&month==12){date=month=1;year++;}
            else if(date==last_date(month,year)){month++;date=1;}
            else date++;
        }
        printf("%d %d %d\n",date,month,year);
    }
    return 0;
}

