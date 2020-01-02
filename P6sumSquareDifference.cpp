#include <iostream>

uint64_t sumSquareDifference(uint64_t n)
{ /*returns the difference between the sum of the squares of the first n natural numbers and the square of the sum.*/

	uint64_t sumSquares = 0;
	uint64_t squareSum = 0;

	for (int i = 1; i <= n; i++)
	{
		sumSquares += i * i;
		squareSum += i;
	}
	return (squareSum * squareSum) - sumSquares;
}

int main()
{	
	uint64_t n;
	std::cin >> n;
	std::cout << sumSquareDifference(n) << std::endl;
	return 0;
}