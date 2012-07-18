#include <cstdio>
#include <cmath>
using namespace std;
float rec[10][4];

bool inside(float x, float y, int index)
{
    if(x < rec[index][2] && x > rec[index][0])
    {
        if(y < rec[index][1] && y > rec[index][3])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int index = 0;
    while(getchar() == 'r')
    {
        for(int i = 0; i < 4; ++i)
        {
            scanf("%f", &rec[index][i]);
        }
        ++index;
        getchar();
    }

    float x, y;
    int count = 1;
    while(scanf("%f %f", &x, &y))
    {
        if(abs(x - 9999.9) < 0.1&& abs(y - 9999.9) < 0.1)
        {
            break;
        }

        bool flag = false;
        for(int i = 0; i < index; ++i)
        {
            if(inside(x, y, i))
            {
                flag = true;
                printf("Point %d is contained in figure %d\n", count, i + 1);
            }
        }
        if(!flag)
        {
            printf("Point %d is not contained in any figure\n", count);
        }
        ++count;
    }
}
