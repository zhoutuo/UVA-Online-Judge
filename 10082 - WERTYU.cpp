#include <cstdio>
#include <map>
using namespace std;

typedef pair <char, char> cPair;

int main()
{
    map <char, char> table;
    table.insert(cPair('1', '`'));
    table.insert(cPair('2', '1'));
    table.insert(cPair('3', '2'));
    table.insert(cPair('4', '3'));
    table.insert(cPair('5', '4'));
    table.insert(cPair('6', '5'));
    table.insert(cPair('7', '6'));
    table.insert(cPair('8', '7'));
    table.insert(cPair('9', '8'));
    table.insert(cPair('0', '9'));
    table.insert(cPair('-', '0'));
    table.insert(cPair('=', '-'));
    table.insert(cPair('S', 'A'));
    table.insert(cPair('D', 'S'));
    table.insert(cPair('F', 'D'));
    table.insert(cPair('G', 'F'));
    table.insert(cPair('H', 'G'));
    table.insert(cPair('J', 'H'));
    table.insert(cPair('K', 'J'));
    table.insert(cPair('L', 'K'));
    table.insert(cPair(';', 'L'));
    table.insert(cPair('\'', ';'));
    table.insert(cPair('X', 'Z'));
    table.insert(cPair('C', 'X'));
    table.insert(cPair('V', 'C'));
    table.insert(cPair('B', 'V'));
    table.insert(cPair('N', 'B'));
    table.insert(cPair('M', 'N'));
    table.insert(cPair(',', 'M'));
    table.insert(cPair('.', ','));
    table.insert(cPair('/', '.'));
    table.insert(cPair('W', 'Q'));
    table.insert(cPair('E', 'W'));
    table.insert(cPair('R', 'E'));
    table.insert(cPair('T', 'R'));
    table.insert(cPair('Y', 'T'));
    table.insert(cPair('U', 'Y'));
    table.insert(cPair('I', 'U'));
    table.insert(cPair('O', 'I'));
    table.insert(cPair('P', 'O'));
    table.insert(cPair('[', 'P'));
    table.insert(cPair(']', '['));
    table.insert(cPair('\\', ']'));


    char tmp;
    while(scanf("%c", &tmp) != EOF)
    {
        map<char, char>::iterator res = table.find(tmp);
        if(res != table.end())
        {
            printf("%c", (*res).second);
        }
        else
        {
            printf("%c", tmp);
        }
    }
}
