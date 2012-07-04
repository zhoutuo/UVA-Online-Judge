#include <cstdio>
#include <iostream>


int triangle[101][102] = {0};


int main()
{
	triangle[0][1] = 1;
	for(int i = 1; i <= 100; ++i)
	{
		for(int j = 1; j <= i + 1; ++j)
		{
			triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
		}
	}

	int n, m;
	while(scanf("%d %d", &n, &m))
	{
		if(n == 0 && m == 0)
		{
			break;
		}

		printf("%d things taken %d at a time is %d exactly.\n", n, m, triangle[n][m + 1]);
	}
}
