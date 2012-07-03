#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

struct member
{
    char ch;
    int number;
};

member table[26];

bool cmp(member a, member b)
{
	if(a.number > b.number)
	{
		return true;
	}
	else if(a.number == b.number)
	{
		return (a.ch < b.ch ? true : false);
	}
	else
	{
		return false;
	}
}

int main()
{
	for(int i = 0; i < 26; ++i)
	{
		table[i].ch = i + 'A';
		table[i].number = 0;
	}

	int n; char buffer[1000];
	scanf("%d", &n);
    getchar();

	while(n--)
	{

	    scanf("%[^\n]", buffer);
	    getchar();
	    for(int i = 0; buffer[i] != '\0'; ++i)
        {
            char tmp = buffer[i];
            if(isalpha(tmp))
            {
                ++table[toupper(tmp) - 'A'].number;
            }
        }

	}
	sort(table, table + 26, cmp);
	for(int i = 0; i < 26; ++i)
    {
        if(table[i].number != 0)
        {
            printf("%c %d\n", table[i].ch, table[i].number);
        }
        else
        {
            break;
        }
    }
}
