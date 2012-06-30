#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;


unsigned int get_reverse(unsigned int num)
{
    char buffer[15];
	sprintf(buffer, "%u", num);
    int len = strlen(buffer) - 1;
    unsigned int reverse = 0;
	for(int i = len; i >=0; --i)
    {
        reverse += (buffer[i] - '0') * pow(10, i);
    }
    return reverse;
}

bool is_palindrome(unsigned int num)
{
    char buffer[15];
	sprintf(buffer, "%u", num);
    int len = strlen(buffer) - 1;

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
		unsigned int original;
		scanf("%u", &original);
		int count = 0;
		do
		{
		    unsigned int rev = get_reverse(original);
			original += rev;
			++count;
		}while(!is_palindrome(original));
		printf("%d %u\n", count, original);
	}


}
