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


uint64_t sumOfPrimes(uint64_t n)
{ /*returns the sum of all primes that are less than n*/
	uint64_t sum = 2;
	uint64_t c = 3;
	while (c < n)
	{
		if (isPrime(c))
		{
			sum += c;
		}
		c += 2;
	}
	return sum;
}

int main()
{	
	uint64_t n;
	std::cin >> n;

	std::cout << sumOfPrimes(n) << std::endl;
	return 0;
}