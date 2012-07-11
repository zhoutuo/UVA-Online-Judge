#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int sum, difference;
        scanf("%d %d", &sum, &difference);

        int tmp = sum - difference;
        if(tmp >= 0 && tmp >> 1 << 1 == tmp)
        {
            int b = tmp >> 1;
            int a = difference + b;
            printf("%d %d\n", a, b);
        }
        else
        {
            printf("impossible\n");
        }
    }
}
