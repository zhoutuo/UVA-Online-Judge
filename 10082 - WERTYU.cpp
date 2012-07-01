#include <cstdio>
#include <cctype>
using namespace std;

char alphaT[26];

void init()
{
    alphaT['W' - 'A'] = 'Q';
    alphaT['E' - 'A'] = 'W';
    alphaT['R' - 'A'] = 'E';
    alphaT['T' - 'A'] = 'R';
    alphaT['Y' - 'A'] = 'T';
    alphaT['U' - 'A'] = 'Y';
    alphaT['I' - 'A'] = 'U';
    alphaT['O' - 'A'] = 'I';
    alphaT['P' - 'A'] = 'O';
    alphaT['S' - 'A'] = 'A';
    alphaT['D' - 'A'] = 'S';
    alphaT['F' - 'A'] = 'D';
    alphaT['G' - 'A'] = 'F';
    alphaT['H' - 'A'] = 'G';
    alphaT['J' - 'A'] = 'H';
    alphaT['K' - 'A'] = 'J';
    alphaT['L' - 'A'] = 'K';
    alphaT['X' - 'A'] = 'Z';
    alphaT['C' - 'A'] = 'X';
    alphaT['V' - 'A'] = 'C';
    alphaT['B' - 'A'] = 'V';
    alphaT['N' - 'A'] = 'B';
    alphaT['M' - 'A'] = 'N';
}

char res(char ch)
{
    if(isdigit(ch))
    {
        if(ch == '0')
        {
            return '9';
        }
        else if(ch == '1')
        {
            return '`';
        }
        else
        {
            return ch - 1;
        }
    }
    else if(isalpha(ch))
    {
        return alphaT[ch - 'A'];
    }
    else
    {
        switch(ch)
        {
        case '-':
            return '0';
        case '=':
            return '-';
        case '[':
            return 'P';
        case ']':
            return '[';
        case '\\':
            return ']';
        case ';':
            return 'L';
        case '\'':
            return ';';
        case ',':
            return 'M';
        case '.':
            return ',';
        case '/':
            return '.';
        default:
            return ch;
        }
    }

}

int main()
{
    init();
    char tmp;
    while(scanf("%c", &tmp) != EOF)
    {
        printf("%c", res(tmp));
    }
}
