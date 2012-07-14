#include <cstdio>
#include <iostream>
using namespace std;

int building[5000][3];
int skyline[10000] = {0};
int main()
{
	int index = 0;
	while(scanf("%d %d %d",
	            &building[index][0], &building[index][1], &building[index][2]) != EOF)
	{
		++index;
	}


	for(int i = 0; i < index; ++i)
	{
		int left = building[i][0];
		int height = building[i][1];
		int right = building[i][2];

		for(int j = left; j < right; ++j)
		{
			skyline[j] = max(skyline[j], height);
		}
	}

    int i = 0;

	for(;; ++i)
	{
		if(skyline[i] != skyline[i + 1])
		{
			printf("%d %d", i + 1, skyline[i + 1]);
			++i;
			break;
		}
	}

	for(; i < 9999; ++i)
    {
		if(skyline[i] != skyline[i + 1])
		{
			printf(" %d %d", i + 1, skyline[i + 1]);
		}
    }

    printf("\n");


}
