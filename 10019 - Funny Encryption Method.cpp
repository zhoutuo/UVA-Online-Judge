#include <cstdio>
using namespace std;

const int m1 = 0x00005555;
const int m2 = 0x00003333;
const int m3 = 0x00000f0f;
const int m4 = 0x000000ff;

int pop_count(int num)
{
    int a = num & m1;
    int b = (num >> 1) & m1;
    int c = a + b;

    a = c & m2;
    b = (c >> 2) & m2;
    c = a + b;

    a = c & m3;
    b = (c >> 4) & m3;
    c = a + b;

    a = c & m4;
    b = (c >> 8) & m4;
    c = a + b;

    return c;

}

int sparse_count(int num)
{
    int sum = 0;
    for(int i = 1; i <= num; i <<= 1)
    {
        if(num & i)
        {
            ++sum;
        }
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

		int b1 = pop_count(m);

		int b2 = 0;
		for(int i = 0; i < 4; ++i)
		{
			int last = m % 10;
			m /= 10;

            b2 += sparse_count(last);
		}

		printf("%d %d\n", b1, b2);
	}
}
