#include <cstdio>
using namespace std;

int main()
{
    int bin[3][3];// in "BGC" order
    char finalOrder[4];
    finalOrder[3] = '\0';
    int finalMoves;
    char defaultColor[3] = {'B', 'G', 'C'};
    char candidateOrder[6][3] = {{'B', 'C', 'G'}, {'B', 'G', 'C'},
    {'C', 'B', 'G'}, {'C', 'G', 'B'}, {'G', 'B', 'C'}, {'G', 'C', 'B'}};
    int potentialMoves;
    while(scanf("%d", &bin[0][0]) != EOF)
    {
        scanf("%d %d %d %d %d %d %d %d", &bin[0][1], &bin[0][2], &bin[1][0], &bin[1][1],
              &bin[1][2], &bin[2][0], &bin[2][1], &bin[2][2]);

        finalMoves = 900000000;

        for(int i = 0; i < 6; ++i)
        {
            potentialMoves = 0;
            for(int j = 0; j < 3; ++j)
            {
                for(int z = 0; z < 3; ++z)
                {
                    if(candidateOrder[i][j] != defaultColor[z])
                    {
                        potentialMoves += bin[j][z];

                    }
                }
            }

            if(potentialMoves < finalMoves)
            {
                finalMoves = potentialMoves;
                for(int j = 0; j < 3; ++j)
                {
                    finalOrder[j] = candidateOrder[i][j];
                }


            }
        }

        printf("%s %d\n", finalOrder, finalMoves);

    }
}
