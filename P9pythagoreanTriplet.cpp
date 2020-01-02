#include <iostream>

uint64_t pythagoreanTriplet(uint64_t n)
{
	/*A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

	a2 + b2 = c2
	For example, 32 + 42 = 9 + 16 = 25 = 52.

	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.*/

	// for all values 5 <= c < square root of n
		// all values 4 <= b < c
			// all values 3 <= a < b
	
	for (uint64_t c = n - 25; c > 0; c--)
	{
		uint64_t b = 2;
		uint64_t a = 1;
		while(a + b + c < n)
		{
			for (b = 2; b < n - c; b++)
			{
				for (a = 1; a < b; a++)
				{
					if (a * a + b * b == c * c && a + b + c == n)
					{
						return a * b * c;
					}
				}
			}
		}
	}
	return 0;
}

int main()
{	
	uint64_t n;
	std::cin >> n;
	
	std::cout << pythagoreanTriplet(n) << std::endl;
	return 0;
}