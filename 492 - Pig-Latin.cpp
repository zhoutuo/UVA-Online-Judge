#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;


char vowel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

bool is_vowel(char ch)
{
	for(int i = 0; i < 10; ++i)
	{
		if(ch == vowel[i])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	char ch;
    char prefix = '\0';
    bool is_flag;

	while(scanf("%c", &ch) != EOF)
	{


		if(isalpha(ch))
		{
			if(prefix == '\0')
			{
				is_flag = is_vowel(ch);
				prefix = ch;

                if(is_flag)
                {
                    printf("%c", ch);
                }
			}
			else
            {
                printf("%c", ch);
            }


		}
		else
		{
		    if(prefix != '\0')
            {
                if(!is_flag)
                {
                    printf("%c", prefix);
                }

                printf("ay");

                prefix = '\0';
            }

			printf("%c", ch);
		}
	}
}
