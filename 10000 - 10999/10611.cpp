#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    while(scanf("%d",&n)==1)
    {
        int lady[n];
        for(int i=0; i<n; i++)scanf("%d",&lady[i]);
        scanf("%d",&q);
        int luchu[q];
        for(int i=0; i<q; i++)scanf("%d",&luchu[i]);
        for(int k=0; k<q; k++)
        {
            int left,right,minimum=0,maximum=n-1,middle;
            int luiccha=luchu[k];
            while(minimum<=maximum)
            {
                middle=(minimum+maximum)/2;
                if(lady[middle]==luiccha)maximum=middle-1;
                else if(lady[middle]>luiccha)maximum=middle-1;
                else minimum=middle+1;
            }
            if(maximum<0)maximum++;
            left=maximum;
            minimum=0,maximum=n-1;
            while(minimum<=maximum)
            {
                middle=(minimum+maximum)/2;
                if(lady[middle]==luiccha)minimum=middle+1;
                else if(lady[middle]>luiccha)maximum=middle-1;
                else minimum=middle+1;
            }
            if(minimum>=n)minimum--;
            right=minimum;
            if(lady[left]==luiccha&&left!=0)printf("%d ",lady[left-1]);
            if(lady[left]!=luiccha)printf("%d ",lady[left]);
            if(lady[left]==luiccha&&left==0)printf("X ");
            if(lady[right]==luiccha&&right!=n-1)printf("%d\n",lady[right+1]);
            if(lady[right]>luiccha)printf("%d\n",lady[right]);
            if(lady[right]<=luiccha&&right>=n-1)printf("X\n");
        }
    }
    return 0;
}
