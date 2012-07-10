#include <cstdio>
#include <algorithm>
using namespace std;

int nums[10000];


int bi_search(int start, int end, int insert)
{

	while(start <  end)
	{
	    int mid = (start + end) >> 1;
		int value = nums[mid];
		if(value > insert)
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}

    return end;
}

int main()
{
	int index = 0;
	int tmp;
	while(scanf("%d", &tmp) != EOF)
	{
		if(index == 0)
		{
			nums[index++] = tmp;
			printf("%d\n", tmp);
		}
		else
		{

			int pos = bi_search(0, index, tmp);
			for(int i = index - 1; i >= pos; --i)
			{
				nums[i + 1] = nums[i];
			}

			nums[pos] = tmp;
			++index;

			if(index >> 1 << 1 == index)
			{
				int median = (nums[index >> 1] + nums[(index >> 1) - 1]) >> 1;
				printf("%d\n", median);
			}
			else
			{
				printf("%d\n", nums[index >> 1]);
			}
		}
	}
}
