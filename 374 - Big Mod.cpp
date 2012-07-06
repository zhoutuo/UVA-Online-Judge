#include <cstdio>
using namespace std;

int main()
{
    int b, p, m;
    int left[32];
    while(scanf("%d %d %d", &b, &p, &m) != EOF)
    {
        int left_index = 0;

        //special case
        if(p == 0)
        {
            printf("%d\n", 1);
            continue;
        }


        while(true)
        {
            while(b < m && p > 1)
            {
                if(p >> 1 << 1 != p)
                {
                    left[left_index++] = b;
                }
                b *= b;
                p = p >> 1;
            }

            b = b % m;

            if(p == 1)
            {
                break;
            }
        }

        for(int i = 0; i < left_index; ++i)
        {
            b = b * left[i] % m;
        }


        printf("%d\n", b);
    }
}
