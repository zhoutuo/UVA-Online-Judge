#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct bignum
{
	char buffer[1050];
	int length;
};

bignum ff[5001];

bignum add(bignum& a, bignum& b)
{
	bignum res;

	int len1 = a.length;
	int len2 = b.length;

	bignum* shorter;
	bignum* longer;

    if(len1 > len2)
    {
        shorter = &b;
        longer = &a;
    }
    else
    {
        shorter = &a;
        longer = &b;
    }

    memset(shorter->buffer + shorter->length, 0, sizeof(char) * (longer->length - shorter->length));

	int rest = 0;
	res.length = longer->length;
	for(int i = 0; i < longer->length; ++i)
	{
		res.buffer[i] = a.buffer[i] + b.buffer[i] + rest;
		if(res.buffer[i] > 9)
		{
			res.buffer[i] -= 10;
			rest = 1;
		}
		else
		{
			rest = 0;
		}
	}

	if(rest == 1)
	{
		res.buffer[res.length] = 1;
		++res.length;
	}

	return res;
}

int main()
{
	int num;
	ff[0].buffer[0] = 0;
	ff[0].length = 1;

	ff[1].buffer[0] = 1;
	ff[1].length = 1;

	for(int i = 2; i <= 5000; ++i)
	{
		ff[i] = add(ff[i - 1], ff[i - 2]);
	}

	while(scanf("%d", &num) != EOF)
	{
		printf("The Fibonacci number for %d is ", num);
		bignum res = ff[num];
		for(int i = res.length - 1; i >= 0; --i)
		{
			printf("%d", res.buffer[i]);
		}
		printf("\n");
	}
}
