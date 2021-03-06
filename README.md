# Postings
This repo contains code for converting between Binary and Postings(sequences of strictly increasing integers).
This repo is fully open source, licensed under a permissive [MIT License](https://opensource.org/licenses/MIT). You are welcome to explore the code and make 
contributions. At the moment, the library is written entirely in C and we encourage contributions from people who want to create bindings in their favorite languages.
\
# Quick Start
1. Download **3 files** GreedyBinaryToPostings.c SharedLibraries.c SharedLibraries.h from this [directory](https://github.com/PostingsCompress/Postings/tree/main/MathLibraries).
2. Create a new file main.c in the same directory as your downloads.
3. Add code for performing conversions like the example below

```C
//compile with gcc GreedyBinaryToPostings.c SharedLibraries.c main.c -o main.o && ./main.o
#include <stdio.h>
#include <stdlib.h>
#include "SharedLibraries.h"
int main()
{
	//Note this only works for max 64 bit signed longs
	int binary[] = {1,0,1,0};//Insert your binary array here
	int binaryLength = sizeof(binary) / sizeof(int);
	int sequenceLength = 5;//You always need to know the length of your postings
	int *postings = BinaryToPostingsSequence(binary,binaryLength,sequenceLength);
	for(int i = 0; i < sequenceLength; i++)
	{
		printf("%d, ", postings[i]);//Print your Postings
	}
	free(postings);//Free
	return 0;
}
```

