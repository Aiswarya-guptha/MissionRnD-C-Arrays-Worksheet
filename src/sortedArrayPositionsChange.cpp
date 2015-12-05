/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL)
		//if arr is NULL
		return NULL;
	int iter = 0;
	while (Arr[iter] >= 0)
		//count no of values in it
		iter++;
	if (iter != (len))
		//if length is not equal to no. of values return invalid
		return NULL;
	int first= 0, last=(len-1),j,temp;
	//quick sort method
	for (; first<last; first++){
		j = last;
		while (Arr[j] > Arr[first])
			j--;
		if (j != first){
			//found swapped positions
			temp = Arr[first];
			Arr[first] = Arr[j];
			Arr[j] = temp;
			return Arr;
		}

	}
}