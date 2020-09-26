#include<stdio.h>
int main()
{
    int g1,g2,g3,b1,b2,b3,c1,c2,c3,bcg,bgc,cbg,cgb,gbc,gcb;
    while(scanf("%d %d %d %d %d %d %d %d %d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)==9)
    {
        bcg=b2+b3+c1+c3+g1+g2;
        bgc=b2+b3+g1+g3+c1+c2;
        cbg=c2+c3+b1+b3+g1+g2;
        cgb=c2+c3+g1+g3+b1+b2;
        gbc=g2+g3+b1+b3+c1+c2;
        gcb=g2+g3+c1+c3+b1+b2;
        if(bcg<=bgc && bcg<=cbg && bcg<=cgb && bcg<=gbc && bcg<=gcb)
            printf("BCG %d\n",bcg);
        else if(bgc<=cbg && bgc<=cgb && bgc<=gbc && bgc<=gcb)
            printf("BGC %d\n",bgc);
        else if(cbg<=gbc && cbg<=cgb && cbg<=gcb)
            printf("CBG %d\n",cbg);
        else if(cgb<=gbc && cgb<=gcb)
            printf("CGB %d\n",cgb);
        else if(gbc<=gcb)
            printf("GBC %d\n",gbc);
        else
            printf("GCB %d\n",gcb);
    }
    return 0;
}
