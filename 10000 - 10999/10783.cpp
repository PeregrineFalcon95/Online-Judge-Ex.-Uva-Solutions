//problem: 10783
#include<stdio.h>
int main()
{
    int sum,j,i,T,a,b;
    scanf("%d",&T);
    if(0<=T<=100){
        for(i=1;i<=T;i++){
            scanf("%d %d",&a,&b);
            sum=0;
            for(j=a;j<=b;j++){
                if(j%2!=0){
                    sum+=j;
                }
            }
            printf("Case %d: %d\n",i,sum);
        }
    }
    return 0;
}
