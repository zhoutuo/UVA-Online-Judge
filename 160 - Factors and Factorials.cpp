#include <cstdio>
using namespace std;

int prime_table[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
                    59, 61, 67, 71, 73, 79, 83, 89, 97};

int main()
{
    int n;
    while(scanf("%d", &n))
    {
        if(n == 0)
        {
            break;
        }

        int num[25] = {0};
        for(int j = 2; j <= n; ++j)
        {
            int tmp = j;
            for(int i = 0; tmp != 1; ++i)
            {
                while(tmp % prime_table[i] == 0)
                {
                    ++num[i];
                    tmp /= prime_table[i];
                }
            }
        }

        printf("%3d! =", n);
        int sum = 0;
        for(int i = 0; i < 25; ++i)
        {
            if(num[i] != 0)
            {
                ++sum;

                if(sum == 16)
                {
                    printf("      ");
                }

                printf("%3d", num[i]);


                if(sum == 15)
                {
                    printf("\n");
                }


            }
        }

        if(sum != 15)
        {
            printf("\n");
        }


    }


}
