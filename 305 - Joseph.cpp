#include <cstdio>
#include <cstring>
using namespace std;

int input[14];

bool test_m(int k, int m)
{
    int total = k << 1;
    int cur = 0;

    do
    {
        cur = (cur + m - 1) % total;
        --total;
    }while(cur >= k);

    if(total == k - 1)
    {
        return true;
    }
    else
    {
        return false;
    }

}


int main()
{
    for(int k = 1; k < 14; ++k)
    {
        int modifier = 2;
        for(int m = k + 1;; ++m)
        {
//            if(m == modifier * k + 1)
//            {
//                modifier += 2;
//                m += k - 1;
//                continue;
//            }

            if(test_m(k, m))
            {

                input[k] = m;
                //printf("%d\n", m);
                break;
            }
        }
    }

    int k;
    while(scanf("%d", &k))
    {
        if(k == 0)
        {
            break;
        }
        else
        {
            printf("%d\n", input[k]);
        }
    }
}
