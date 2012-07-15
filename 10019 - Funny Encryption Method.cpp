#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);


	while(n--)
	{
		int m;
		scanf("%d", &m);

		int b1 = 0;
		for(int i = 1; i <= m; i <<= 1)
		{
			if(m & i)
			{
				++b1;
			}
		}

		int b2 = 0;
		for(int i = 0; i < 4; ++i)
		{
			int last = m % 10;
			m /= 10;

			for(int j = 1; j <= last; j <<= 1)
			{
				if(last & j)
				{
					++b2;
				}
			}
		}

		printf("%d %d\n", b1, b2);
	}
}
