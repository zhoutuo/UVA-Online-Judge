#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t ; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);



        a += (~a & 0x1);
        b -= (~b & 0x1);


        int sum = (a + b) * (b - a + 2);
        sum >>= 2;
        printf("Case %d: %d\n", i, sum);
    }
}
