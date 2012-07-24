#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char input[13];
int rotation[][6] = {
    {1, 2, 3, 4, 5, 6},
    {1, 4, 2, 5, 3, 6},
    {1, 5, 4, 3, 2, 6},
    {1, 3, 5, 2, 4, 6},
    {2, 6, 3, 4, 1, 5},
    {2, 4, 6, 1, 3, 5},
    {2, 1, 4, 3, 6, 5},
    {2, 3, 1, 6, 4, 5},
    {3, 1, 2, 5, 6, 4},
    {3, 5, 1, 6, 2, 4},
    {3, 6, 5, 2, 1, 4},
    {3, 2, 6, 1, 5, 4},
    {6, 5, 3, 4, 2, 1},
    {6, 3, 2, 5, 4, 1},
    {6, 2, 4, 3, 5, 1},
    {6, 4, 5, 2, 3, 1},
    {5, 1, 3, 4, 6, 2},
    {5, 3, 6, 1, 4, 2},
    {5, 6, 4, 3, 1, 2},
    {5, 4, 1, 6, 3, 2},
    {4, 6, 2, 5, 1, 3},
    {4, 2, 1, 6, 5, 3},
    {4, 1, 5, 2, 6, 3},
    {4, 5, 6, 1, 2, 3},
};

void rotate(char* str, int n)
{
    for(int i = 0; i < 6; ++i)
    {
        str[i] = input[rotation[n][i] - 1];
    }
}

bool cmp(char * str)
{
    for(int i = 0; i < 6; ++i)
    {
        if(str[i] != input[6 + i])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    while(scanf("%s", input) != EOF)
    {
        char rotated[6];
        bool is_found = false;
        for(int i = 0; i < 24; ++i)
        {
            rotate(rotated, i);
            if(cmp(rotated))
            {
                is_found = true;
                break;
            }
        }

        if(is_found)
        {
            printf("TRUE\n");
        }
        else
        {
            printf("FALSE\n");
        }
    }
}
