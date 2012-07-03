#include <cstdio>
using namespace std;


int main()
{
    int n;
    while(scanf("%d", &n))
    {
        if(n == 0)
        {
            break;
        }
        else
        {
            int res;
            if(n <= 100)
            {
                res = 91;
            }
            else
            {
                res = n - 10;
            }
            printf("f91(%d) = %d\n", n, res);
        }
    }
}

