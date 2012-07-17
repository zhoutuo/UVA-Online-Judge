#include <cstdio>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int remainder = 1;
        int len = 1;
        int tmp = 10 % n;
        while(remainder)
        {
            remainder = (remainder * tmp + 1) % n;
            ++len;
        }
        printf("%d\n", len);
    }
}
