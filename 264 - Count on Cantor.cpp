#include <cstdio>
#include <iostream>
using namespace std;

int res(int n)
{
	int low = 1;
	int high = n;
	while(low < high - 1)
	{
		long long mid = (low + high) >> 1;
		long long cal = (mid * mid + mid) >> 1;
		if(cal > n)
		{
			high = mid;
		}
		else if(cal == n)
		{
			return mid;
		}
		else
		{
			low = mid;
		}
	}

	return low;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int pre = res(n);
		int rest = n - ((pre * pre + pre) >> 1);
		int numerator = 0;
		int denominator = pre;


		if(rest == 0)
		{
			numerator = 1;

            if(pre >> 1 << 1 == pre)
            {
                swap(numerator, denominator);
            }

		}
		else
		{
			numerator = denominator - rest + 2;
			denominator = rest;

            if(pre >> 1 << 1 != pre)
            {
                swap(numerator, denominator);
            }
		}


		printf("TERM %d IS %d/%d\n", n, numerator, denominator);

	}
}
