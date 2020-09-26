#include<bits/stdc++.h>
using namespace std;
void converter(string token);
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    //cin.ignore();
    for(int i=1; i<=t;)
    {
        string code;
        getline(cin,code);
        if(i!=1)printf("\n");
        string token;
        int position=0;
        printf("Message #%d\n",i++);
        stringstream ss(code);
        while(ss>>token)
        {
            converter(token);
            position+=token.size()+1;
            while(position<code.size()&&code[position]==' '){printf(" ");position++;}
        }
        printf("\n");
    }
    return 0;
}
void converter(string token)
{
    if(token==".-")printf("A");
    else if(token==".---")printf("J");
    else if(token=="...")printf("S");
    else if(token==".----")printf("1");
    else if(token=="-...")printf("B");
    else if(token=="---")printf("O");
    else if(token=="..-.")printf("F");
    else if(token=="-....-")printf("-");
    else if(token=="-.-.--")printf("!");
    else if(token==".....")printf("5");
    else if(token==".--")printf("W");
    else if(token=="-.")printf("N");
    else if(token==".")printf("E");
    else if(token==".-.-.")printf("+");
    else if(token==".----.")printf("'");
    else if(token=="....-")printf("4");
    else if(token=="...-")printf("V");
    else if(token=="--")printf("M");
    else if(token=="-..")printf("D");
    else if(token=="-...-")printf("=");
    else if(token=="..--..")printf("?");
    else if(token=="...--")printf("3");
    else if(token=="..-")printf("U");
    else if(token==".-..")printf("L");
    else if(token=="-.-.")printf("C");
    else if(token=="-.-.-.")printf(";");
    else if(token=="--..--")printf(",");
    else if(token=="..---")printf("2");
    else if(token=="-")printf("T");
    else if(token=="-.-")printf("K");
    else if(token=="-..-")printf("X");
    else if(token=="-....")printf("6");
    else if(token=="-..-.")printf("/");
    else if(token=="..--.-")printf("_");
    else if(token=="--.")printf("G");
    else if(token==".--.")printf("P");
    else if(token=="-.--")printf("Y");
    else if(token=="--...")printf("7");
    else if(token=="-.--.")printf("(");
    else if(token==".-..-.")printf("\"");
    else if(token=="....")printf("H");
    else if(token=="--.-")printf("Q");
    else if(token=="--..")printf("Z");
    else if(token=="-----")printf("0");
    else if(token=="----.")printf("9");
    else if(token==".-...")printf("&");
    else if(token==".-.")printf("R");
    else if(token=="..")printf("I");
    else if(token==".--.-.")printf("@");
    else if(token=="-.--.-")printf(")");
    else if(token=="---..")printf("8");
    else if(token=="---...")printf(":");
    else if(token==".-.-.-")printf(".");
}
