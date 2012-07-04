#include <cstdio>
#include <iostream>


int prime_factors[] = {2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 37, 41, 43, 47};


int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m))
	{
		if(n == 0 && m == 0)
		{
			break;
		}

		int larger = std::max(m, n - m);
		int less = n - larger;

		int c = 1;

		int factors[14] = {0};

		for(int i = 2; i <= less; ++i)
		{
			int tmp = i;
			int index = 0;
			while(tmp != 1)
			{
				while(tmp % prime_factors[index] == 0)
				{
					tmp /= prime_factors[index];
					++factors[index];
				}

                ++index;
			}
		}

		for(int i = larger + 1; i <= n; ++i)
		{
			int tmp = i;

            for(int j = 0; j < 14; ++j)
            {
                while(factors[j] > 0 && tmp % prime_factors[j] == 0)
                {
                    tmp /= prime_factors[j];
                    --factors[j];
                }

                if(tmp < prime_factors[j])
                {
                    break;
                }
            }

            c *= tmp;

		}



		printf("%d things taken %d at a time is %d exactly.\n", n, m, c);
	}
}
