#include <cstdio>
#include <cstring>
using namespace std;

char matrix[102][102];
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};


int count(int i, int j)
{
    int sum = 0;
    for(int x = 0; x < 8; ++x)
    {
        if(matrix[i + dx[x]][j + dy[x]] == '*')
        {
            ++sum;
        }
    }
    return sum;
}

int main()
{
    int m, n;
    int index = 1;

    while(scanf("%d %d", &m, &n))
    {
        if(m == 0 && n == 0)
        {
            break;
        }
        else
        {
            if(index != 1)
            {
                printf("\n");
            }

        }

        memset(matrix, '.', sizeof(matrix));
        for(int i = 1; i <= m; ++i)
        {
            getchar();
            for(int j = 1; j <= n; ++j)
            {
                scanf("%c", &matrix[i][j]);
            }
        }

        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(matrix[i][j] == '.')
                {
                    matrix[i][j] = count(i, j) + '0';
                }
            }
        }

        printf("Field #%d:\n", index++);
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    }
}
