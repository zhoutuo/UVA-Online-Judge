#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char buffer[100];
    while(scanf("%s", buffer) != EOF)
    {
        int length = strlen(buffer);
        for(int i = 0; i < length >> 1 ; ++i)
        {
            swap(buffer[i], buffer[length - i - 1]);
        }

        char ch = getchar();
        buffer[length] = ch;
        buffer[length + 1] = '\0';
        printf("%s", buffer);
    }
}
