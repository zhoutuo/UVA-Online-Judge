#include <cstdio>
#include <cmath>
using namespace std;

bool is_prime(int num)
{
    int root = sqrt(num);

    for(int i = 3; i <= root; i += 2)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    while(scanf("%d", &n))
    {
        if(n == 0)
        {
            break;
        }

        int sum = 0;
        int half = n >> 1;

        if(n == 4)
        {
            printf("1\n");
            continue;
        }


        for(int i = 3; i <= half; i += 2)
        {
            if(is_prime(i) && is_prime(n - i))
            {
                ++sum;
            }
        }

        printf("%d\n", sum);
    }
}
