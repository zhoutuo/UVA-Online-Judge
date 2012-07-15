#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        int m;
        scanf("%d", &m);

        int b1 = 0;
        int tmp = m;
        for(int i = 0; i < 32; ++i)
        {
            if(tmp & 1)
            {
                ++b1;
            }
            tmp = tmp >> 1;
        }

        int b2 = 0;
        for(int i = 0; i < 4; ++i)
        {
            int last = m % 10;
            m /= 10;

            for(int j = 0; j < 4; ++j)
            {
                if(last & 1)
                {
                    ++b2;
                }
                last = last >> 1;
            }
        }

        printf("%d %d\n", b1, b2);
    }
}
