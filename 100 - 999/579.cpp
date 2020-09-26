#include<stdio.h>
int main()
{
    double h,m,n;
    while(scanf("%lf:%lf",&h,&m)==2){
        if(h==0&&m==0){
            break;
        }
        h=h*5*6;
        m=m*6;
        h=h+((m/72)*6);
        n=h-m;
        if(n<0){
            n=n*(-1);
        }
        if(n>180){
            n=360-n;
        }
        printf("%.3lf\n",n);
    }
    return 0;
}
