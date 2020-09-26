#include<stdio.h>
#include<string.h>
int main()
{
    char str[10000];
    gets(str);
    int i,a=strlen(str);
    for(i=0;i<a;i++)
    {
        if(str[i]==']')
            str[i]='p';
        else if(str[i]=='[')
            str[i]=str[i]='o';
        else if(str[i]=='p'||str[i]=='P')
            str[i]='i';
        else if(str[i]=='o'||str[i]=='O')
            str[i]='u';
        else if(str[i]=='i'||str[i]=='I')
            str[i]='y';
        else if(str[i]=='u'||str[i]=='U')
            str[i]='t';
        else if(str[i]=='y'||str[i]=='Y')
            str[i]='r';
        else if(str[i]=='t'||str[i]=='T')
            str[i]='e';
        else if(str[i]=='r'||str[i]=='R')
            str[i]='w';
        else if(str[i]=='e'||str[i]=='E')
            str[i]='q';
        else if(str[i]==34||str[i]==39)
            str[i]='l';
        else if(str[i]==58||str[i]==59)
            str[i]='k';
        else if(str[i]=='l'||str[i]=='L')
            str[i]='j';
        else if(str[i]=='k'||str[i]=='K')
            str[i]='h';
        else if(str[i]=='j'||str[i]=='J')
            str[i]='g';
        else if(str[i]=='h'||str[i]=='H')
            str[i]='f';
        else if(str[i]=='g'||str[i]=='G')
            str[i]='d';
        else if(str[i]=='f'||str[i]=='F')
            str[i]='s';
        else if(str[i]=='d'||str[i]=='D')
            str[i]='a';
        else if(str[i]=='.'||str[i]=='>')
            str[i]='m';
        else if(str[i]==','||str[i]=='<')
            str[i]='n';
        else if(str[i]=='m'||str[i]=='M')
            str[i]='b';
        else if(str[i]=='n'||str[i]=='N')
            str[i]='v';
        else if(str[i]=='b'||str[i]=='B')
            str[i]='c';
        else if(str[i]=='v'||str[i]=='V')
            str[i]='x';
        else if(str[i]=='c'||str[i]=='C')
            str[i]='z';
    }
    printf("%s\n",str);
    return 0;
}
