#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int board[101][10];
bool flag[101][10];

struct Contestant
{
	int index;
	int solved;
	int penalty;
	bool sub;
};

char buffer[20];
Contestant contestants[101];

bool cmp(const Contestant& a, const Contestant& b)
{
	if(a.solved > b.solved)
	{
		return true;
	}
	else if(a.solved < b.solved)
	{
		return false;
	}
	else
	{
		if(a.penalty < b.penalty)
		{
			return true;
		}
		else if(a.penalty > b.penalty)
		{
			return false;
		}
		else
		{
			//return
			if(a.sub > b.sub)
            {
                return true;
            }
            else if(a.sub < b.sub)
            {
                return false;
            }
            else
            {
                return a.index < b.index;
            }

		}
	}
}

int main()
{
	//freopen("data.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	getchar();
	getchar();
	while(n--)
	{
		memset(board, 0, sizeof(board));
		memset(flag, 0, sizeof(flag));
		memset(contestants, 0, sizeof(contestants));

		for(int i = 0; i <= 100; ++i)
        {
            contestants[i].index = i;
        }

		while(gets(buffer) != NULL)
		{
			if(strlen(buffer) == 0)
			{
				break;
			}

			int contestant, problem, time;
			char l;
			sscanf(buffer, "%d %d %d %c", &contestant, &problem, &time, &l);


			contestants[contestant].sub = true;
			if(l == 'I')
			{
				//check if the problem has been solved
				if(!flag[contestant][problem])
				{
					board[contestant][problem] += 20;
				}
			}
			else if(l == 'C')
			{
				//check if the problem has been solved
				if(!flag[contestant][problem])
				{
					board[contestant][problem] += time;
					flag[contestant][problem] = true;
					contestants[contestant].solved += 1;
					contestants[contestant].penalty += board[contestant][problem];
				}
			}
		}

		sort(contestants, contestants + 101, cmp);

		for(int i = 0;; ++i)
		{
			Contestant cur = contestants[i];
			if(!cur.sub)
			{
				break;
			}
			else
			{
				printf("%d %d %d\n", cur.index, cur.solved, cur.penalty);
			}
		}

		if(n != 0)
        {
            printf("\n");
        }

	}
}
