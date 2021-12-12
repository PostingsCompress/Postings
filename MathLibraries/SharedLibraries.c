#include <stdio.h>
#include <stdlib.h>
#include "SharedLibraries.h"

/*
Function: BinaryToLong
Input: int *binary, int binaryLength
Role: Converts an array of binary digits to a long value
Note: Left-most bit is most significant
*/

long BinaryToLong(int *binary, int binaryLength)
{
	long result = 0;
	int j = binaryLength - 1;
	for(int i = 0; i < binaryLength; i++)
	{
		result += (binary[j] * (1 << i));
		j--;
	}
	return result;
}

/*
Function: NchooseK
Input: int n, int k
Role: Calculates the binomial coefficent(n,k) up to 64 bits
*/
long NchooseK(int n, int k)
{
	long result = 1;
	if(n < k)
	{
		return 0;
	}
	if(n == k)
	{
		return 1;
	}
	if(k > n-k)
	{
		k = n - k;
	}
	for(int i = 0; i < k; i++)
	{
		result *= (n - i);
		result /= (i + 1);
	}
	return result;
}

/*
Function: PrintArray
Input: int array[], int length
Role: Prints an array of ints
*/
void PrintArray(int array[], int length)
{
	for(int i = 0 ; i < length; i++)
	{
		printf("%d,", array[i]);
	}
	putchar('\n');
}

