#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

double students[1000];

int main()
{
    int n;
    while(scanf("%d", &n))
    {
        if(n == 0)
        {
            break;
        }

        for(int i = 0; i < n; ++i)
        {
            scanf("%lf", &students[i]);
        }

        double sum = 0;

        for(int i = 0; i < n; ++i)
        {
            sum += students[i];
        }

        double average = sum / n;
        average = floor(average * 100 + 0.5) / 100.0;
        double res = 0;
        double res2 = 0;

        for(int i = 0; i < n; ++i)
        {
            if(students[i] > average)
            {
                res += (students[i] - average);
            }
            else
            {
                res2 += (average - students[i]);
            }
        }

        //res = min(res, sum - res);

        printf("$%.2lf\n", min(res, res2));

    }
}
