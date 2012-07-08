#include <cstdio>
#include <cstring>
using namespace std;

bool flags[101];

int main()
{
    int n;
    while(scanf("%d", &n))
    {
        if(n == 0)
        {
            break;
        }

        if(n == 13)
        {
            printf("1\n");
        }
        else
        {
            for(int i = 2; ; ++i)
            {
                memset(flags, 0, sizeof(flags));
                int sum = 1;
                flags[1] = true;
                int curPos = 1;
                bool found = false;
                while(1)
                {
                    int tmp = i;
                    for(int j = curPos;; ++j)
                    {
                        if(j == n + 1)
                        {
                            j = 1;
                        }

                        if(!flags[j])
                        {
                            --tmp;
                        }

                        if(tmp == 0)
                        {
                            flags[j] = true;
                            ++sum;
                            curPos = j;
                            //printf("%d ", curPos);
                            break;
                        }
                    }

                    if(curPos == 13)
                    {
                        if(sum == n)
                        {
                            found = true;
                        }
                        break;
                    }

                }

                if(found == true)
                {
                    printf("%d\n", i);
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
}
