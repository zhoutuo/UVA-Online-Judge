#include <cstdio>
using namespace std;

int grades[1000];

int main()
{
    int c;
    scanf("%d", &c);
    while(c--)
    {
        int n;
        scanf("%d", &n);
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &grades[i]);
            sum += grades[i];
        }
        float average = float(sum) / n;
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            if(grades[i] > average)
            {
                ++count;
            }
        }

        float res = (float)count * 100 / n ;

        printf("%.3f%%\n", res);


    }
}
