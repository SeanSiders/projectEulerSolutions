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

uint64_t primeIndex(uint64_t n)
{ /*returns the nth prime number counting up from 2*/

	uint64_t i = 1;
	uint64_t p = 0;

	while(i < n)
	{
		p += 2;
		if (p == 2)
		{
			p++;
			i++;
		}
		else if (isPrime(p))
		{
			i++;
		}	
	}
	return p;
}

int main()
{	
	uint64_t n;
	std::cin >> n;
	std::cout << primeIndex(n) << std::endl;
	return 0;
}