#include <cstdio>
using namespace std;

int matrix[100][100];
bool flag_vertical[100];
bool flag_horizontal[100];

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
            for(int j = 0; j < n; ++j)
            {
                scanf("%d", &matrix[i][j]);
            }
        }

        int sum_vertical = 0;
        int sum_horizontal = 0;

        for(int i = 0; i < n; ++i)
        {
            int sum = 0;
            for(int j = 0; j < n; ++j)
            {
                sum ^= matrix[i][j];
            }

            if(sum == 0)
            {
                flag_horizontal[i] = true;
            }
            else
            {
                ++sum_horizontal;
                flag_horizontal[i] = false;

                if(sum_horizontal > 1)
                {
                    break;
                }
            }
        }

        for(int i = 0; i < n; ++i)
        {
            int sum = 0;
            for(int j = 0; j < n; ++j)
            {
                sum ^= matrix[j][i];
            }

            if(sum == 0)
            {
                flag_vertical[i] = true;
            }
            else
            {
                ++sum_vertical;
                flag_vertical[i] = false;

                if(sum_vertical > 1)
                {
                    break;
                }
            }
        }

        if(sum_vertical == 0 && sum_horizontal == 0)
        {
            printf("OK\n");
        }
        else if(sum_vertical == 1 && sum_horizontal == 1)
        {
            int index_horizontal = -1;
            int index_vertical = -1;
            for(int i = 0; i < n; ++i)
            {
                if(!flag_horizontal[i])
                {
                    index_horizontal = i + 1;
                    break;
                }

            }

            for(int i = 0; i < n; ++i)
            {
                if(!flag_vertical[i])
                {
                    index_vertical = i + 1;
                    break;
                }

            }

            printf("Change bit (%d,%d)\n", index_horizontal, index_vertical);
        }
        else
        {
            printf("Corrupt\n");
        }

    }
}
