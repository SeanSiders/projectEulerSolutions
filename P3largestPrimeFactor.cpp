#include <iostream>
#include <cmath>

bool isPrime(uint64_t x)
{ /*if x is prime, return true*/

	if (x == 2)
	{
		return true;
	}
	else if (x % 2 == 0)
	{
		return false;
	}
	else
	{
		for(uint64_t i = 3; i <= sqrt(x); i += 2)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

uint64_t largestPrimeFactor(uint64_t n)
{ /*return the largest prime factor of n*/

	while (n % 2 == 0 && n != 2)
	{
	n /= 2;
	}

	uint64_t root = sqrt(n);
	for (uint64_t i = 3; i <= root; i += 2)
	{	
		while (n % i == 0 && isPrime(i) && n != i)
		{
			n /= i;
		}
	}
	return n;
}

int main()
{	
	uint64_t maxNum;
	std::cin >> maxNum;
	std::cout << largestPrimeFactor(maxNum) << std::endl;
	return 0;
}