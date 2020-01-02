#include <iostream>

#include "lib.hpp"

uint64_t nextNonZeroProduct(std::string const& sequence, uint64_t scale, uint64_t& i)
{
	uint64_t product = 0;
	while (0 == product)
	{
		product = 1;
		for (uint64_t k = i - scale; k < i; k++)
		{
			product *= digitToInt(sequence[k]);
			if (0 == product)
			{
				i += i - k;
				break;
			}
		}
	}

	return product;
}
                         
uint64_t largestProductOfSequence(std::string const& sequence, uint64_t scale)
{	/*returns the largest product of a given range of numbers within a given sequence*/

	uint64_t product = 0;
	uint64_t largestProduct = 0;
	
	for (uint64_t i = scale; i <= sequence.length(); i++)
	{	
		if (0 == product)
		{
			product = nextNonZeroProduct(sequence, scale, i);
		}
		
		if (product > largestProduct && i <= sequence.length())
		{
			largestProduct = product;
		}

		uint64_t firstNum = digitToInt(sequence[i - scale]);
		uint64_t lastNum = digitToInt(sequence[i]);
		
		while (0 == lastNum)
		{
			i += scale;
			lastNum = digitToInt(sequence[i]);
			product = 0;
		}

		product /= firstNum;
		product *= lastNum;
	}

	return largestProduct;
}

int main()
{	
	uint64_t scale = 1;
	std::string sequence = "";

	while (scale > sequence.length())
	{
		std::cin >> sequence >> scale;
	}

	std::cout << largestProductOfSequence(sequence, scale) << std::endl;
	return 0;
}