#include <cstdio>
using namespace std;



int main()
{
    char tmp;
    char buffer[2000];
    int count = 0;
    bool flag = false; // false means `` true means ''

    while(scanf("%c", &tmp) != EOF)
    {
        if(tmp == '"')
        {
            if(!flag)
            {
                buffer[count++] = '`';
                buffer[count++] = '`';
            }
            else
            {
                buffer[count++] = '\'';
                buffer[count++] = '\'';
            }
            flag = !flag;
        }
        else
        {
            buffer[count++] = tmp;
        }

        if(count > 1990)
        {
            buffer[count] = '\0';
            printf("%s", buffer);
            count = 0;
        }
    }

    buffer[count] = '\0';
    printf("%s", buffer);


}
