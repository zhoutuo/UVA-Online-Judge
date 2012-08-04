#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;


struct card
{
	char suit;
	int value;
};

card cards[10];
char buffer[30];
int tmp[10];



struct priority
{
	int index;
	int value;
};


int change(char ch)
{
	if(isdigit(ch))
	{
		return (ch - '0');
	}
	else
	{
		int res;
		switch(ch)
		{
			case 'T':
				res = 10;
				break;
			case 'J':
				res = 11;
				break;
			case 'Q':
				res = 12;
				break;
			case 'K':
				res = 13;
				break;
			case 'A':
				res = 14;
		}

		return res;
	}
}


int highest()
{
	for(int i = 4; i >= 0; --i)
	{
		if(tmp[i] > tmp[i + 5])
		{
			return 0;
		}
		else if(tmp[i] < tmp[i + 5])
		{
			return 1;
		}

	}
	return 2;
}

priority get_rank(bool flag)
{
	int index = flag ? 5 : 0;
	priority p;



	//whether it fits flush
	bool flush = true;
	char standard = cards[index].suit;
	for(int i = index; i < index + 5; ++i)
	{
		if(cards[i].suit != standard)
		{
			flush = false;
			break;
		}
	}

	//whether it fits straight
	bool straight = true;

	for(int i = index; i < index + 5; ++i)
	{
		tmp[i] = cards[i].value;
	}

	sort(tmp + index, tmp + index + 5);

	for(int i = index; i < index + 4; ++i)
	{
		if(tmp[i] != tmp[i + 1] - 1)
		{
			straight = false;
			break;
		}
	}

	if(flush && straight)
	{
		p.index = 9;
		p.value = tmp[index + 4];
		return p;
	}

	int value_hit_table[15] = {0};

	for(int i = index; i < index + 5; ++i)
	{
		++value_hit_table[tmp[i]];
	}

	//whether it fits four of a kind
	bool four = false;
	bool three = false;
	int two = 0;

	for(int i = 2; i  <= 14; ++i)
	{
		if(!four && value_hit_table[i] == 4)
		{
			four = true;
		}
		else if(!three && value_hit_table[i] == 3)
		{
			three = true;
		}
		else if(two < 2 && value_hit_table[i] == 2)
		{
			++two;
		}
	}

	if(four)
	{
		p.index = 8;
		p.value = tmp[index + 3];
		return p;
	}


	//whether it fits full house

	if(three && two == 1)
	{
		p.index = 7;
		p.value = tmp[index + 2];
		return p;
	}


	if(flush)
	{
		p.index = 6;
		p.value = tmp[index + 4];
		return p;

	}
	else if(straight)
	{
		p.index = 5;
		p.value = tmp[index + 4];
		return p;
	}

	//three of a kind

	if(three)
	{
		p.index = 4;
		p.value = tmp[index + 2];
		return p;
	}


	//two pairs

	if(two == 2)
	{
		p.index = 3;
	}
	else if(two == 1)
	{
		p.index = 2;
	}
	else
	{
		p.index = 1;
	}


	return p;


}

int main()
{
    freopen("data.txt","w",stdout);

	while(gets(buffer) != NULL)
	{
		for(int i = 0; i < 10; ++i)
		{
			cards[i].suit = buffer[i * 3 + 1];
			cards[i].value = change(buffer[i * 3]);
		}


		priority black = get_rank(false);
		priority white = get_rank(true);

		if(black.index > white.index)
		{
			printf("Black wins.\n");
		}
		else if(black.index < white.index)
		{
			printf("White wins.\n");
		}
		else
		{
			if(black.index == 6 || black.index == 5 || black.index == 1)
			{
				int res = highest();
				if(res == 0)
				{
					printf("Black wins.\n");
				}
				else if(res == 1)
				{
					printf("White wins.\n");
				}
				else
				{
					printf("Tie.\n");
				}

			}
			else if(black.index == 3)
			{
				int bigger = 0, less = 0;
				int sum = 0;
				for(int i = 4; i >= 0 ; --i)
				{
					if(tmp[i] == tmp[i - 1])
					{
						if(bigger == 0)
						{
							bigger = tmp[i];
						}
						else
						{
							less = tmp[i];
						}
					}
					sum += tmp[i];
				}



				int bigger2 = 0, less2 = 0;
				int sum2 = 0;
				for(int i = 9; i >= 5 ; --i)
				{
					if(tmp[i] == tmp[i - 1])
					{
						if(bigger2 == 0)
						{
							bigger2 = tmp[i];
						}
						else
						{
							less2 = tmp[i];
						}
					}
					sum2 += tmp[i];
				}


				if(bigger > bigger2)
				{
					printf("Black wins.\n");
				}
				else if(bigger < bigger2)
				{
					printf("White wins.\n");
				}
				else
				{
					if(less > less2)
					{
						printf("Black wins.\n");
					}
					else if(less < less2)
					{
						printf("White wins.\n");
					}
					else
					{
						if(sum > sum2)
						{
							printf("Black wins.\n");
						}
						else if(sum < sum2)
						{
							printf("White wins.\n");
						}
						else
						{
							printf("Tie.\n");
						}
					}
				}

			}
			else if(black.index == 2)
			{
				int one, second;
				for(int i = 0; i < 4; ++i)
				{
					if(tmp[i] == tmp[i + 1])
					{
						one = tmp[i];
						break;
					}
				}
				for(int i = 5; i < 9; ++i)
				{
					if(tmp[i] == tmp[i + 1])
					{
						second = tmp[i];
						break;
					}
				}


				if(one > second)
				{
					printf("Black wins.\n");
				}
				else if(one < second)
				{
					printf("White wins.\n");
				}
				else
				{
					int res = highest();
					if(res == 0)
					{
						printf("Black wins.\n");
					}
					else if(res == 1)
					{
						printf("White wins.\n");
					}
					else
					{
						printf("Tie.\n");
					}
				}
			}
			else
			{
				if(black.value > white.value)
				{
					printf("Black wins.\n");
				}
				else if(black.value < white.value)
				{
					printf("White wins.\n");
				}
				else
				{


					printf("Tie.\n");


				}
			}
		}

	}
}
