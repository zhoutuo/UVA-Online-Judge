#include <cstdio>
using namespace std;

int main()
{
    long long n;
    while(scanf("%lld", &n))
    {
        if(n < 0)
        {
            break;
        }
        long long sum = 1;
        sum += (n * n + n) >> 1;
        printf("%lld\n", sum);
    }
}
