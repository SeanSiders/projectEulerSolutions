#include <iostream>

uint64_t sumOfMultiples(uint64_t n)
{ /*return the sum of all the multiples of 3 or 5 below n*/

	uint64_t k = 0;

	for (uint64_t i = 3; i < n; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			k += i;
	}
	return k;
}

int main()
{	
	uint64_t maxNum;
	std::cin >> maxNum;
	std::cout << sumOfMultiples(maxNum) << std::endl;
	return 0;
}