#include <stdio.h>
#include <stdlib.h>
#include "SharedLibraries.h"


/*
Function: FindLargestN
Input: long number, int k
Role: Calculates the binomial coefficent(n,k) up to 64 bits
*/
int FindLargestN(long number, int k)
{
	long highestValue = 0;
	int index = 1;
	while(highestValue <= number)
	{
		highestValue = NchooseK(index, k);
		index++;
	}
	return (index - 2);
}

/*
Function: BinaryToPostingsSequence
Input: int *binary, int binaryLength, int sequenceLength
Role: Converts a binary array into a Postings sequence array
*/
int *BinaryToPostingsSequence(int *binary, int binaryLength, int sequenceLength)
{
	int *result = calloc(sequenceLength, sizeof(int));
	int resultIndex = sequenceLength - 1;
	long number = 0;
	number = BinaryToLong(binary,binaryLength);
	int startN = FindLargestN(number,sequenceLength);
	while(number >= 0)
	{
		result[resultIndex] = startN;
		number -= (NchooseK(startN, sequenceLength));
		resultIndex--;
		sequenceLength--;
		startN = FindLargestN(number, sequenceLength);
	}
	return result;
}

int main()
{
	//Note this only works for 64 bit numbers
	int binary[] = {1,0,1,0};
	int binaryLength = sizeof(binary) / sizeof(int);
	int sequenceLength = 5;
	int *postings = BinaryToPostingsSequence(binary,binaryLength,sequenceLength);
	for(int i = 0; i < sequenceLength; i++)
	{
		printf("%d, ", postings[i]);
	}
	free(postings);
	return 0;
}
