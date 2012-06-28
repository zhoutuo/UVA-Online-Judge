#include <cstdio>
using namespace std;



int main()
{
    int first, second;
    while(scanf("%d %d", &first, &second))
    {
        if(first == 0 && second == 0)
        {
            break;
        }

        int curCarry = 0;
        int sumOfCarry = 0;

        int digit1;
        int digit2;

        while(1)
        {
            if(first == 0)
            {
                if(curCarry == 0)
                {
                    break;
                }
                else
                {
                    curCarry = 0;
                    first = 1;
                }
            }


            if(second == 0)
            {
                if(curCarry == 0)
                {
                    break;
                }
                else
                {
                    curCarry = 0;
                    second = 1;
                }
            }

            digit1 = first % 10;
            digit2 = second % 10;

            first /= 10;
            second /= 10;

            curCarry = digit1 + digit2 + curCarry;

            if(curCarry >= 10)
            {
                ++sumOfCarry;
                curCarry = 1;
            }
            else
            {
                curCarry = 0;
            }
        }

        if(sumOfCarry == 0)
        {
            printf("No carry operation.\n");
        }
        else if(sumOfCarry == 1)
        {
            printf("1 carry operation.\n");
        }
        else
        {
            printf("%d carry operations.\n", sumOfCarry);
        }



    }
}
