#include <iostream>
#include <cstdio>
#include "binarySearch.cpp"

using namespace std;

int readInputs(int **adr, int *adrNum);

int main()
{
	printf
	(
		"\n\nHi this is a Sample usage of interval binary search.\n\n\
 Tip : you must enter array numbers in increasing order.\n\n\n"
	);
	while(1 == 1)
	{
		int **adr;
		int adrNum;
		int element = readInputs(&*adr, &adrNum);
		int result = binarySearch(element, *adr, 0, adrNum-1);
		if(result == 0)
			printf("\nOppps, not Found\n\n");
		else
			printf("\nwanted element is between indexes %d and %d\n\n", result-1, result);
		printf("Do you want to continue the survey (y | n): ");
		char next;
		scanf("%s", &next);
		printf("\n");
		if(next != 'y')
			break;
	}
}

int readInputs(int **adr, int *adrNum)
{
	int sizee;
	printf("Please enter size of wanted array of numbers you want to enter : ");
	scanf("%d", &sizee);
	printf("\n");
	sizee++;
	int arr[sizee];
	sizee--;
	arr[sizee] = 99999999;
	*adrNum = sizee;
	*adr = arr;
	for(int i = 0; i < sizee; i++)
	{
		printf("Please Enter index number %d : ", i);
		scanf("%d", &arr[i]);
	}
	printf("\nNow please Enter the element you are trying to find : ");
	int element;
	scanf("%d", &element);
	printf("\n");
	return element;
}

