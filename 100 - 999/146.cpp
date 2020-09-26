#include<bits/stdc++.h>
int main()
{
    char str[52];
    while(gets(str))
    {
        if(str[0]=='#')break;
        int i=strlen(str);
        if(std::next_permutation(str,str+i))
            printf("%s\n",str);
        else
            printf("No Successor\n");
    }
    return 0;
}
