#include <cstdio>
using namespace std;

int main()
{
    int bin[3][3];// in "BGC" color
    int moves[3][3];// in "BGC" color

    char finalOrder[4];
    finalOrder[3] = '\0';
    int finalMoves;
    //char defaultColor[3] = {'B', 'G', 'C'};
    int potentialMoves;

    while(scanf("%d", &bin[0][0]) != EOF)
    {
        scanf("%d %d %d %d %d %d %d %d", &bin[0][1], &bin[0][2], &bin[1][0], &bin[1][1],
              &bin[1][2], &bin[2][0], &bin[2][1], &bin[2][2]);

        finalMoves = 900000000;

        //calculate the matrix of movement
        //input: 1 2 3 4 5 6 7 8 9
        //if the first bin is B, the usage is 5, G => 4, C => 3
        //if the second B => 11 G =>10 C => 9
        //if third B => 17 G => 16 C => 15
        //select the minimal legal combination

        //first bin => second => third
        for(int i = 0; i < 3; ++i)
        {
            moves[i][0] = bin[i][1] + bin[i][2];
            moves[i][1] = bin[i][0] + bin[i][2];
            moves[i][2] = bin[i][0] + bin[i][1];
        }

        //selection, color order is bgc
        //bcg
        potentialMoves = (moves[0][0] + moves[1][2] + moves[2][1]);
        if(potentialMoves < finalMoves)
        {
            finalMoves = potentialMoves;
            finalOrder[0] = 'B';
            finalOrder[1] = 'C';
            finalOrder[2] = 'G';
        }


        //bgc
        potentialMoves = (moves[0][0] + moves[1][1] + moves[2][2]);
        if(potentialMoves < finalMoves)
        {
            finalMoves = potentialMoves;
            finalOrder[0] = 'B';
            finalOrder[1] = 'G';
            finalOrder[2] = 'C';

        }


        //CBG
        potentialMoves = (moves[0][2] + moves[1][0] + moves[2][1]);
        if(potentialMoves < finalMoves)
        {
            finalMoves = potentialMoves;
            finalOrder[0] = 'C';
            finalOrder[1] = 'B';
            finalOrder[2] = 'G';

        }


        //CGB
        potentialMoves = (moves[0][2] + moves[1][1] + moves[2][0]);
        if(potentialMoves < finalMoves)
        {
            finalMoves = potentialMoves;
            finalOrder[0] = 'C';
            finalOrder[1] = 'G';
            finalOrder[2] = 'B';
        }

        //GBC
        potentialMoves = (moves[0][1] + moves[1][0] + moves[2][2]);
        if(potentialMoves < finalMoves)
        {
            finalMoves = potentialMoves;
            finalOrder[0] = 'G';
            finalOrder[1] = 'B';
            finalOrder[2] = 'C';
        }

        //GCB
        potentialMoves = (moves[0][1] + moves[1][2] + moves[2][0]);
        if(potentialMoves < finalMoves)
        {
            finalMoves = potentialMoves;
            finalOrder[0] = 'G';
            finalOrder[1] = 'C';
            finalOrder[2] = 'B';

        }
        printf("%s %d\n", finalOrder, finalMoves);

    }
}
