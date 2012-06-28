#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int array[3000];
bool set[3000];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        //input
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &array[i]);
        }

        memset(set, 0, sizeof(set));

        //judge
        bool found = false;

        for(int i = 0; i < n - 1; ++i)
        {
            int value = abs(array[i] - array[i + 1]);

            if(value == 0 || value >= n)
            {
                found = true;
                break;
            }

            if(!set[value])
            {
                set[value] = true;
            }
            else
            {
                found = true;
                break;
            }
        }

        //output
        if(!found)
        {
            printf("Jolly\n");
        }
        else
        {
            printf("Not jolly\n");
        }
    }
}
