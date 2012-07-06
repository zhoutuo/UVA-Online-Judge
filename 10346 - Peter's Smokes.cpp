#include <cstdio>
using namespace std;

int main()
{
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF)
    {
        int sum = n;
        int butt = n;
        while(butt >= k)
        {
            int res = butt / k;
            sum += res;
            butt = res + butt % k;
        }
        printf("%d\n", sum);
    }
}
