# Postings
This repo is fully open source, licensed under a permissive [MIT License](https://opensource.org/licenses/MIT). You are welcome to explore the code and make 
contributions. At the moment, the library is written entirely in C and we encourage contributors who want to create bindings in their favorite languages.
\
# Quick Start
1. Download **4 files** binary.c binomial.c logs.c sharedLibraries.h from this [directory]().
2. In the same directory where you put your downloaded files, create a new file main.c
3. Initialize a Lookup Table for calculating logarithms, then you can start performing conversions.

```C
#include "sharedLibraries.h"
//gcc binary.c binomial.c logs.c main.c -lm -o main.o
int main()
{	
  //Create a lookup table to calculate logarithms
  int lookupSize = 16;
  double *logarithmLookupTable = GenerateLookupTable(lookupSize);
  
  //This is sample binary data
  int binaryExample[] = {1,0,1,0,1,0,1,0,1,0};
  int binaryExampleLength = sizeof(binaryExample) / sizeof(int);
  
  //Convert from Binary to Inverted Index list
  //Note, you need to know the length of your list
  int invertedListLength = 10;
  int *invertedIndexList = BinomialTransform(binaryExample, binaryExampleLength,logarithmLookupTable,lookupSize,invertedListLength);
  
  //Print your inverted index list
  for(int i = 0; i < invertedListLength; i++)
  {
    printf("%d ", invertedIndexList[i]);
  }
  //Free lookup table
  free(logarithmLookupTable);
  //Free inverted index list
  free(invertedIndexList);
}
