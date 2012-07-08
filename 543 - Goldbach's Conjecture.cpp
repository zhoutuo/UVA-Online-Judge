#include <cstdio>
#include <cmath>
using namespace std;

bool is_prime(int num)
{
    int root = sqrt(num);
    for(int i =  3; i <= root; i += 2)
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

        bool isFound = false;
        //int half = n >> 1;

        for(int i = 3; i < n; i += 2)
        {
            if(is_prime(i) && is_prime(n - i))
            {
                printf("%d = %d + %d\n", n, i, n - i);
                isFound = true;
                break;
            }
        }

        if(!isFound)
        {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
}
