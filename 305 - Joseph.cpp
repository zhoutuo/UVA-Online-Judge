#include <cstdio>
#include <cstring>
using namespace std;

int input[14] = {2,
7,
5,
30,
169,
441,
1872,
7632,
1740,
93313,
459901,
1358657,
2504881};




int main()
{

    int k;
    while(scanf("%d", &k))
    {
        if(k == 0)
        {
            break;
        }
        else
        {
            printf("%d\n", input[k]);
        }
    }
}
