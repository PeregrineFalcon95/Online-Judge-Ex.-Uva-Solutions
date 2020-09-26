#include<bits/stdc++.h>
#define pi printf
#define sc scanf
#define lld long long int
#define br break
int main()
{
    char str[1000005];
    while(gets(str))
    {
        lld l,i,ar[55];
        for(i=0;i<55;i++)ar[i]=0;
        l=strlen(str);
        for(i=0;i<l;i++)
        {
            switch (str[i])
            {
            case 'A':
                ar[0]++;
                br;
            case 'B':
                ar[1]++;
                br;
            case 'C':
                ar[2]++;
                br;
            case 'D':
                ar[3]++;
                br;
            case 'E':
                ar[4]++;
                br;
            case 'F':
                ar[5]++;
                br;
            case 'G':
                ar[6]++;
                br;
            case 'H':
                ar[7]++;
                br;
            case 'I':
                ar[8]++;
                br;
            case 'J':
                ar[9]++;
                br;
            case 'K':
                ar[10]++;
                br;
            case 'L':
                ar[11]++;
                br;
            case 'M':
                ar[12]++;
                br;
            case 'N':
                ar[13]++;
                br;
            case 'O':
                ar[14]++;
                br;
            case 'P':
                ar[15]++;
                br;
            case 'Q':
                ar[16]++;
                br;
            case 'R':
                ar[17]++;
                br;
            case 'S':
                ar[18]++;
                br;
            case 'T':
                ar[19]++;
                br;
            case 'U':
                ar[20]++;
                br;
            case 'V':
                ar[21]++;
                br;
            case 'W':
                ar[22]++;
                br;
            case 'X':
                ar[23]++;
                br;
            case 'Y':
                ar[24]++;
                br;
            case 'Z':
                ar[25]++;
                br;
            case 'a':
                ar[26]++;
                br;
            case 'b':
                ar[27]++;
                br;
            case 'c':
                ar[28]++;
                br;
            case 'd':
                ar[29]++;
                br;
            case 'e':
                ar[30]++;
                br;
            case 'f':
                ar[31]++;
                br;
            case 'g':
                ar[32]++;
                br;
            case 'h':
                ar[33]++;
                br;
            case 'i':
                ar[34]++;
                br;
            case 'j':
                ar[35]++;
                br;
            case 'k':
                ar[36]++;
                br;
            case 'l':
                ar[37]++;
                br;
            case 'm':
                ar[38]++;
                br;
            case 'n':
                ar[39]++;
                br;
            case 'o':
                ar[40]++;
                br;
            case 'p':
                ar[41]++;
                br;
            case 'q':
                ar[42]++;
                br;
            case 'r':
                ar[43]++;
                br;
            case 's':
                ar[44]++;
                br;
            case 't':
                ar[45]++;
                br;
            case 'u':
                ar[46]++;
                br;
            case 'v':
                ar[47]++;
                br;
            case 'w':
                ar[48]++;
                br;
            case 'x':
                ar[49]++;
                br;
            case 'y':
                ar[50]++;
                br;
            case 'z':
                ar[51]++;
                br;
            }
        }
            lld te=0;
            for(i=0;i<51;i++)if(ar[i]>te)
                te=ar[i];

            if(ar[0]==te)
                pi("A");
            if(ar[1]==te)
                pi("B");
            if(ar[2]==te)
                pi("C");
            if(ar[3]==te)
                pi("D");
            if(ar[4]==te)
                pi("E");
            if(ar[5]==te)
                pi("F");
            if(ar[6]==te)
                pi("G");
            if(ar[7]==te)
                pi("H");
            if(ar[8]==te)
                pi("I");
            if(ar[9]==te)
                pi("J");
            if(ar[10]==te)
                pi("K");
            if(ar[11]==te)
                pi("L");
            if(ar[12]==te)
                pi("M");
            if(ar[13]==te)
                pi("N");
            if(ar[14]==te)
                pi("O");
            if(ar[15]==te)
                pi("P");
            if(ar[16]==te)
                pi("Q");
            if(ar[17]==te)
                pi("R");
            if(ar[18]==te)
                pi("S");
            if(ar[19]==te)
                pi("T");
            if(ar[20]==te)
                pi("U");
            if(ar[21]==te)
                pi("V");
            if(ar[22]==te)
                pi("W");
            if(ar[23]==te)
                pi("X");
            if(ar[24]==te)
                pi("Y");
            if(ar[25]==te)
                pi("Z");
            if(ar[26]==te)
                pi("a");
            if(ar[27]==te)
                pi("b");
            if(ar[28]==te)
                pi("c");
            if(ar[29]==te)
                pi("d");
            if(ar[30]==te)
                pi("e");
            if(ar[31]==te)
                pi("f");
            if(ar[32]==te)
                pi("g");
            if(ar[33]==te)
                pi("h");
            if(ar[34]==te)
                pi("i");
            if(ar[35]==te)
                pi("j");
            if(ar[36]==te)
                pi("k");
            if(ar[37]==te)
                pi("l");
            if(ar[38]==te)
                pi("m");
            if(ar[39]==te)
                pi("n");
            if(ar[40]==te)
                pi("o");
            if(ar[41]==te)
                pi("p");
            if(ar[42]==te)
                pi("q");
            if(ar[43]==te)
                pi("r");
            if(ar[44]==te)
                pi("s");
            if(ar[45]==te)
                pi("t");
            if(ar[46]==te)
                pi("u");
            if(ar[47]==te)
                pi("v");
            if(ar[48]==te)
                pi("w");
            if(ar[49]==te)
                pi("x");
            if(ar[50]==te)
                pi("y");
            if(ar[51]==te)
                pi("z");
            printf(" %lld\n",te);
    }
    return 0;
}

