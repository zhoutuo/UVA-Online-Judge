#include <cstdio>
#include <cmath>

using namespace std;

long long get_reverse(long long num)
{
	int len = log10(num);
	long long reverse = 0;
	for(int index = len; index >= 0; --index)
	{
		int mod = num % 10;
		num /= 10;
		reverse += mod * pow(10, index);
	}

	return reverse;
}

void itoa(long long data, char* buffer, int len)
{
    for(int i = 0; i < len; ++i)
    {
        buffer[i] = data % 10;
        data /= 10;
    }
}

bool is_palindrome(long long num)
{
	int len = log10(num);
	char buffer[15];
	itoa(num, buffer, len + 1);
	for(int i = 0 ; i <= len / 2; ++i)
	{
		if(buffer[i] != buffer[len - i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		long long original;
		scanf("%lld", &original);
		int count = 0;
		do
		{
		    long long rev = get_reverse(original);
			original += rev;
			++count;
		}while(!is_palindrome(original));
		printf("%d %lld\n", count, original);
	}


}
