#include <iostream>
#include <cmath>

uint64_t largestPalindrome(uint64_t n)
{ /*return the largest palindrome that is the product of two numbers with n digits*/

	uint64_t largestP = 0;
	uint64_t top = pow(10, n) - 1;
	uint64_t bottom = pow(10, (n - 1)) - 1;

	for (uint64_t i = top; i > bottom; i--)
	{
		for (uint64_t k = i; k > bottom; k--)
		{
			uint64_t p = k * i;
			uint64_t p2 = p;
			uint64_t revP = 0;

			for (int c = 0; c < n * 2; c++)
			{
				revP *= 10;
				if (p2 < 10)
				{
					revP += p2;
				}
				else
				{
					revP += p2 % 10;
				}
				p2 /= 10;
			}
			if (revP == p && p > largestP)
			{
				largestP = p;
			}
		}
	}
	return largestP;
}

int main()
{	
	uint64_t maxNum;
	std::cin >> maxNum;
	std::cout << largestPalindrome(maxNum) << std::endl;
	return 0;
}