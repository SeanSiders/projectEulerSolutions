#include <iostream>
#include <cmath>

uint64_t smallestMultipleOfRange(uint64_t min, uint64_t max)
{ /*returns the smallest number that is divisible by every number within the range [min, max]*/

	if (min == max)
	{
		return min * max;
	}

	uint64_t smallestMultiple = 0;
	bool isDivisible = false;

	while (!isDivisible)
	{
		smallestMultiple += max * (max - 1);
		for (int i = max; i > min - 1; i--)
		{
			if (smallestMultiple % i != 0)
			{
				break;
			}
			else if (i == min)
			{
				isDivisible = true;
				break;
			}
		}
		if (smallestMultiple == 0)
		{
			std::cout << "range too large" << std::endl;
			return 0;
		}
	}
	return smallestMultiple;
}

int main()
{	
	uint64_t maxNum;
	uint64_t minNum;
	std::cin >> minNum >> maxNum;
	std::cout << smallestMultipleOfRange(minNum, maxNum) << std::endl;
	return 0;
}