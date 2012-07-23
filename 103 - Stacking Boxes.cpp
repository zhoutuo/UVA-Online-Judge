#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int k, n;

struct box
{
    int index;
    int dimensions[10];
};
box boxes[30];
int dp[30];

bool cmp(const box& a, const box& b)
{
    for(int i = 0; i < n; ++i)
    {
        if(a.dimensions[i] < b.dimensions[i])
        {
            return true;
        }
        else if(a.dimensions[i] > b.dimensions[i])
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    return false;
}

bool is_contain(const box& a, const box& b)
{
    for(int i = 0; i < n; ++i)
    {
        if(a.dimensions[i] <= b.dimensions[i])
        {
            return false;
        }
    }
    return true;
}

void print(int i)
{
    int cur = dp[i];
    if(cur != 0)
    {
        for(int j = i - 1; j >= 0; --j)
        {
            if(dp[j] == cur - 1 && is_contain(boxes[i], boxes[j]))
            {
                print(j);
                break;
            }
        }
        printf(" ");
    }

    printf("%d", boxes[i].index);
}

int main()
{

    while(scanf("%d %d", &k, &n) != EOF)
    {
        for(int i = 0; i < k; ++i)
        {
            boxes[i].index = i + 1;
            for(int j = 0; j < n; ++j)
            {
                scanf("%d", &boxes[i].dimensions[j]);
            }

            sort(boxes[i].dimensions, boxes[i].dimensions + n);
        }


        sort(boxes, boxes + k, cmp);

        memset(dp, 0, sizeof(dp));
        int max_count = 0;
        int max_index = 0;

        for(int i = 1; i < k; ++i)
        {
            for(int j = i - 1; j >= 0; --j)
            {
                if(is_contain(boxes[i], boxes[j]))
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                    if(max_count < dp[i])
                    {
                        max_count = dp[i];
                        max_index = i;
                    }

                }
            }
        }


        printf("%d\n", max_count + 1);

        print(max_index);

        printf("\n");


    }
}
