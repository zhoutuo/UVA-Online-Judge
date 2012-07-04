#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    printf("PERFECTION OUTPUT\n");
    int n;
    while(scanf("%d", &n))
    {
        if(n == 0)
        {
            break;
        }
        int sum = 1;
        int root = sqrt(n);


        for(int i = 2; i <= root; ++i)
        {
            if(n % i == 0)
            {
                sum += i;
                sum += n / i;
            }
        }

        if(root * root == n)
        {
            sum -= root;
        }

        if(sum == n)
        {
            printf("%5d  PERFECT\n", n);
        }
        else if(sum > n)
        {
            printf("%5d  ABUNDANT\n", n);
        }
        else
        {
            printf("%5d  DEFICIENT\n", n);
        }

    }
    printf("END OF OUTPUT\n");
}
