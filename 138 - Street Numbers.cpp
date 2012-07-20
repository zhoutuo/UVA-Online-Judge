#include <cstdio>
using namespace std;



int main()
{
    int count = 10;

    long long left_sum = 0;
    long long right_sum = 2;
    int j = 3;

    for(long long k = 2; count > 0; ++k)
    {
        left_sum += k - 1;
        right_sum -=  k;

        for(; right_sum < left_sum; ++j)
        {
            right_sum += j;
        }

        if(left_sum == right_sum)
        {
            printf("%10lld%10d\n", k, j - 1);
            --count;
        }
    }

}
