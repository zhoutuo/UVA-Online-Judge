#include <cstdio>
#include <cstring>
using namespace std;

char names[10][13];
int money[10];
int n;

int get_index(char name[13])
{
    for(int i = 0; i < n; ++i)
    {
        if(strcmp(names[i], name) == 0)
        {
            return i;
        }
    }

    return -1;

}

int main()
{
    int cases = 1;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", names[i]);
        }

        memset(money, 0, sizeof(money));

        for(int i = 0; i < n; ++i)
        {
            char tmp[13];
            scanf("%s", tmp);
            int cur = get_index(tmp);

            int sum, people;
            scanf("%d", &sum);
            scanf("%d", &people);

            if(people == 0)
            {
                continue;
            }

            int average = sum / people;

            money[cur] -= people * average;


            for(int j = 0; j < people; ++j)
            {
                scanf("%s", tmp);
                int re = get_index(tmp);
                money[re] += average;
            }
        }

        if(cases != 1)
        {
            printf("\n");

        }
        ++cases;
        for(int i = 0; i < n; ++i)
        {
            printf("%s %d\n", names[i], money[i]);
        }
    }
}
