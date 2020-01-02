#include <iostream>

uint64_t evenFibonacciSum(uint64_t n)
{ /*return the sum of all even numbers in the fibonacci sequence <= n*/

	uint64_t a = 0;
	uint64_t b = 1;
	uint64_t fNum = 0;
	uint64_t fibonacciSum = 0;
	while (fNum <= n)
	{
		fNum = a + b;
		a = b;
		b = fNum;
		
		if (fNum % 2 == 0)
			fibonacciSum += fNum;
	}
	return fibonacciSum;
}

int main()
{	
	uint64_t maxNum;
	std::cin >> maxNum;
	std::cout << evenFibonacciSum(maxNum) << std::endl;
	return 0;
}