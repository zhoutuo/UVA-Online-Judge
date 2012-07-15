#include <cstdio>
using namespace std;

int bit_count(int num)
{
    int sum = 0;
    while(num)
    {
        ++sum;
        num &= num - 1;
    }
    return sum;
}

int main()
{
	int n;
	scanf("%d", &n);


	while(n--)
	{
		int m;
		scanf("%d", &m);

		int b1 = bit_count(m);


		int b2 = 0;
		for(int i = 0; i < 4; ++i)
		{
			int last = m % 10;
			m /= 10;

            b2 += bit_count(last);
		}

		printf("%d %d\n", b1, b2);
	}
}
