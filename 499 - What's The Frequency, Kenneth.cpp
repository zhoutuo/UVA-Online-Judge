#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

struct couple
{
	char ch;
	int count;
};

bool cmp(const couple& a, const couple& b)
{
	if(a.count > b.count)
	{
		return true;
	}
	else if(a.count == b.count)
	{
		return a.ch < b.ch ? true : false;
	}
	else
	{
		return false;
	}
}

void init(couple table[52])
{
	for(int i = 0; i < 26; ++i)
	{
		table[i].ch = 'A' + i;
		table[i].count = 0;
	}

	for(int i = 26; i < 52; ++i)
	{
		table[i].ch = 'a' + i - 26;
		table[i].count = 0;
	}
}

int main()
{
	char buffer[1000];
	couple table[52];


	init(table);


	while(gets(buffer) != NULL)
	{
		for(int i = 0; buffer[i] != '\0'; ++i)
		{
			if(islower(buffer[i]))
			{
				++table[buffer[i] - 'a' + 26].count ;
			}
			else if(isupper(buffer[i]))
			{
				++table[buffer[i] - 'A'].count ;
			}
		}


		sort(table, table + 52, cmp);
		int max = table[0].count;
		for(int i = 0; i < 52; ++i)
		{
			if(table[i].count == max)
			{
				printf("%c", table[i].ch);
			}
			else
			{
				break;
			}
		}
		printf(" %d\n", max);

		init(table);


	}

}
