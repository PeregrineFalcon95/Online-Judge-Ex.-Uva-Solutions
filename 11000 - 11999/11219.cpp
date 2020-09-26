//problem: 11219
#include<stdio.h>
int main()
{
    int d1,m1,y1,d2,m2,y2,i,T,age;
    scanf("%d",&T);
    if(1<=T && T<=200){
        for(i=1;i<=T;i++){
            scanf("%d/%d/%d",&d1,&m1,&y1);
            scanf("%d/%d/%d",&d2,&m2,&y2);
            if(d2>d1){
                d1+=30;
                m2++;
            }
            if(m2>m1){
                m1+=12;
                y2++;
            }
            age=y1-y2;
            if(age<0)
            {
                printf("Case #%d: Invalid birth date\n",i);
            }
            else if(age>130)
            {
                printf("Case #%d: Check birth date\n",i);
            }
            else
            {
                printf("Case #%d: %d\n",i,age);
            }
        }
    }
    return 0;
}

