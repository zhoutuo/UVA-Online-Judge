#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int buffer[1000];


int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &buffer[i]);
        }

        int sum = 0;


        for(int j = 0; j < i; ++j)
        {
            if(buffer[0] < buffer[j])
            {
                ++sum;
            }
        }

        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(buffer[i] < buffer[j])
                {
                    ++sum;
                }
            }
        }


        printf("Minimum exchange operations : %d\n", sum);

    }
}
