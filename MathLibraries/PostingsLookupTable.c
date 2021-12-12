#include <stdio.h>
#include <stdlib.h>
#include "SharedLibraries.h"

/*
File Name: PostingsLookupTable.c
Role: Creates one lookup table for finding out the combination represented by a number N
Note: NchooseK is called once, then a for loop is used to create the entire table 
*/


/*
Function: CopyArray
Input: int *source, int *destination, int length
Role: Copies source array to the destination
Note: This is where the conversion happens
*/
void CopyArray(int *source, int *destination, int length)
{
	int start = 0;
	for(int i = length-1 ; i >= 0; i--)
	{
		destination[start] = source[i] + start;
		start++;
	}
}

//This algorithm is discussed in the Docs under technical details
//eg 0000 = 1000, 2222 = 3000long NchooseK(int n, int k)
/*
Function: GenerateLookupTable
Input: int *source, int *destination, int length
Role: Copies source array to the destination
Note: This is where the conversion happens
*/
int **GenerateLookupTable(int maxValue,int arrayLength)
{
	long max = NchooseK(maxValue + arrayLength, arrayLength);
	int *current  = calloc(arrayLength, sizeof(int));
	int **result = malloc(max * sizeof(int*));
	for(long i = 0; i < max; i++)
	{
		result[i] = malloc(arrayLength * sizeof(int));
		//printf("%ld: ", i);
		CopyArray(current,result[i],arrayLength);
		//PrintArray(current,arrayLength);
		for(int j = arrayLength-1 ; j > 0; j--)
		{
			if(current[0] == current[arrayLength-1])
			{
				current[0] += 1;
				for(int j = 1; j < arrayLength; j++)
				{
					current[j] = 0;
				}
				break;
			}
			if(current[j] == current[j - 1])
			{}
			else if(current[j] != current[j - 1])
			{
				current[j] += 1;
				for(int k = j+1; k < arrayLength; k++)
				{
					current[k] = 0;
				}
				break;
			}
		}
	}
	free(current);
	return result;
}

void DestroyPostings(int **postingsTable, long dataCount)
{
	for(long i = 0; i < dataCount; i++)
	{
		free(postingsTable[i]);
	}
	free(postingsTable);
}

//How to use sample
/*
int main()
{
	//Note maxvalue is the expected size of n for n choose k
	int maxValue = 2;
	int sequenceLength = 4;
	long dataCount = NchooseK(maxValue + sequenceLength, sequenceLength);
	int **postingsTable = GenerateLookupTable(maxValue,sequenceLength);
	for(int i = 0; i < dataCount; i++)
	{
		printf("%d: ",i);
		PrintArray(postingsTable[i], sequenceLength);
	}
	DestroyPostings(postingsTable, dataCount);
	return 0;
}*/
