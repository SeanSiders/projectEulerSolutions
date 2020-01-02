#pragma once
#include <cmath>
#include <string>
#include <fstream>
#include <vector>

struct matrixDimensions2D
{
    uint64_t rows;
    uint64_t columns;
};

uint64_t digitToInt(char digit)
{
	return digit - '0';
}

bool isPrime(const uint64_t& x)
{/*if x is prime, return true*/

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

void printVector2D(std::vector< std::vector<uint64_t> > vector2D, matrixDimensions2D matrixDimensions)
{
    uint64_t u = matrixDimensions.columns;
    uint64_t v = matrixDimensions.rows;

    for (uint64_t i = 0; i < v; i++)
    {
        for (uint64_t k = 0; k < u; k++)
        {
            std::cout << vector2D[i][k] << " ";
        }
        std::cout << '\n';
    }
}

std::string parseFile(const std::string& filepath)
{
	std::ifstream fileStream(filepath);
	std::string str;

	str.assign((std::istreambuf_iterator<char>(fileStream)),
				(std::istreambuf_iterator<char>()) );
    
    return str;
}

uint64_t lastParsedNumber(const std::string& source, uint64_t& i, int64_t lastBlankIndex)
{
    uint64_t newNumber = 0;
    uint64_t exponent = 0;

    for (int64_t k = i - 1; k > lastBlankIndex; k--)
    {                
        newNumber += digitToInt(source[k]) * pow(10, exponent);
        exponent++;
    }

    return newNumber;
}

void getDimensionsOfMatrix(const std::string& source, matrixDimensions2D& matrixDimensions)
{
    uint64_t i = 0;
    uint64_t columnEntries = 1;
    uint64_t rowEntries = 1;

    while (i < source.length())
    {

        if (rowEntries == 1 && source[i] == ' ')
        {
            columnEntries++;
        }

        if (source[i] == '\n')
        {
            rowEntries++;
        }

        i++;
    }

    matrixDimensions = {columnEntries, rowEntries};
}

std::vector< std::vector<uint64_t> > populateVectorFromString(const std::string& source)
{
    matrixDimensions2D matrixDimensions;
    getDimensionsOfMatrix(source, matrixDimensions);

    uint64_t i = 0;
    int64_t lastBlankIndex = -1;
    
    std::vector< std::vector<uint64_t> > matrixVector(matrixDimensions.rows, std::vector<uint64_t>(matrixDimensions.columns));
    uint64_t row = 0;
    uint64_t column = 0; 
    
    while (i < source.length())
    {
        if (source[i] == ' ' || source[i] == '\n')
        {  
            matrixVector[row][column] = lastParsedNumber(source, i, lastBlankIndex);
            if (column == matrixDimensions.columns - 1)
            {
                column = 0;
            }
            else
            {
                column++;
            }

            if (source[i] == '\n')
            {
                row++;
            }

            lastBlankIndex = i;
        }

        i++;
    }
    
    if (!source[i])
    {
        matrixVector[row][column] = lastParsedNumber(source, i, lastBlankIndex);
    }

    return matrixVector;
}