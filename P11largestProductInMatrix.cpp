#include <iostream>
#include "lib.hpp"

matrixDimensions2D matrixDimensions;

std::vector< std::vector<uint64_t> > transposeMatrix(std::vector< std::vector<uint64_t> >& matrix)
{
	std::vector< std::vector<uint64_t> > transposedMatrix(matrixDimensions.columns, std::vector<uint64_t>(matrixDimensions.rows));

	for (uint64_t u = 0; u < matrixDimensions.columns; u++)
	{
		for (uint64_t v = 0; v < matrixDimensions.rows; v++)
		{
			transposedMatrix[v][u] = matrix[u][v];
		}
	}
	return transposedMatrix;
}

uint64_t largestProductOfMatrixDiagonals(std::vector< std::vector<uint64_t> >& matrix, const uint64_t& scale)
{
	uint64_t product;
	uint64_t largestProduct = 0;
	uint64_t diagonalScale = scale;

	while (diagonalScale <= matrixDimensions.rows)
	{
		uint64_t v = matrixDimensions.rows - diagonalScale;
		uint64_t u = 0;

		for (uint64_t i = 0; i <= diagonalScale - scale; i++)
		{
			product = 1;
			for (uint64_t k = i; k < i + scale; k++)
			{
				product *= matrix[v + k][u + k];
			}

			if (product > largestProduct)
			{
				largestProduct = product;
			}
		}
		
		diagonalScale++;
	}

	diagonalScale = scale;
	
	while (diagonalScale < matrixDimensions.columns)
	{
		uint64_t u = matrixDimensions.columns - diagonalScale;
		uint64_t v = 0;

		for (uint64_t i = 0; i <= diagonalScale - scale; i++)
		{
			product = 1;
			for (uint64_t k = i; k < i + scale; k++)
			{
				product *= matrix[v + k][u + k];
			}

			if (product > largestProduct)
			{
				largestProduct = product;
			}
		}
		
		diagonalScale++;
	}

	diagonalScale = scale;

	while (diagonalScale <= matrixDimensions.rows)
	{
		uint64_t v = matrixDimensions.rows - diagonalScale;
		uint64_t u = matrixDimensions.columns - 1;

		for (uint64_t i = 0; i <= diagonalScale - scale; i++)
		{
			product = 1;
			for (uint64_t k = i; k < i + scale; k++)
			{
				product *= matrix[v + k][u - k];
			}

			if (product > largestProduct)
			{
				largestProduct = product;
			}
		}

		diagonalScale++;
	}

	diagonalScale = scale;
	
	while (diagonalScale < matrixDimensions.columns)
	{
		uint64_t u = diagonalScale - 1;
		uint64_t v = 0;

		for (uint64_t i = 0; i <= diagonalScale - scale; i++)
		{
			product = 1;
			for (uint64_t k = i; k < i + scale; k++)
			{
				product *= matrix[v + k][u - k];
			}

			if (product > largestProduct)
			{
				largestProduct = product;
			}
		}
	
		diagonalScale++;
	}
	
	return largestProduct;
}

uint64_t nextNonZeroProduct(std::vector<uint64_t> sequence, const uint64_t& scale, uint64_t& i)
{
	uint64_t product = 0;
	while (0 == product && i < sequence.size())
	{
		product = 1;
		
		for (uint64_t k = i - scale; k <= i; k++)
		{
			product *= sequence[k];
			if (0 == product)
			{
				i += i - k;
				break;
			}
		}	
	}

	return product;
}

uint64_t largestHorizontalProductInMatrix(std::vector< std::vector<uint64_t> >& matrix, const uint64_t& scale)
{
	uint64_t product;
	uint64_t largestProduct = 0;

	for (uint64_t v = 0; v < matrixDimensions.rows; v++)
	{
		for (uint64_t u = 0; u < matrixDimensions.columns - scale; u++)
		{
			product = 1;
			for (uint64_t i = 0; i < scale; i++)
			{
				product *= matrix[v][u + i];

				if (0 == product)
				{
					break;
				}
			}
			
			if (product > largestProduct)
			{
				largestProduct = product;
			}
		}
	}

	return largestProduct;
}

int main()
{	
	const std::string& source = parseFile("numMatrix20x20");
	std::vector <std::vector<uint64_t> > matrix = populateVectorFromString(source);
	getDimensionsOfMatrix(source, matrixDimensions);

	uint64_t uProduct = largestHorizontalProductInMatrix(matrix, 4);
	uint64_t largestProduct = uProduct;

	std::vector< std::vector<uint64_t> > matrixTransposed = transposeMatrix(matrix);
	uint64_t vProduct = largestHorizontalProductInMatrix(matrixTransposed, 4);

	if (vProduct > largestProduct)
	{
		largestProduct = vProduct;
	}

	uint64_t diagonals = largestProductOfMatrixDiagonals(matrix, 4);

	if (diagonals > largestProduct)
	{
		largestProduct = diagonals;
	}

	std::cout << largestProduct << "\n";

	return 0;
}